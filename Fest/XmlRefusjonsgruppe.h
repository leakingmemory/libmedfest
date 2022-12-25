//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLREFUSJONSGRUPPE_H
#define LEGEMFEST_XMLREFUSJONSGRUPPE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "XmlValueWithCodeSet.h"
#include "XmlAtc.h"
#include "XmlContentElement.h"
#include "XmlRefVilkar.h"
#include "../Struct/Decoded/GruppeNr.h"
#include "../Struct/Decoded/MaybeBoolean.h"
#include "../Struct/Decoded/Refusjonskode.h"
#include <memory>
#include <map>
#include <vector>

class XmlRefusjonshjemmel;

class XmlRefusjonsgruppe : public XMLObject, public FestIdObject, public XmlAtc, public XmlRefVilkar {
private:
    std::shared_ptr<XmlRefusjonshjemmel> parent;
    GruppeNr gruppeNr{};
    MaybeBoolean kreverRefusjonskode{MaybeBoolean::UNSPECIFIED};
    std::string refusjonsberettigetBruk{};
    std::vector<Refusjonskode> refusjonskode{};
public:
    XmlRefusjonsgruppe(std::shared_ptr<XmlRefusjonshjemmel> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetGruppeNr(const GruppeNr &gruppeNr);
    void SetKreverRefusjonskode(bool kreverRefusjonskode);
    void SetRefusjonsberettigetBruk(const std::string &refusjonsberettigetBruk);
    void AddRefusjonskode(const Refusjonskode &refusjonskode);
    bool Merge();
};

class XmlRefusjonsgruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlGruppeNrHandler : public XmlValueWithCodeSetHandler<XmlRefusjonsgruppe> {
public:
    XmlGruppeNrHandler() : XmlValueWithCodeSetHandler<XmlRefusjonsgruppe>("GruppeNr") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonsgruppe>> obj) override;
};

class XmlKreverRefusjonskodeHandler : public XmlContentElementHandler<XmlRefusjonsgruppe> {
public:
    XmlKreverRefusjonskodeHandler() : XmlContentElementHandler<XmlRefusjonsgruppe>("KreverRefusjonskode") {}
    bool Merge(std::shared_ptr<XmlRefusjonsgruppe> parent, const std::string &content) override;
};

class XmlRefusjonsberettigetBrukHandler : public XmlContentElementHandler<XmlRefusjonsgruppe> {
public:
    XmlRefusjonsberettigetBrukHandler() : XmlContentElementHandler<XmlRefusjonsgruppe>("RefusjonsberettighetBruk") {}
    bool Merge(std::shared_ptr<XmlRefusjonsgruppe> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFUSJONSGRUPPE_H
