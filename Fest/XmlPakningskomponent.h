//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPAKNINGSKOMPONENT_H
#define LEGEMFEST_XMLPAKNINGSKOMPONENT_H

#include <Fest/XMLObject.h>
#include "XmlPakningsinfo.h"
#include "XmlMengde.h"
#include <Struct/Decoded/PakningskomponentInfo.h>

class XmlPakningskomponentInfo {
public:
    virtual bool Merge(const PakningskomponentInfo &pakningskomponentInfo) = 0;
};

class XmlPakningskomponentInfoObject : public XMLObject, public XmlPakningstype, public XmlMengde {
private:
    std::shared_ptr<XmlPakningskomponentInfo> parentRef;
    XmlPakningskomponentInfo &parent;
    ValueUnit mengde{};
public:
    XmlPakningskomponentInfoObject(std::shared_ptr<XmlPakningskomponentInfo> parentRef) :
        parentRef(parentRef), parent(*parentRef) {}
protected:
    XmlPakningskomponentInfoObject(XmlPakningskomponentInfo &parent) : parentRef(), parent(parent) {}
public:
    std::string GetName() const override;
    bool Mengde(const ValueUnit &mengde) override;
    bool Merge();
};

class XmlPakningskomponent : public XmlPakningskomponentInfo, public XmlPakningskomponentInfoObject, public XmlAntall {
private:
    std::shared_ptr<XmlPakningsinfoObject> parent;
public:
    XmlPakningskomponent(std::shared_ptr<XmlPakningsinfoObject> parent) : XmlPakningskomponentInfoObject(static_cast<XmlPakningskomponentInfo &>(*this)), parent(parent) {}
    bool Merge(const PakningskomponentInfo &) override;
};

class XmlPakningskomponentHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLPAKNINGSKOMPONENT_H
