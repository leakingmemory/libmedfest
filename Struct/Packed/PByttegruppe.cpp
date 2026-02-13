//
// Created by sigsegv on 2/10/23.
//

#include <Struct/Packed/PByttegruppe.h>
#include <Struct/Decoded/Byttegruppe.h>

PByttegruppe_0_0_0::PByttegruppe_0_0_0(const Byttegruppe &byttegruppe, std::vector<FestUuid> &idblock, std::string &strblock,
                           std::map<std::string, uint32_t> &cache) :
        kode(byttegruppe.kode, strblock, cache),
        gyldigFraDato(byttegruppe.gyldigFraDato, strblock, cache),
        beskrivelseByttbarhet(byttegruppe.beskrivelseByttbarhet, strblock, cache),
        id(byttegruppe.id, idblock),
        merknadTilByttbarhet(byttegruppe.merknadTilByttbarhet)
{
}

PByttegruppe_0_0_0::~PByttegruppe_0_0_0() = default;

bool PByttegruppe_0_0_0::operator==(const PByttegruppe_0_0_0 &other) const {
    return id == other.id &&
           kode == other.kode &&
           gyldigFraDato == other.gyldigFraDato &&
           beskrivelseByttbarhet == other.beskrivelseByttbarhet &&
           merknadTilByttbarhet == other.merknadTilByttbarhet;
}

PByttegruppe_1_5_0::PByttegruppe_1_5_0(const Byttegruppe &byttegruppe, std::vector<FestUuid> &idblock, std::string &strblock,
                           std::map<std::string, uint32_t> &cache) :
        kode(byttegruppe.kode, strblock, cache),
        gyldigFraDato(byttegruppe.gyldigFraDato, strblock, cache),
        gyldigTilDato(byttegruppe.gyldigTilDato, strblock, cache),
        beskrivelseByttbarhet(byttegruppe.beskrivelseByttbarhet, strblock, cache),
        id(byttegruppe.id, idblock),
        merknadTilByttbarhet(byttegruppe.merknadTilByttbarhet)
{
}

PByttegruppe_1_5_0::PByttegruppe_1_5_0(const PByttegruppe_0_0_0 &pbyttegruppe) :
    kode(pbyttegruppe.kode),
    gyldigFraDato(pbyttegruppe.gyldigFraDato),
    gyldigTilDato(),
    beskrivelseByttbarhet(pbyttegruppe.beskrivelseByttbarhet),
    id(pbyttegruppe.id),
    merknadTilByttbarhet(pbyttegruppe.merknadTilByttbarhet)
{
}

PByttegruppe_1_5_0::~PByttegruppe_1_5_0() = default;

bool PByttegruppe_1_5_0::operator==(const PByttegruppe_1_5_0 &other) const {
    return id == other.id &&
           kode == other.kode &&
           gyldigFraDato == other.gyldigFraDato &&
           gyldigTilDato == other.gyldigTilDato &&
           beskrivelseByttbarhet == other.beskrivelseByttbarhet &&
           merknadTilByttbarhet == other.merknadTilByttbarhet;
}

PByttegruppe::~PByttegruppe() = default;

bool PByttegruppe::operator==(const PByttegruppe &other) const {
    struct {
        const PByttegruppe &other;
        bool operator() (const PByttegruppe_0_0_0 &pByttegruppe) const {
            struct {
                const PByttegruppe_0_0_0 &pByttegruppe;
                bool operator() (const PByttegruppe_0_0_0 &other) const {
                    return pByttegruppe == other;
                }
                bool operator() (const PByttegruppe_1_5_0 &other) const {
                    PByttegruppe_1_5_0 upgrade{pByttegruppe};
                    return upgrade == other;
                }
            } visitor{.pByttegruppe = pByttegruppe};
            return std::visit(visitor, other);
        }
        bool operator() (const PByttegruppe_1_5_0 &pByttegruppe) const {
            struct {
                const PByttegruppe_1_5_0 &pByttegruppe;
                bool operator() (const PByttegruppe_0_0_0 &other) const {
                    PByttegruppe_1_5_0 upgrade{other};
                    return pByttegruppe == upgrade;
                }
                bool operator() (const PByttegruppe_1_5_0 &other) const {
                    return pByttegruppe == other;
                }
            } visitor{.pByttegruppe = pByttegruppe};
            return std::visit(visitor, other);
        }
    } self_visitor{.other = other};
    return std::visit(self_visitor, *this);
}
