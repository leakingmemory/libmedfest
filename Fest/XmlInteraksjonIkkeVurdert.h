//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLINTERAKSJONIKKEVURDERT_H
#define LEGEMFEST_XMLINTERAKSJONIKKEVURDERT_H

#include <Fest/XMLObject.h>
#include "XmlAtc.h"
#include <memory>
#include <map>

class XmlOppfInteraksjon;

class XmlInteraksjonIkkeVurdert : public XMLObject, public XmlAtc {
private:
    std::shared_ptr<XmlOppfInteraksjon> parent;
public:
    XmlInteraksjonIkkeVurdert(std::shared_ptr<XmlOppfInteraksjon> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Merge();
};

class XmlInteraksjonIkkeVurdertHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLINTERAKSJONIKKEVURDERT_H
