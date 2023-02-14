//
// Created by sigsegv on 2/13/23.
//

#include "PInteraksjonIkkeVurdert.h"
#include "../Decoded/InteraksjonIkkeVurdert.h"

PInteraksjonIkkeVurdert::PInteraksjonIkkeVurdert(const InteraksjonIkkeVurdert &interaksjonIkkeVurdert, std::string &strblock,
                                                 std::map<std::string, uint32_t> &cache) :
        atc(interaksjonIkkeVurdert.atc, strblock, cache) {}