//
// Created by sigsegv on 1/10/23.
//

#include "PLenke.h"
#include "../Decoded/Lenke.h"

PLenke::PLenke(const Lenke &lenke, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        beskrivelse(lenke.GetBeskrivelse(), strblock, cache),
        www(lenke.GetWww(), strblock, cache) {
}

bool PLenke::operator==(const PLenke &other) const {
    return beskrivelse == other.beskrivelse && www == other.www;
}