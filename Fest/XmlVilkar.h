//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_XMLVILKAR_H
#define LEGEMFEST_XMLVILKAR_H

#include <Fest/XMLObject.h>
#include "XmlContentElement.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlValueWithCodeSet.h"
#include "FestIdObject.h"
#include "XmlGyldigFraDato.h"
#include "XmlType.h"
#include <Struct/Decoded/Gruppe.h>
#include <Struct/Decoded/GjelderFor.h>
#include <Struct/Decoded/StrukturertVilkar.h>
#include <memory>
#include <map>

class XmlOppfVilkar;

class XmlVilkar : public XMLObject, public FestIdObject, public XmlGyldigFraDato {
private:
    std::shared_ptr<XmlOppfVilkar> parent;
    std::string vilkarNr{};
    Gruppe gruppe{};
    GjelderFor gjelderFor{};
    std::string tekst{};
    StrukturertVilkar strukturertVilkar{};
public:
    XmlVilkar(std::shared_ptr<XmlOppfVilkar> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetVilkarNr(const std::string &vilkarNr);
    void SetGruppe(const Gruppe &gruppe);
    void SetGjelderFor(const GjelderFor &gjelderFor);
    void SetTekst(const std::string &tekst);
    void SetStrukturertVilkar(const StrukturertVilkar &strukturertVilkar);
    bool Merge();
};

class XmlStrukturertVilkar : public XMLObject, public XmlTypeObject {
private:
    std::shared_ptr<XmlVilkar> parent;
    ValueWithCodeSet verdiKodet{};
    std::string verdiTekst{};
public:
    XmlStrukturertVilkar(std::shared_ptr<XmlVilkar> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetVerdiKodet(const ValueWithCodeSet &verdiKodet);
    void SetVerdiTekst(const std::string &verdiTekst);
    bool Merge();
};

class XmlVilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlVilkarNrHandler : public XmlContentElementHandler<XmlVilkar> {
public:
    XmlVilkarNrHandler() : XmlContentElementHandler<XmlVilkar>("VilkarNr") {}
    bool Merge(std::shared_ptr<XmlVilkar> parent, const std::string &content) override;
};

class XmlGruppeHandler : public XmlValueWithCodeSetHandler<XmlVilkar> {
public:
    XmlGruppeHandler() : XmlValueWithCodeSetHandler<XmlVilkar>("Gruppe") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVilkar>> obj) override;
};

class XmlGjelderForHandler : public XmlValueWithDistinguishedNameHandler<XmlVilkar> {
public:
    XmlGjelderForHandler() : XmlValueWithDistinguishedNameHandler<XmlVilkar>("GjelderFor") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlTekstHandler : public XmlContentElementHandler<XmlVilkar> {
public:
    XmlTekstHandler() : XmlContentElementHandler<XmlVilkar>("Tekst") {}
    bool Merge(std::shared_ptr<XmlVilkar> parent, const std::string &content) override;
};

class XmlStrukturertVilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlVerdiKodetHandler : public XmlValueWithCodeSetHandler<XmlStrukturertVilkar> {
public:
    XmlVerdiKodetHandler() : XmlValueWithCodeSetHandler<XmlStrukturertVilkar>("VerdiKodet") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlStrukturertVilkar>> obj) override;
};

class XmlVerdiTekstHandler : public XmlContentElementHandler<XmlStrukturertVilkar> {
public:
    XmlVerdiTekstHandler() : XmlContentElementHandler<XmlStrukturertVilkar>("VerdiTekst") {}
    bool Merge(std::shared_ptr<XmlStrukturertVilkar> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLVILKAR_H
