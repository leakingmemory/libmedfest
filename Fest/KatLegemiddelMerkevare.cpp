//
// Created by sigsegv on 12/9/22.
//

#include "KatLegemiddelMerkevare.h"
#include "Fest.h"
#include <iostream>

std::string KatLegemiddelMerkevare::GetName() {
    return "KatLegemiddelMerkevare";
}

void KatLegemiddelMerkevare::Merge(const OppfLegemiddelMerkevare &oppf) {

}

std::shared_ptr<XMLObject>
KatLegemiddelMerkevareHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: HentetDato parent is not Fest\n";
        return {};
    }
    return std::make_shared<KatLegemiddelMerkevare>(fest);
}

bool KatLegemiddelMerkevareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<KatLegemiddelMerkevare*>(&(*obj)) != nullptr;
}

std::string OppfLegemiddelMerkevare::GetName() {
    return "OppfLegemiddelMerkevare";
}

void OppfLegemiddelMerkevare::Merge() {
    kat->Merge(*this);
}

std::shared_ptr<XMLObject> OppfLegemiddelMerkevareHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                        const std::vector<NameValue> &attributes) {
    std::shared_ptr<KatLegemiddelMerkevare> kat = std::dynamic_pointer_cast<KatLegemiddelMerkevare>(parent);
    if (!kat) {
        std::cerr << "Error: OppfLegemiddelMerkevare parent is not KatLegemiddelMerkevare\n";
        return {};
    }
    return std::make_shared<OppfLegemiddelMerkevare>(kat);
}

bool OppfLegemiddelMerkevareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<OppfLegemiddelMerkevare*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End element, not for the OppfLegemiddelMerkevare\n";
        return false;
    }
    oppf->Merge();
    return true;
}