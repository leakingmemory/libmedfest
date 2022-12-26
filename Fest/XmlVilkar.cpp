//
// Created by sigsegv on 12/26/22.
//

#include "XmlVilkar.h"
#include "KatVilkar.h"
#include <iostream>

std::string XmlVilkar::GetName() const {
    return "Vilkar";
}

void XmlVilkar::SetVilkarNr(const std::string &vilkarNr) {
    this->vilkarNr = vilkarNr;
}

void XmlVilkar::SetGruppe(const Gruppe &gruppe) {
    this->gruppe = gruppe;
}

void XmlVilkar::SetGjelderFor(const GjelderFor &gjelderFor) {
    this->gjelderFor = gjelderFor;
}

void XmlVilkar::SetTekst(const std::string &tekst) {
    this->tekst = tekst;
}

void XmlVilkar::SetStrukturertVilkar(const StrukturertVilkar &strukturertVilkar) {
    this->strukturertVilkar = strukturertVilkar;
}

bool XmlVilkar::Merge() {
    parent->SetVilkar({GetId(), vilkarNr, gruppe, gjelderFor, tekst, GetGyldigFraDato(), strukturertVilkar});
    return true;
}

std::string XmlStrukturertVilkar::GetName() const {
    return "StrukturertVilkar";
}

void XmlStrukturertVilkar::SetVerdiKodet(const ValueWithCodeSet &verdiKodet) {
    this->verdiKodet = verdiKodet;
}

void XmlStrukturertVilkar::SetVerdiTekst(const std::string &verdiTekst) {
    this->verdiTekst = verdiTekst;
}

bool XmlStrukturertVilkar::Merge() {
    parent->SetStrukturertVilkar({GetType(), verdiKodet, verdiTekst});
    return true;
}

std::shared_ptr<XMLObject> XmlVilkarHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<XmlOppfVilkar> typedParent = std::dynamic_pointer_cast<XmlOppfVilkar>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Vilkar\n";
        return {};
    }
    return std::make_shared<XmlVilkar>(typedParent);
}

bool XmlVilkarHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *v = dynamic_cast<XmlVilkar *>(&(*obj));
    if (v == nullptr) {
        std::cerr << "Error: Not ending Vilkar\n";
        return false;
    }
    return v->Merge();
}

bool XmlVilkarNrHandler::Merge(std::shared_ptr<XmlVilkar> parent, const std::string &content) {
    parent->SetVilkarNr(content);
    return true;
}

bool XmlGruppeHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVilkar>> obj) {
    obj->GetParent()->SetGruppe({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlGjelderForHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetGjelderFor({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlTekstHandler::Merge(std::shared_ptr<XmlVilkar> parent, const std::string &content) {
    parent->SetTekst(content);
    return true;
}

std::shared_ptr<XMLObject> XmlStrukturertVilkarHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlVilkar> typedParent = std::dynamic_pointer_cast<XmlVilkar>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected StrukturertVilkar\n";
        return {};
    }
    return std::make_shared<XmlStrukturertVilkar>(typedParent);
}

bool XmlStrukturertVilkarHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *s = dynamic_cast<XmlStrukturertVilkar *>(&(*obj));
    if (s == nullptr) {
        std::cerr << "Error: Not ending StrukturertVilkar\n";
        return false;
    }
    return s->Merge();
}

bool XmlVerdiKodetHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlStrukturertVilkar>> obj) {
    obj->GetParent()->SetVerdiKodet(obj->GetValueWithCodeSet());
    return true;
}

bool XmlVerdiTekstHandler::Merge(std::shared_ptr<XmlStrukturertVilkar> parent, const std::string &content) {
    parent->SetVerdiTekst(content);
    return true;
}
