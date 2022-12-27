//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_XMLVARSELSLV_H
#define LEGEMFEST_XMLVARSELSLV_H

#include "XMLObject.h"
#include "XmlType.h"
#include "XmlContentElement.h"
#include "XmlValueWithCodeSet.h"
#include "XmlFraDato.h"
#include "XmlLenke.h"
#include "XmlReferanseelement.h"
#include "../Struct/Decoded/Visningsregel.h"
#include <memory>
#include <map>
#include <vector>

class XmlOppfVarselSlv;

class XmlVarselSlv : public XMLObject, public XmlTypeObject, public XmlFraDato, public XmlLenke,
                     public XmlReferanseelement {
private:
    std::shared_ptr<XmlOppfVarselSlv> parent;
    std::string overskrift{};
    std::string varseltekst{};
    std::vector<Visningsregel> visningsregel{};
public:
    XmlVarselSlv(std::shared_ptr<XmlOppfVarselSlv> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetOverskrift(const std::string &overskrift);
    void SetVarseltekst(const std::string &varseltekst);
    void AddVisningsregel(const Visningsregel &visningsregel);
    bool Merge();
};

class XmlVarselSlvHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOverskriftHandler : public XmlContentElementHandler<XmlVarselSlv> {
public:
    XmlOverskriftHandler() : XmlContentElementHandler<XmlVarselSlv>("Overskrift") {}
    bool Merge(std::shared_ptr<XmlVarselSlv> parent, const std::string &content) override;
};

class XmlVarseltekstHandler : public XmlContentElementHandler<XmlVarselSlv> {
public:
    XmlVarseltekstHandler() : XmlContentElementHandler<XmlVarselSlv>("Varseltekst") {}
    bool Merge(std::shared_ptr<XmlVarselSlv> parent, const std::string &content) override;
};

class XmlVisningsregelHandler : public XmlValueWithCodeSetHandler<XmlVarselSlv> {
public:
    XmlVisningsregelHandler() : XmlValueWithCodeSetHandler<XmlVarselSlv>("Visningsregel") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVarselSlv>> obj) override;
};

#endif //LEGEMFEST_XMLVARSELSLV_H
