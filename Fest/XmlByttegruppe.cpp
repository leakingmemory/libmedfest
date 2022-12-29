//
// Created by sigsegv on 12/28/22.
//

#include "XmlByttegruppe.h"
#include "KatByttegruppe.h"
#include <iostream>

std::string XmlByttegruppe::GetName() const {
    return "Byttegruppe";
}

void XmlByttegruppe::SetBeskrivelseByttbarhet(const std::string &beskrivelseByttbarhet) {
    this->beskrivelseByttbarhet = beskrivelseByttbarhet;
}

void XmlByttegruppe::SetMerknadTilByttbarhet(bool merknadTilByttbarhet) {
    this->merknadTilByttbarhet = merknadTilByttbarhet ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

bool XmlByttegruppe::Merge() {
    bool merknadTilByttbarhet;
    {
        switch (this->merknadTilByttbarhet) {
            case MaybeBoolean::FALSE:
                merknadTilByttbarhet = false;
                break;
            case MaybeBoolean::TRUE:
                merknadTilByttbarhet = true;
                break;
            default:
                std::cerr << "Error: No MerknadTilByttbarhet for Byttegruppe\n";
                return false;
        }
    }
    parent->SetByttegruppe({GetId(), GetKodeValueWithDN(), GetGyldigFraDato(), beskrivelseByttbarhet, merknadTilByttbarhet});
    return true;
}

std::shared_ptr<XMLObject> XmlByttegruppeHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                               const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfByttegruppe> typedParent = std::dynamic_pointer_cast<XmlOppfByttegruppe>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Byttegruppe\n";
        return {};
    }
    return std::make_shared<XmlByttegruppe>(typedParent);
}

bool XmlByttegruppeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *b = dynamic_cast<XmlByttegruppe *>(&(*obj));
    if (b == nullptr) {
        std::cerr << "Error: Not ending Byttegruppe\n";
        return false;
    }
    return b->Merge();
}

bool XmlMerknadTilByttbarhetHandler::Merge(std::shared_ptr<XmlByttegruppe> parent, const std::string &content) {
    if (content == "true") {
        parent->SetMerknadTilByttbarhet(true);
    } else if (content == "false") {
        parent->SetMerknadTilByttbarhet(false);
    } else {
        std::cerr << "Error: MerknadTilByttbarhet: Invalid value: " << content << "\n";
        return false;
    }
    return true;
}

bool XmlBeskrivelseByttbarhetHandler::Merge(std::shared_ptr<XmlByttegruppe> parent, const std::string &content) {
    parent->SetBeskrivelseByttbarhet(content);
    return true;
}