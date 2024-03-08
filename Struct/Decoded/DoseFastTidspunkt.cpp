//
// Created by sigsegv on 12/31/22.
//

#include <Struct/Decoded/DoseFastTidspunkt.h>

ValueUnit DoseFastTidspunkt::GetMengde() const {
    return mengde;
}

ValueUnit DoseFastTidspunkt::GetIntervall() const {
    return intervall;
}

ValueWithDistinguishedName DoseFastTidspunkt::GetTidsomrade() const {
    return tidsomrade;
}

bool DoseFastTidspunkt::GetGisEksakt() const {
    return gisEksakt;
}

FastDose DoseFastTidspunkt::GetFastDose() const {
    return fastDose;
}