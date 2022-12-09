//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDEL_H
#define LEGEMFEST_XMLLEGEMIDDEL_H


#include "../Struct/Decoded/Atc.h"
#include "../Struct/Decoded/Reseptgruppe.h"
#include "XMLObject.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/LegemiddelformKort.h"
#include "XmlContentElement.h"
#include "../Struct/Decoded/TypeSoknadSlv.h"
#include <memory>
#include <map>
#include <vector>

class XmlLegemiddel {
private:
    Atc atc{};
    std::string navnFormStyrke{};
    Reseptgruppe reseptgruppe{};
    LegemiddelformKort legemiddelformKort{};
    std::vector<std::string> refVilkar{};
    TypeSoknadSlv typeSoknadSlv{};
public:
    virtual ~XmlLegemiddel() = default;
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
    void SetTypeSoknadSlv(const TypeSoknadSlv &typeSoknadSlv1);
};

class XmlAtc : public XMLObject {
public:
    std::string GetName() const override;
};

class XmlNavnFormStyrke : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddel> legemiddel;
    std::string navnFormStyrke{};
public:
    XmlNavnFormStyrke(std::shared_ptr<XmlLegemiddel> legemiddel) : legemiddel(legemiddel) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class XmlAtcHandler : public XmlValueWithCodeSetHandler<XmlLegemiddel> {
public:
    XmlAtcHandler() : XmlValueWithCodeSetHandler<XmlLegemiddel>("Atc") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) override;
};

class XmlNavnFormStyrkeHandler : public XmlContentElementHandler<XmlLegemiddel> {
public:
    XmlNavnFormStyrkeHandler() : XmlContentElementHandler<XmlLegemiddel>("NavnFormStyrke") {}
    bool Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) override;
};

class XmlReseptgruppeHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddel> {
public:
    XmlReseptgruppeHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddel>("Reseptgruppe") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlLegemiddelformKortHandler : public XmlValueWithCodeSetHandler<XmlLegemiddel> {
public:
    XmlLegemiddelformKortHandler() : XmlValueWithCodeSetHandler<XmlLegemiddel>("LegemiddelformKort") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) override;
};

class XmlRefVilkarHandler : public XmlContentElementHandler<XmlLegemiddel> {
public:
    XmlRefVilkarHandler() : XmlContentElementHandler<XmlLegemiddel>("RefVilkar") {}
    bool Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) override;
};

class XmlTypeSoknadSlvHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddel> {
public:
    XmlTypeSoknadSlvHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddel>("TypeSoknadSlv") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDEL_H
