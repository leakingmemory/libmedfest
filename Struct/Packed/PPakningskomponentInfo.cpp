//
// Created by sigsegv on 1/18/23.
//

#include "PPakningskomponentInfo.h"
#include "../Decoded/PakningskomponentInfo.h"

PPakningskomponentInfo::PPakningskomponentInfo(const PakningskomponentInfo &info, std::string &strblock) :
        pakningstype(info.GetPakningstype(), strblock),
        mengde(info.GetMengde(), strblock) {
}

bool PPakningskomponentInfo::operator==(const PPakningskomponentInfo &other) const {
    return pakningstype == other.pakningstype && mengde == other.mengde;
}