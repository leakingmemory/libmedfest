//
// Created by sigsegv on 2/12/23.
//

#include <Struct/Packed/POppfInteraksjon.h>
#include <Struct/Decoded/OppfInteraksjon.h>

POppfInteraksjon::POppfInteraksjon(const OppfInteraksjon &oppf, ReferanseList &referanseList,
                                   SubstansgruppeList &substansgruppeList, SubstansList &substansList,
                                   ValueWithCodesetList &valueWithCodesetList, std::vector<FestUuid> &idblock,
                                   std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PInteraksjon(oppf.interaksjon, referanseList, substansgruppeList, substansList, valueWithCodesetList, idblock, strblock, cache)
{
}

bool POppfInteraksjon::operator==(const POppfInteraksjon &other) const {
    return POppf::operator==(other) &&
           PInteraksjon::operator==(other);
}
