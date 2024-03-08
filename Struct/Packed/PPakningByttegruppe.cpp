//
// Created by sigsegv on 1/19/23.
//

#include <Struct/Packed/PPakningByttegruppe.h>
#include <Struct/Decoded/PakningByttegruppe.h>

PPakningByttegruppe::PPakningByttegruppe(const PakningByttegruppe &pakningByttegruppe, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        refByttegruppe(pakningByttegruppe.GetRefByttegruppe(), uuidblock),
        gyldigFraDato(pakningByttegruppe.GetGyldigFraDato(), strblock, cache) {}

bool PPakningByttegruppe::operator==(const PPakningByttegruppe &other) const {
    return refByttegruppe == other.refByttegruppe && gyldigFraDato == other.gyldigFraDato;
}