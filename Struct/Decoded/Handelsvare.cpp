//
// Created by sigsegv on 12/19/22.
//

#include "Handelsvare.h"

std::string Handelsvare::GetNr() const {
    return nr;
}

std::string Handelsvare::GetNavn() const {
    return navn;
}

ProduktInfoVare Handelsvare::GetProduktInfoVare() const {
    return produktInfoVare;
}

Leverandor Handelsvare::GetLeverandor() const {
    return leverandor;
}

std::vector<PrisVare> Handelsvare::GetPrisVare() const {
    return prisVare;
}

Refusjon Handelsvare::GetRefusjon() const {
    return refusjon;
}