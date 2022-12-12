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

Markedsforingsinfo Legemiddelpakning::GetMarkedsforingsinfo() const {
    return markedsforingsinfo;
}

std::string Legemiddelpakning::GetEan() const {
    return ean;
}