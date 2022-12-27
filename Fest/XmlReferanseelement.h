//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_XMLREFERANSEELEMENT_H
#define LEGEMFEST_XMLREFERANSEELEMENT_H

#include "XMLObject.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlContentElement.h"
#include "../Struct/Decoded/Referanseelement.h"
#include <memory>
#include <map>

class XmlReferanseelement {
private:
    Referanseelement referanseelement{};
public:
    ~XmlReferanseelement() = default;
    void SetReferanseelement(const Referanseelement &referanseelement);
    [[nodiscard]] Referanseelement GetReferanseelement() const;
};

class XmlReferanseelementObject : public XMLObject {
private:
    std::shared_ptr<XmlReferanseelement> parent;
    Klasse klasse{};
    std::vector<std::string> refs{};
public:
    XmlReferanseelementObject(const std::shared_ptr<XmlReferanseelement> &parent) : parent(parent) {}
    std::string GetName() const override;
    void SetKlasse(const Klasse &klasse);
    void AddRef(const std::string &ref);
    bool Merge();
};

class XmlReferanseelementHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlKlasseHandler : public XmlValueWithDistinguishedNameHandler<XmlReferanseelementObject> {
public:
    XmlKlasseHandler() : XmlValueWithDistinguishedNameHandler<XmlReferanseelementObject>("Klasse") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlRefElementHandler : public XmlContentElementHandler<XmlReferanseelementObject> {
public:
    XmlRefElementHandler() : XmlContentElementHandler<XmlReferanseelementObject>("RefElement") {}
    bool Merge(std::shared_ptr<XmlReferanseelementObject> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFERANSEELEMENT_H
