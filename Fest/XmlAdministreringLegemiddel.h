//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H
#define LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H


#include "XMLObject.h"
#include "XmlValueWithCodeSet.h"
#include "XmlContentElement.h"
#include "../Struct/Decoded/AdministreringLegemiddel.h"
#include "../Struct/Decoded/EnhetDosering.h"
#include "../Struct/Decoded/ForhandsregelInntak.h"
#include "../Struct/Decoded/Kortdose.h"
#include "../Struct/Decoded/Deling.h"
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
    Deling deling{};
    KanApnes kanApnes{};
    Bolus bolus{};
    InjeksjonshastighetBolus injeksjonshastighetBolus{};
    MaybeBoolean blandingsveske{MaybeBoolean::UNSPECIFIED};
public:
    XmlAdministreringLegemiddel(std::shared_ptr<XmlLegemiddel> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetAdministrasjonsvei(const Administrasjonsvei &administrasjonsvei);
    void SetEnhetDosering(const EnhetDosering &enhetDosering);
    void AddBruksomradeEtikett(const BruksomradeEtikett &bruksomradeEtikett);
    void SetKanKnuses(const KanKnuses &kanKnuses);
    void AddForhandsregelInntak(const ForhandsregelInntak &forhandsregelInntak);
    void AddKortdose(const Kortdose &kortdose);
    void SetDeling(const Deling &deling);
    void SetKanApnes(const KanApnes &kanApnes);
    void SetBolus(const Bolus &bolus);
    void SetInjeksjonshastighetBolus(const InjeksjonshastighetBolus &injeksjonshastighetBolus);
    void SetBlandingsveske(bool blandingsveske);
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

class XmlDelingHandler : public XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel> {
public:
    XmlDelingHandler() : XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel>("Deling") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlKanApnesHandler : public XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel> {
public:
    XmlKanApnesHandler() : XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel>("KanApnes") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlBolusHandler : public XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel> {
public:
    XmlBolusHandler() : XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel>("Bolus") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlInjeksjonshastighetBolusHandler : public XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel> {
public:
    XmlInjeksjonshastighetBolusHandler() : XmlValueWithDistinguishedNameHandler<XmlAdministreringLegemiddel>("InjeksjonshastighetBolus") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlBlandingsveskeHandler : public XmlContentElementHandler<XmlAdministreringLegemiddel> {
public:
    XmlBlandingsveskeHandler() : XmlContentElementHandler<XmlAdministreringLegemiddel>("Blandingsveske") {}
    bool Merge(std::shared_ptr<XmlAdministreringLegemiddel> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLADMINISTRERINGLEGEMIDDEL_H
