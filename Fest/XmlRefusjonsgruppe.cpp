//
// Created by sigsegv on 12/25/22.
//

#include "XmlRefusjonsgruppe.h"
#include "XmlRefusjonshjemmel.h"
#include <iostream>

std::string XmlRefusjonsgruppe::GetName() const {
    return "Refusjonsgruppe";
}

void XmlRefusjonsgruppe::SetGruppeNr(const GruppeNr &gruppeNr) {
    this->gruppeNr = gruppeNr;
}

void XmlRefusjonsgruppe::SetKreverRefusjonskode(bool kreverRefusjonskode) {
    this->kreverRefusjonskode = kreverRefusjonskode ? MaybeBoolean::MTRUE : MaybeBoolean::MFALSE;
}

void XmlRefusjonsgruppe::SetRefusjonsberettigetBruk(const std::string &refusjonsberettigetBruk) {
    this->refusjonsberettigetBruk = refusjonsberettigetBruk;
}

void XmlRefusjonsgruppe::AddRefusjonskode(const Refusjonskode &refusjonskode) {
    this->refusjonskode.emplace_back(refusjonskode);
}

bool XmlRefusjonsgruppe::Merge() {
    bool kreverRefusjonskode;
    switch (this->kreverRefusjonskode) {
        case MaybeBoolean::MFALSE:
            kreverRefusjonskode = false;
            break;
        case MaybeBoolean::MTRUE:
            kreverRefusjonskode = true;
            break;
        default:
            std::cerr << "Error: Not specified KreverRefusjonskode\n";
            return false;
    }
    parent->SetRefusjonsgruppe({GetId(), gruppeNr, GetAtc(), refusjonsberettigetBruk, refusjonskode, GetRefVilkar(),
                                kreverRefusjonskode});
    return true;
}

std::shared_ptr<XMLObject> XmlRefusjonsgruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                   const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlRefusjonshjemmel> typedParent = std::dynamic_pointer_cast<XmlRefusjonshjemmel>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Refusjonshjemmel\n";
        return {};
    }
    return std::make_shared<XmlRefusjonsgruppe>(typedParent);
}

bool XmlRefusjonsgruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *r = dynamic_cast<XmlRefusjonsgruppe *>(&(*obj));
    if (r == nullptr) {
        std::cerr << "Error: Not ending Refusjonsgruppe\n";
        return false;
    }
    return r->Merge();
}

bool XmlGruppeNrHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonsgruppe>> obj) {
    obj->GetParent()->SetGruppeNr({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlKreverRefusjonskodeHandler::Merge(std::shared_ptr<XmlRefusjonsgruppe> parent, const std::string &content) {
    if (content == "false") {
        parent->SetKreverRefusjonskode(false);
        return true;
    }
    if (content == "true") {
        parent->SetKreverRefusjonskode(true);
        return true;
    }
    std::cerr << "Error: KreverRefusjonskode: Invalid value: " << content << "\n";
    return false;
}

bool XmlRefusjonsberettigetBrukHandler::Merge(std::shared_ptr<XmlRefusjonsgruppe> parent, const std::string &content) {
    parent->SetRefusjonsberettigetBruk(content);
    return true;
}