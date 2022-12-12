//
// Created by sigsegv on 12/12/22.
//

#include "Pakningsinfo.h"

std::string Pakningsinfo::GetMerkevareId() const {
    return merkevareId;
}

std::string Pakningsinfo::GetPakningsstr() const {
    return pakningsstr;
}

EnhetPakning Pakningsinfo::GetEnhetPakning() const {
    return enhetPakning;
}

Pakningstype Pakningsinfo::GetPakningstype() const {
    return pakningstype;
}

std::string Pakningsinfo::GetMengde() const {
    return mengde;
}

DDD Pakningsinfo::GetDDD() const {
    return ddd;
}

int Pakningsinfo::GetStatistikkfaktor() const {
    return statistikkfaktor;
}