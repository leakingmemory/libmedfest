//
// Created by sigsegv on 2/10/23.
//

#include <Struct/Packed/PByttegruppe.h>
#include <Struct/Decoded/Byttegruppe.h>

PByttegruppe::PByttegruppe(const Byttegruppe &byttegruppe, std::vector<FestUuid> &idblock, std::string &strblock,
                           std::map<std::string, uint32_t> &cache) :
        kode(byttegruppe.kode, strblock, cache),
        gyldigFraDato(byttegruppe.gyldigFraDato, strblock, cache),
        beskrivelseByttbarhet(byttegruppe.beskrivelseByttbarhet, strblock, cache),
        id(byttegruppe.id, idblock),
        merknadTilByttbarhet(byttegruppe.merknadTilByttbarhet)
{
}

bool PByttegruppe::operator==(const PByttegruppe &other) const {
    return id == other.id &&
           kode == other.kode &&
           gyldigFraDato == other.gyldigFraDato &&
           beskrivelseByttbarhet == other.beskrivelseByttbarhet &&
           merknadTilByttbarhet == other.merknadTilByttbarhet;
}
