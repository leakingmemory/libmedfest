//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_XMLPARSER_H
#define LEGEMFEST_XMLPARSER_H

#include <expat.h>
#include <vector>
#include <string>

class XMLParser {
private:
    XML_Parser parser;
public:
    XMLParser();
    ~XMLParser();
    XMLParser(const XMLParser &) = delete;
    XMLParser(XMLParser &&) = delete;
    XMLParser &operator = (const XMLParser &) = delete;
    XMLParser &operator = (XMLParser &&) = delete;

    void StartElement(const std::string &name, const std::vector<std::string> &attributes);
    void EndElement(const std::string &name);

    bool ParseBuffer(const void *buf, int len, bool lastBuffer);
};


#endif //LEGEMFEST_XMLPARSER_H
