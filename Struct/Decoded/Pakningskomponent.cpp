//
// Created by sigsegv on 12/12/22.
//

#include "Pakningskomponent.h"

Pakningstype Pakningskomponent::GetPakningstype() const {
    return pakningstype;
}

ValueUnit Pakningskomponent::GetMengde() const {
    return mengde;
}

int Pakningskomponent::GetAntall() const {
    return antall;
}