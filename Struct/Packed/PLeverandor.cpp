//
// Created by sigsegv on 1/29/23.
//

#include <Struct/Packed/PLeverandor.h>
#include <Struct/Decoded/Leverandor.h>

PLeverandor::PLeverandor(const Leverandor &leverandor, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        navn(leverandor.GetNavn(), strblock, cache),
        adresse(leverandor.GetAdresse(), strblock, cache),
        telefon(leverandor.GetTelefon(), strblock, cache) {}

bool PLeverandor::operator==(const PLeverandor &other) const {
    return navn == other.navn &&
           adresse == other.adresse &&
           telefon == other.telefon;
}
