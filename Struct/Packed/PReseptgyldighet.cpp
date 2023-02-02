//
// Created by sigsegv on 1/10/23.
//

#include "PReseptgyldighet.h"
#include "../Decoded/Reseptgyldighet.h"

PReseptgyldighet::PReseptgyldighet(const Reseptgyldighet &reseptgyldighet, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        kjonn(reseptgyldighet.GetKjonn(), strblock, cache),
        varighet(reseptgyldighet.GetVarighet(), strblock, cache) {}
