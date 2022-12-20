//
// Created by sigsegv on 12/19/22.
//

#include "ProduktInfoVare.h"

std::string ProduktInfoVare::GetProduktNr() const {
    return produktNr;
}

std::string ProduktInfoVare::GetVolum() const {
    return volum;
}

EnhetStorrelse ProduktInfoVare::GetEnhetStorrelse() const {
    return enhetStorrelse;
}

int ProduktInfoVare::GetAntPerPakning() const {
    return antPerPakning;
}

MaybeBoolean ProduktInfoVare::GetTillattMerMakspris() const {
    return tillattMerMakspris;
}