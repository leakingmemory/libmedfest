//
// Created by sigsegv on 1/9/23.
//

#include "POppf.h"
#include "../Decoded/Oppf.h"

POppf::POppf(const Oppf &oppf, std::vector<FestUuid> &uuidblock, std::string &strblock) :
        id(oppf.GetId(), uuidblock),
        tidspunkt(oppf.GetTidspunkt(), strblock),
        status() {
    auto s = oppf.GetStatus();
    status = PValueWithDistinguishedName(s, strblock);
}