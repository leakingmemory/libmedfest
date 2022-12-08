//
// Created by jeo on 12/8/22.
//

#include "XMLParser.h"
#include <iostream>
#include <cstring>
#include <boost/algorithm/string.hpp>

static void XMLCALL
startElement(void *userData, const XML_Char *in_name, const XML_Char **in_atts) {
    auto *stream = (XMLParser *) userData;
    std::string name{in_name};
    std::vector<NameValue> attributes{};
    while (*in_atts != NULL) {
        auto &attribute = attributes.emplace_back();
        attribute.name.append(*in_atts);
        ++in_atts;
        attribute.value.append(*in_atts);
        ++in_atts;
    }
    stream->StartElement(name, attributes);
}

static void XMLCALL
endElement(void *userData, const XML_Char *in_name) {
    auto *stream = (XMLParser *) userData;
    std::string name{in_name};
    stream->EndElement(name);
}

static void XMLCALL
characterData(void *userData,
              const XML_Char *s, int len) {
    auto *stream = (XMLParser *) userData;
    std::string charData{};
    charData.append(s, len);
    stream->CharacterData(charData);
}

XMLParser::XMLParser() : handlers(), trail(), stop(false){
    parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser, this);
    XML_SetElementHandler(parser, startElement, endElement);
    XML_SetCharacterDataHandler(parser, characterData);
}

XMLParser::~XMLParser() {
    XML_ParserFree(parser);
}

std::shared_ptr<XMLObjectHandlerInterface> XMLParser::GetHandler(const std::string &name) {
    auto iterator = handlers.find(name);
    if (iterator == handlers.end()) {
        std::cerr << "Error: Unhandled item " << name << "\n";
        auto iter = trail.end();
        while (iter != trail.begin()) {
            --iter;
            std::cerr << " * in: " << (*iter)->GetName() << "\n";
        }
        stop = true;
        return {};
    }
    return iterator->second;
}

void XMLParser::StartElement(const std::string &name, const std::vector<NameValue> &attributes) {
    if (stop) {
        return;
    }
    auto handler = GetHandler(name);
    if (!handler) {
        std::cerr << "Attributes:\n";
        for (auto attr : attributes) {
            std::cerr << " * " << attr.name << "=" << attr.value << "\n";
        }
        return;
    }
    std::shared_ptr<XMLObject> parent{};
    {
        auto iterator = trail.end();
        if (iterator != trail.begin()) {
            --iterator;
            parent = *iterator;
        }
    }
    auto obj = handler->StartElement(parent, attributes);
    trail.push_back(obj);
}

void XMLParser::EndElement(const std::string &name) {
    if (stop) {
        return;
    }
    auto handler = GetHandler(name);
    if (!handler) {
        std::cerr << "Error: Handler not found for end of " << name << "\n";
        return;
    }
    std::shared_ptr<XMLObject> obj{};
    {
        auto iterator = trail.end();
        if (iterator != trail.begin()) {
            --iterator;
            obj = *iterator;
            trail.pop_back();
        }
    }
    if (!obj) {
        std::cerr << "Error: Unexpected end of: " << name << "\n";
        stop = true;
        return;
    }
    if (obj->GetName() != name) {
        std::cerr << "Error: Expected end of " << obj->GetName() << ", but found end of " << name << "\n";
        stop = true;
        return;
    }
    if (!handler->EndElement(obj)) {
        std::cerr << "Error: Handler for " << name << " rejected the element at the end\n";
        stop = true;
        return;
    }
    if (trail.empty()) {
        roots.push_back(obj);
    }
}

void XMLParser::CharacterData(const std::string &charData) {
    if (stop) {
        return;
    }
    std::shared_ptr<XMLObject> obj{};
    {
        auto iterator = trail.end();
        if (iterator != trail.begin()) {
            --iterator;
            obj = *iterator;
        }
    }
    if (!obj->AppendCharacterData(charData)) {
        std::string trimstr{charData};
        boost::trim(trimstr);
        if (!trimstr.empty()) {
            std::cerr << "Element " << obj->GetName() << " did not accept character data: " << charData << "\n";
            stop = true;
        }
    }
}

bool XMLParser::ParseBuffer(const void *buf, int len, bool lastBuffer) {
    if (len > 0) {
        void *const exbuf = XML_GetBuffer(parser, len);
        if (!buf) {
            std::cerr << "Expat: Couldn't allocate memory for buffer\n";
            return false;
        }
        memcpy(exbuf, buf, len);
    } else if (len < 0) {
        std::cerr << "XML Parser: Invalid len<0 call\n";
        return false;
    }

    if (XML_ParseBuffer(parser, len, lastBuffer) == XML_Status::XML_STATUS_ERROR) {
        std::cerr << "Expat: Parse error at " << XML_GetCurrentLineNumber(parser) << ": " << XML_ErrorString(XML_GetErrorCode(parser)) << "\n";
        return false;
    }

    if (stop) {
        std::cerr << "Stop!: Errors\n";
        return false;
    }

    return true;
}