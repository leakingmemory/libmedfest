//
// Created by jeo on 12/8/22.
//

#include "XMLParser.h"
#include <iostream>
#include <cstring>

static void XMLCALL
startElement(void *userData, const XML_Char *in_name, const XML_Char **in_atts) {
    auto *stream = (XMLParser *) userData;
    std::string name{in_name};
    std::vector<std::string> attributes{};
    while (*in_atts != NULL) {
        std::string &attribute = attributes.emplace_back();
        attribute.append(*in_atts);
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

XMLParser::XMLParser() {
    parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser, this);
    XML_SetElementHandler(parser, startElement, endElement);
}

XMLParser::~XMLParser() {
    XML_ParserFree(parser);
}

void XMLParser::StartElement(const std::string &name, const std::vector<std::string> &attributes) {
    std::cout << "Start: " << name;
    for (auto attr : attributes) {
        std::cout << ", " << attr;
    }
    std::cout << "\n";
}

void XMLParser::EndElement(const std::string &name) {
    std::cout << "End: " << name << "\n";
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

    return true;
}