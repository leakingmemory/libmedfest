//
// Created by jeo on 12/8/22.
//

#include "XMLParser.h"
#include <iostream>
#include <cstring>

XMLParser::XMLParser() {
    parser = XML_ParserCreate(NULL);
}

XMLParser::~XMLParser() {
    XML_ParserFree(parser);
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

    if (XML_ParseBuffer(parser, len, lastBuffer)) {
        std::cerr << "Expat: Parse error\n";
        return false;
    }

    return true;
}