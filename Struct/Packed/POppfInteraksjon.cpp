//
// Created by sigsegv on 2/12/23.
//

#include "POppfInteraksjon.h"
#include "../Decoded/OppfInteraksjon.h"

POppfInteraksjon::POppfInteraksjon(const OppfInteraksjon &oppf, ReferanseList &referanseList,
                                   SubstansgruppeList &substansgruppeList, SubstansList &substansList,
                                   ValueWithCodesetList &valueWithCodesetList, std::vector<FestUuid> &idblock,
                                   std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PInteraksjon(oppf.interaksjon, referanseList, substansgruppeList, substansList, valueWithCodesetList, idblock, strblock, cache)
{
}