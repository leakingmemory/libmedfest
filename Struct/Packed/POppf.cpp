//
// Created by sigsegv on 1/9/23.
//

#include <Struct/Packed/POppf.h>
#include <Struct/Decoded/Oppf.h>

POppf::POppf(const Oppf &oppf, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        id(oppf.GetId(), uuidblock, false),
        tidspunkt(oppf.GetTidspunkt(), strblock, cache),
        status() {
    auto s = oppf.GetStatus();
    status = PValueWithDistinguishedName(s, strblock, cache);
}

bool POppf::operator==(const POppf &other) const {
    return id == other.id && tidspunkt == other.tidspunkt && status == other.status;
}
