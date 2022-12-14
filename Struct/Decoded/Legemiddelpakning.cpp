//
// Created by sigsegv on 12/11/22.
//

#include "Legemiddelpakning.h"

Preparattype Legemiddelpakning::GetPreparattype() const {
    return preparattype;
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
    return refusjon;
}

PakningByttegruppe Legemiddelpakning::GetPakningByttegruppe() const {
    return pakningByttegruppe;
}