//
// Created by sigsegv on 2/10/23.
//

#include "PByttegruppe.h"
#include "../Decoded/Byttegruppe.h"

PByttegruppe::PByttegruppe(const Byttegruppe &byttegruppe, std::vector<FestUuid> &idblock, std::string &strblock,
                           std::map<std::string, uint32_t> &cache) :
        kode(byttegruppe.kode, strblock, cache),
        gyldigFraDato(byttegruppe.gyldigFraDato, strblock, cache),
        beskrivelseByttbarhet(byttegruppe.beskrivelseByttbarhet, strblock, cache),
        id(byttegruppe.id, idblock),
        merknadTilByttbarhet(byttegruppe.merknadTilByttbarhet)
{
}