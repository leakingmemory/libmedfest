//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPAKNINGSKOMPONENT_H
#define LEGEMFEST_XMLPAKNINGSKOMPONENT_H

#include "XMLObject.h"
#include "XmlPakningsinfo.h"

class XmlPakningskomponent : public XMLObject {
private:
    std::shared_ptr<XmlPakningsinfoObject> parent;
public:
    XmlPakningskomponent(std::shared_ptr<XmlPakningsinfoObject> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Merge();
};

class XmlPakningskomponentHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLPAKNINGSKOMPONENT_H
