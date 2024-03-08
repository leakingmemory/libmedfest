//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_XMLELEMENT_H
#define LEGEMFEST_XMLELEMENT_H

#include <Fest/XMLObject.h>
#include "XmlContentElement.h"
#include "XmlValueWithDistinguishedName.h"
#include "FestIdObject.h"
#include "XmlKode.h"
#include "XmlBeskrivelseTerm.h"
#include <Struct/Decoded/Sprak.h>
#include <Struct/Decoded/Term.h>
#include <memory>
#include <map>

class XmlOppfKodeverk;

class XmlElement : public XMLObject, public FestIdObject, public XmlKode {
private:
    std::shared_ptr<XmlOppfKodeverk> parent;
    Term term{};
public:
    XmlElement(std::shared_ptr<XmlOppfKodeverk> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetTerm(const Term &term);
    bool Merge();
};

class XmlTerm : public XMLObject, public XmlBeskrivelseTerm {
private:
    std::shared_ptr<XmlElement> parent;
    std::string term{};
    Sprak sprak{};
public:
    XmlTerm(std::shared_ptr<XmlElement> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetTerm(const std::string &term);
    void SetSprak(const Sprak &sprak);
    bool Merge();
};

class XmlElementHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlTermHandler : private XmlContentElementHandler<XmlTerm> {
public:
    XmlTermHandler() : XmlContentElementHandler<XmlTerm>("Term") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlTerm> parent, const std::string &content) override;
};

class XmlSprakHandler : public XmlValueWithDistinguishedNameHandler<XmlTerm> {
public:
    XmlSprakHandler() : XmlValueWithDistinguishedNameHandler<XmlTerm>("Sprak") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLELEMENT_H
