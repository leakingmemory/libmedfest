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

Leverandor MedForbrMatr::GetLeverandor() const {
    return leverandor;
}

std::vector<PrisVare> MedForbrMatr::GetPrisVare() const {
    return prisVare;
}

Refusjon MedForbrMatr::GetRefusjon() const {
    return refusjon;
}