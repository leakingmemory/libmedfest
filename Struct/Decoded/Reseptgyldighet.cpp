//
// Created by sigsegv on 12/11/22.
//

#include <Struct/Decoded/Reseptgyldighet.h>

std::string Reseptgyldighet::GetVarighet() const {
    return varighet;
}

ValueWithDistinguishedName Reseptgyldighet::GetKjonn() const {
    return kjonn;
}