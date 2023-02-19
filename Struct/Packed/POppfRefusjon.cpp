//
// Created by sigsegv on 2/6/23.
//

#include "POppfRefusjon.h"
#include "../Decoded/OppfRefusjon.h"

POppfRefusjon::POppfRefusjon(const OppfRefusjon &oppf, RefusjonskodeList &refusjonskodeList,
                             RefRefusjonsvilkarList &refRefusjonsvilkarList, StringList &stringList,
                             std::vector<FestUuid> &idblock, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PRefusjonshjemmel(oppf.refusjonshjemmel, refusjonskodeList, refRefusjonsvilkarList, stringList, idblock, strblock, cache)
{
}

bool POppfRefusjon::operator==(const POppfRefusjon &other) const {
    return POppf::operator==(other) &&
           PRefusjonshjemmel::operator==(other);
}
