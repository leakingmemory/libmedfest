//
// Created by sigsegv on 2/4/23.
//

#include "PInfo.h"
#include "FestUuid.h"
#include "../Decoded/Info.h"

PInfo::PInfo(const Info &info, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        betegnelse(info.betegnelse, strblock, cache),
        kortnavn(info.kortnavn, strblock, cache),
        ansvarligUtgiver(info.ansvarligUtgiver, strblock, cache),
        id(info.id, strblock, cache)
{
}

bool PInfo::operator==(const PInfo &other) const {
    return id == other.id &&
           betegnelse == other.betegnelse &&
           kortnavn == other.kortnavn &&
           ansvarligUtgiver == other.ansvarligUtgiver;
}