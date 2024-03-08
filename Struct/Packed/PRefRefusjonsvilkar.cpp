//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PRefRefusjonsvilkar.h>
#include <Struct/Decoded/RefRefusjonsvilkar.h>

PRefRefusjonsvilkar::PRefRefusjonsvilkar(const RefRefusjonsvilkar &refRefusjonsvilkar, std::vector<FestUuid> &idblock,
                                         std::string &strblock, std::map<std::string, uint32_t> &cache) :
        id(refRefusjonsvilkar.GetId(), idblock),
        fraDato(refRefusjonsvilkar.GetFraDato(), strblock, cache)
{
}

bool PRefRefusjonsvilkar::operator==(const PRefRefusjonsvilkar &other) const {
    return id == other.id && fraDato == other.fraDato;
}