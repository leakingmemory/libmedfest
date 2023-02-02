//
// Created by sigsegv on 1/18/23.
//

#include "PPakningskomponentInfo.h"
#include "../Decoded/PakningskomponentInfo.h"

PPakningskomponentInfo::PPakningskomponentInfo(const PakningskomponentInfo &info, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        pakningstype(info.GetPakningstype(), strblock, cache),
        mengde(info.GetMengde(), strblock, cache) {
}

bool PPakningskomponentInfo::operator==(const PPakningskomponentInfo &other) const {
    return pakningstype == other.pakningstype && mengde == other.mengde;
}