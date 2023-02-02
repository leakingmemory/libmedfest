//
// Created by sigsegv on 1/18/23.
//

#include "PPakningskomponent.h"
#include "../Decoded/Pakningskomponent.h"

PPakningskomponent::PPakningskomponent(const Pakningskomponent &pakningskomponent, std::string &strblock,
                                       std::map<std::string,uint32_t> &cache) :
        PPakningskomponentInfo(pakningskomponent, strblock, cache), antall(pakningskomponent.GetAntall()) {
}

bool PPakningskomponent::operator==(const PPakningskomponent &other) const {
    return PPakningskomponentInfo::operator==(other) && antall == other.antall;
}