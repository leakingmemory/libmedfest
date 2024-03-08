//
// Created by sigsegv on 2/13/23.
//

#include <Struct/Packed/PInteraksjonIkkeVurdert.h>
#include <Struct/Decoded/InteraksjonIkkeVurdert.h>

PInteraksjonIkkeVurdert::PInteraksjonIkkeVurdert(const InteraksjonIkkeVurdert &interaksjonIkkeVurdert, std::string &strblock,
                                                 std::map<std::string, uint32_t> &cache) :
        atc(interaksjonIkkeVurdert.atc, strblock, cache) {}