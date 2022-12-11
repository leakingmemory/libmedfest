//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H


#include "XMLObject.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/AdministreringLegemiddel.h"
#include "../Struct/Decoded/EnhetDosering.h"
#include "../Struct/Decoded/ForhandsregelInntak.h"
#include "../Struct/Decoded/Kortdose.h"
#include <memory>
#include <map>

class XmlLegemiddel;

class XmlAdministreringLegemiddel : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddel> parent;
    Administrasjonsvei administrasjonsvei{};
    EnhetDosering enhetDosering{};
    std::vector<BruksomradeEtikett> bruksomradeEtikett{};
    KanKnuses kanKnuses;
    std::vector<ForhandsregelInntak> forhandsregelInntak{};
    std::vector<Kortdose> kortdose{};
public:
    XmlAdministreringLegemiddel(std::shared_ptr<XmlLegemiddel> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetAdministrasjonsvei(const Administrasjonsvei &administrasjonsvei);
    void SetEnhetDosering(const EnhetDosering &enhetDosering);
    void AddBruksomradeEtikett(const BruksomradeEtikett &bruksomradeEtikett);
    void SetKanKnuses(const KanKnuses &kanKnuses);
    void AddForhandsregelInntak(const ForhandsregelInntak &forhandsregelInntak);
    void AddKortdose(const Kortdose &kortdose);
    void Merge();
};

class XmlAdministreringLegemiddelHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlAdministrasjonsveiHandler : public XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel> {
public:
    XmlAdministrasjonsveiHandler() : XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel>("Administrasjonsvei") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) override;
};

class XmlEnhetDoseringHandler : public XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel> {
public:
    XmlEnhetDoseringHandler() : XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel>("EnhetDosering") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) override;
};

class XmlBruksomradeEtikettHandler : public XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel> {
public:
    XmlBruksomradeEtikettHandler() : XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel>("BruksomradeEtikett") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) override;
};

class XmlKanKnusesHandler : public XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel> {
public:
    XmlKanKnusesHandler() : XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel>("KanKnuses") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlForhandsregelInntakHandler : public XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel> {
public:
    XmlForhandsregelInntakHandler() : XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel>("ForhandsregelInntak") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) override;
};

class XmlKortdoseHandler : public XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel> {
public:
    XmlKortdoseHandler() : XmlValueWithCodeSetHandler<XmlAdministreringLegemiddel>("Kortdose") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAdministreringLegemiddel>> obj) override;
};

#endif //LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H
