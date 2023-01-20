//
// Created by sigsegv on 1/19/23.
//

#include "PPakningByttegruppe.h"
#include "../Decoded/PakningByttegruppe.h"

PPakningByttegruppe::PPakningByttegruppe(const PakningByttegruppe &pakningByttegruppe, std::vector<FestUuid> &uuidblock,
                                         std::string &strblock) :
        refByttegruppe(pakningByttegruppe.GetRefByttegruppe(), uuidblock),
        gyldigFraDato(pakningByttegruppe.GetGyldigFraDato(), strblock) {}