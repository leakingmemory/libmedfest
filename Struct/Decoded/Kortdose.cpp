//
// Created by sigsegv on 12/30/22.
//

#include <Struct/Decoded/Kortdose.h>

ValueWithCodeSet Kortdose::GetKortdose() const {
    return kortdose;
}

std::string Kortdose::GetBeskrivelseTerm() const {
    return beskrivelseTerm;
}

std::vector<Legemiddelforbruk> Kortdose::GetLegemiddelforbruk() const {
    return legemiddelforbruk;
}