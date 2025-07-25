//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_FESTVECTORS_H
#define LEGEMFEST_FESTVECTORS_H

#include <string>
#include "Struct/Packed/PFest.h"
#include <variant>

class POppfLegemiddelMerkevare;
class POppfLegemiddelpakning;
class POppfLegemiddelVirkestoff;
class POppfMedForbrMatr;
class POppfNaringsmiddel;
class POppfBrystprotese;
class POppfLegemiddeldose;
class POppfVirkestoffMedStyrke;
class POppfVirkestoff;
class POppfRefusjon_0_0_0;
class POppfRefusjon_1_4_0;
class POppfRefusjon;
class POppfVilkar;
class POppfVarselSlv_0_4_0;
class POppfVarselSlv_0_0_0;
class POppfVarselSlv;
class POppfKodeverk_0_0_0;
class POppfKodeverk_0_3_0;
class POppfKodeverk;
class POppfByttegruppe;
class POppfInteraksjon;
class POppfInteraksjonIkkeVurdert;
class POppfStrDosering;

class FestVectors {
private:
    std::string dato;
    const std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0> festV;
    const uint16_t* legemiddelMerkevare;
    const uint32_t* legemiddelMerkevare_1_3_0;
    const uint16_t* legemiddelpakning_0_0_0;
    const uint32_t* legemiddelpakning_0_3_0;
    const uint16_t* legemiddelVirkestoff;
    const uint32_t* legemiddelVirkestoff_1_3_0;
    const uint16_t* medForbrMatr;
    const uint16_t* naringsmiddel;
    const uint16_t* brystprotese;
    const uint16_t* legemiddeldose;
    const uint32_t* legemiddeldose_1_3_0;
    const uint16_t* virkestoffMedStyrke;
    const uint16_t* virkestoff;
    const uint16_t* kodeverk;
    const uint16_t* refusjon;
    const uint16_t* vilkar;
    const uint16_t* varselSlv;
    const uint16_t* byttegruppe;
    const uint16_t* interaksjon;
    const uint16_t* interaksjonIkkeVurdert;
    const uint16_t* strDosering;
public:
    FestVectors(const PFest_V_0_0_0 &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List);
    FestVectors(const PFest_V_0_2_0 &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List);
    FestVectors(const PFest_V_0_3_0 &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List);
    FestVectors(const PFest_V_0_4_0 &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List);
    FestVectors(const PFest_V_1_3_0 &, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List);
    [[nodiscard]] std::string GetDato() const;
    [[nodiscard]] std::vector<POppfLegemiddelMerkevare> GetLegemiddelMerkevare(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning> GetLegemiddelPakning(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfLegemiddelVirkestoff> GetLegemiddelVirkestoff(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfMedForbrMatr> GetMedForbrMatr(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfNaringsmiddel> GetNaringsmiddel(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfBrystprotese> GetBrystprotese(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfLegemiddeldose> GetLegemiddeldose(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVirkestoffMedStyrke> GetVirkestoffMedStyrke(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVirkestoff> GetVirkestoff(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfRefusjon_0_0_0> GetRefusjon_0_0_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfRefusjon_1_4_0> GetRefusjon_1_4_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfRefusjon> GetRefusjon(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVilkar> GetVilkar(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVarselSlv_0_4_0> GetVarselSlv_0_4_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVarselSlv_0_0_0> GetVarselSlv_0_0_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfVarselSlv> GetVarselSlv(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfKodeverk_0_0_0> GetKodeverk_0_0_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfKodeverk_0_3_0> GetKodeverk_0_3_0(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfKodeverk> GetKodeverk(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfByttegruppe> GetByttegruppe(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfInteraksjon> GetInteraksjon(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfInteraksjonIkkeVurdert> GetInteraksjonIkkeVurdert(const FestDeserializer &) const;
    [[nodiscard]] std::vector<POppfStrDosering> GetStrDosering(const FestDeserializer &) const;
};


#endif //LEGEMFEST_FESTVECTORS_H
