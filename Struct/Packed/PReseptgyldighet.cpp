//
// Created by sigsegv on 1/10/23.
//

#include "PReseptgyldighet.h"
#include "../Decoded/Reseptgyldighet.h"

PReseptgyldighet::PReseptgyldighet(const Reseptgyldighet &reseptgyldighet, std::string &strblock) :
        kjonn(reseptgyldighet.GetKjonn(), strblock),
        varighet(reseptgyldighet.GetVarighet(), strblock) {}
