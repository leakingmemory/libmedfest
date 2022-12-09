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
#include <memory>
#include <map>

class XmlLegemiddel {
private:
    Atc atc{};
    std::string navnFormStyrke{};
    Reseptgruppe reseptgruppe{};
public:
    virtual ~XmlLegemiddel() = default;
    [[nodiscard]] Atc GetAtc() const;
    void SetAtc(const Atc &);
    [[nodiscard]] std::string GetNavnFormStyrke();
    void SetNavnFormStyrke(const std::string &navnFormStyrke);
    [[nodiscard]] Reseptgruppe GetReseptgruppe();
    void SetReseptgruppe(const Reseptgruppe &reseptgruppe);
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

class XmlNavnFormStyrkeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlReseptgruppeHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddel> {
public:
    XmlReseptgruppeHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddel>("Reseptgruppe") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDEL_H
