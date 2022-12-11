//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELCORE_H
#define LEGEMFEST_XMLLEGEMIDDELCORE_H


#include "../Struct/Decoded/Atc.h"
#include "../Struct/Decoded/Reseptgruppe.h"
#include "XMLObject.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/LegemiddelformKort.h"
#include "XmlContentElement.h"
#include "../Struct/Decoded/TypeSoknadSlv.h"
#include "../Struct/Decoded/AdministreringLegemiddel.h"
#include "../Struct/Decoded/MaybeBoolean.h"
#include "../Struct/Decoded/SvartTrekant.h"
#include "XmlSortertVirkestoffMedStyrke.h"
#include <memory>
#include <map>
#include <vector>

class XmlLegemiddelCore {
private:
    Atc atc{};
    std::string navnFormStyrke{};
    Reseptgruppe reseptgruppe{};
    LegemiddelformKort legemiddelformKort{};
    std::vector<std::string> refVilkar{};
    TypeSoknadSlv typeSoknadSlv{};
    MaybeBoolean opioidsoknad{MaybeBoolean::UNSPECIFIED};
    SvartTrekant svartTrekant{};
public:
    virtual ~XmlLegemiddelCore() = default;
    [[nodiscard]] Atc GetAtc() const;
    void SetAtc(const Atc &);
    [[nodiscard]] std::string GetNavnFormStyrke();
    void SetNavnFormStyrke(const std::string &navnFormStyrke);
    [[nodiscard]] Reseptgruppe GetReseptgruppe();
    void SetReseptgruppe(const Reseptgruppe &reseptgruppe);
    [[nodiscard]] LegemiddelformKort GetLegemiddelformKort() const;
    void SetLegemiddelformKort(const LegemiddelformKort &legemiddelformKort);
    [[nodiscard]] std::vector<std::string> GetRefVilkar() const;
    void AddRefVilkar(const std::string &refVilkar);
    [[nodiscard]] TypeSoknadSlv GetTypeSoknadSlv() const;
    void SetTypeSoknadSlv(const TypeSoknadSlv &typeSoknadSlv);
    [[nodiscard]] MaybeBoolean GetOpioidsoknad() const;
    void SetOpioidsoknad(bool opioidsoknad);
    [[nodiscard]] SvartTrekant GetSvartTrekant() const;
    void SetSvartTrekant(const SvartTrekant &svartTrekant);
};

class XmlAtc : public XMLObject {
public:
    std::string GetName() const override;
};

class XmlNavnFormStyrke : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddelCore> legemiddel;
    std::string navnFormStyrke{};
public:
    XmlNavnFormStyrke(std::shared_ptr<XmlLegemiddelCore> legemiddel) : legemiddel(legemiddel) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class XmlAtcHandler : public XmlValueWithCodeSetHandler<XmlLegemiddelCore> {
public:
    XmlAtcHandler() : XmlValueWithCodeSetHandler<XmlLegemiddelCore>("Atc") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) override;
};

class XmlNavnFormStyrkeHandler : public XmlContentElementHandler<XmlLegemiddelCore> {
public:
    XmlNavnFormStyrkeHandler() : XmlContentElementHandler<XmlLegemiddelCore>("NavnFormStyrke") {}
    bool Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) override;
};

class XmlReseptgruppeHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddelCore> {
public:
    XmlReseptgruppeHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddelCore>("Reseptgruppe") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlLegemiddelformKortHandler : public XmlValueWithCodeSetHandler<XmlLegemiddelCore> {
public:
    XmlLegemiddelformKortHandler() : XmlValueWithCodeSetHandler<XmlLegemiddelCore>("LegemiddelformKort") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) override;
};

class XmlRefVilkarHandler : public XmlContentElementHandler<XmlLegemiddelCore> {
public:
    XmlRefVilkarHandler() : XmlContentElementHandler<XmlLegemiddelCore>("RefVilkar") {}
    bool Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) override;
};

class XmlTypeSoknadSlvHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddelCore> {
public:
    XmlTypeSoknadSlvHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddelCore>("TypeSoknadSlv") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlOpioidsoknadHandler : public XmlContentElementHandler<XmlLegemiddelCore> {
public:
    XmlOpioidsoknadHandler() : XmlContentElementHandler<XmlLegemiddelCore>("Opioidsoknad") {}
    bool Merge(std::shared_ptr<XmlLegemiddelCore> parent, const std::string &content) override;
};

class XmlSvartTrekantHandler : public XmlValueWithCodeSetHandler<XmlLegemiddelCore> {
public:
    XmlSvartTrekantHandler() : XmlValueWithCodeSetHandler<XmlLegemiddelCore>("SvartTrekant") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelCore>> obj) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELCORE_H
