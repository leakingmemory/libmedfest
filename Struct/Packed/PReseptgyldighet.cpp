//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PReseptgyldighet.h>
#include <Struct/Decoded/Reseptgyldighet.h>

PReseptgyldighet::PReseptgyldighet(const Reseptgyldighet &reseptgyldighet, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        kjonn(reseptgyldighet.GetKjonn(), strblock, cache),
        varighet(reseptgyldighet.GetVarighet(), strblock, cache) {}
