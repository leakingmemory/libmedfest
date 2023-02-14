//
// Created by sigsegv on 2/13/23.
//

#include "POppfInteraksjonIkkeVurdert.h"
#include "../Decoded/OppfInteraksjonIkkeVurdert.h"

POppfInteraksjonIkkeVurdert::POppfInteraksjonIkkeVurdert(const OppfInteraksjonIkkeVurdert &interaksjonIkkeVurdert,
                                                         std::vector<FestUuid> &idblock, std::string &strblock,
                                                         std::map<std::string, uint32_t> &cache) :
        POppf(interaksjonIkkeVurdert, idblock, strblock, cache),
        PInteraksjonIkkeVurdert(interaksjonIkkeVurdert.interaksjonIkkeVurdert, strblock, cache)
{
}