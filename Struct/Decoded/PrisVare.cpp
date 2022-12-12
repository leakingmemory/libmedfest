//
// Created by sigsegv on 12/12/22.
//

#include "PrisVare.h"

ValueWithCodeSet PrisVare::GetType() const {
    return type;
}

Pris PrisVare::GetPris() const {
    return pris;
}

std::string PrisVare::GetGyldigFraDato() const {
    return gyldigFraDato;
}