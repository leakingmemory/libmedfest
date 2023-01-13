//
// Created by sigsegv on 1/10/23.
//

#include "PLenke.h"
#include "../Decoded/Lenke.h"

PLenke::PLenke(const Lenke &lenke, std::string &strblock) :
        beskrivelse(lenke.GetBeskrivelse(), strblock),
        www(lenke.GetWww(), strblock) {
}