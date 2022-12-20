//
// Created by sigsegv on 12/19/22.
//

#include "MedForbrMatr.h"

std::string MedForbrMatr::GetNr() const {
    return nr;
}

std::string MedForbrMatr::GetNavn() const {
    return navn;
}

ProduktInfoVare MedForbrMatr::GetProduktInfoVare() const {
    return produktInfoVare;
}