//
// Created by sigsegv on 1/29/23.
//

#include "PLeverandor.h"
#include "../Decoded/Leverandor.h"

PLeverandor::PLeverandor(const Leverandor &leverandor, std::string &strblock) :
        navn(leverandor.GetNavn(), strblock),
        adresse(leverandor.GetAdresse(), strblock),
        telefon(leverandor.GetTelefon(), strblock) {}

