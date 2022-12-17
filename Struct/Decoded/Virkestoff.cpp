//
// Created by sigsegv on 12/16/22.
//

#include "Virkestoff.h"

std::string Virkestoff::GetId() const {
    return id;
}

std::string Virkestoff::GetNavn() const {
    return navn;
}

std::string Virkestoff::GetNavnEngelsk() const {
    return navnEngelsk;
}

std::vector<std::string> Virkestoff::GetRefVirkestoff() const {
    return refVirkestoff;
}