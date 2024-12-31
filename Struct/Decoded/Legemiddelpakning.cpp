//
// Created by sigsegv on 12/11/22.
//

#include <Struct/Decoded/Legemiddelpakning.h>

Preparattype Legemiddelpakning::GetPreparattype() const {
    return preparattype;
}

std::string Legemiddelpakning::GetId() const {
    return id;
}

std::string Legemiddelpakning::GetVarenr() const {
    return varenr;
}

Oppbevaring Legemiddelpakning::GetOppbevaring() const {
    return oppbevaring;
}

std::vector<Pakningsinfo> Legemiddelpakning::GetPakningsinfo() const {
    return pakningsinfo;
}

Markedsforingsinfo Legemiddelpakning::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}

std::string Legemiddelpakning::GetEan() const {
    return ean;
}

std::vector<PrisVare> Legemiddelpakning::GetPrisVare() const {
    return prisVare;
}

Refusjon Legemiddelpakning::GetRefusjon() const {
    if (refusjon.empty()) {
        return {};
    }
    return refusjon.back();
}

std::vector<Refusjon> Legemiddelpakning::GetRefusjonList() const {
    return refusjon;
}

PakningByttegruppe Legemiddelpakning::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}

Preparatomtaleavsnitt Legemiddelpakning::GetPreparatomtaleavsnitt() const {
    return preparatomtaleavsnitt;
}

bool Legemiddelpakning::GetIkkeKonservering() const {
    return ikkeKonservering;
}