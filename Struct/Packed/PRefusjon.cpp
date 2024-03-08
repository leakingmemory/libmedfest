//
// Created by sigsegv on 1/19/23.
//

#include <Struct/Packed/PRefusjon.h>
#include <Struct/Decoded/Refusjon.h>
#include <Struct/Packed/StringList.h>

PRefusjon::PRefusjon(const Refusjon &refusjon, StringList &stringList, std::string &strblock,
                     std::map<std::string,uint32_t> &cache) :
        refRefusjonsgruppe(stringList.StoreList(refusjon.GetRefRefusjonsgruppe(), strblock, cache)),
        gyldigFraDato(refusjon.GetGyldigFraDato(), strblock, cache),
        forskrivesTilDato(refusjon.GetForskrivesTilDato(), strblock, cache),
        utleveresTilDato(refusjon.GetUtleveresTilDato(), strblock, cache) {
}

bool PRefusjon::operator==(const PRefusjon &other) const {
    return refRefusjonsgruppe == other.refRefusjonsgruppe &&
        gyldigFraDato == other.gyldigFraDato &&
        forskrivesTilDato == other.forskrivesTilDato &&
        utleveresTilDato == other.utleveresTilDato;
}
