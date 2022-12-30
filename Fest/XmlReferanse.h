//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLREFERANSE_H
#define LEGEMFEST_XMLREFERANSE_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include "XmlLenke.h"
#include <memory>
#include <map>

class XmlInteraksjon;

class XmlReferanse : public XMLObject, public XmlLenkeValue {
private:
    std::shared_ptr<XmlInteraksjon> parent;
    std::string kilde{};
public:
    XmlReferanse(std::shared_ptr<XmlInteraksjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetKilde(const std::string &kilde);
    bool Merge();
};

class XmlReferanseHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlKildeHandler : public XmlContentElementHandler<XmlReferanse> {
public:
    XmlKildeHandler() : XmlContentElementHandler<XmlReferanse>("Kilde") {}
    bool Merge(std::shared_ptr<XmlReferanse> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFERANSE_H
