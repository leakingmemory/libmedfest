//
// Created by sigsegv on 2/18/23.
//

#include <Struct/Packed/PFest.h>
#include <Struct/Packed/Uint16List.h>
#include <Struct/Packed/Uint32List.h>
#include <FestSerializer.h>
#include <FestDeserializer.h>

static std::vector<uint16_t> ClipTo16bit(const std::vector<uint32_t> &src) {
    std::vector<uint16_t> output{};
    for (uint32_t s : src) {
        if (s <= std::numeric_limits<uint16_t>::max()) {
            output.push_back(static_cast<uint16_t>(s));
        }
    }
    return output;
}

PFest_V_0_0_0::PFest_V_0_0_0(const FestData &festData, Uint16List_V_0_0_0 &uint16List, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        dato(festData.dato, strblock, cache),
        legemiddelMerkevare(uint16List.StoreList(ClipTo16bit(festData.legemiddelMerkevare_0_0_0))),
        legemiddelpakning(uint16List.StoreList(ClipTo16bit(festData.legemiddelpakning_0_0_0))),
        legemiddelVirkestoff(uint16List.StoreList(ClipTo16bit(festData.legemiddelVirkestoff_0_0_0))),
        medForbrMatr(uint16List.StoreList(festData.medForbrMatr)),
        naringsmiddel(uint16List.StoreList(festData.naringsmiddel)),
        brystprotese(uint16List.StoreList(festData.brystprotese)),
        legemiddeldose(uint16List.StoreList(ClipTo16bit(festData.legemiddeldose_0_0_0))),
        virkestoffMedStyrke(uint16List.StoreList(festData.virkestoffMedStyrke)),
        virkestoff(uint16List.StoreList(festData.virkestoff)),
        kodeverk(uint16List.StoreList(festData.kodeverk_0_0_0)),
        refusjon(uint16List.StoreList(festData.refusjon)),
        vilkar(uint16List.StoreList(festData.vilkar)),
        varselSlv(uint16List.StoreList(festData.varselSlv)),
        byttegruppe(uint16List.StoreList(festData.byttegruppe)),
        interaksjon(uint16List.StoreList(festData.interaksjon)),
        interaksjonIkkeVurdert(uint16List.StoreList(festData.interaksjonIkkeVurdert)),
        strDosering(uint16List.StoreList(festData.strDosering))
{
}

PFest_V_0_2_0_or_later::PFest_V_0_2_0_or_later(const PFest_V_0_0_0 &legacy) :
dato(legacy.dato),
legemiddelMerkevare(legacy.legemiddelMerkevare.CastToWider<GenericListItems64>()),
legemiddelpakning(legacy.legemiddelpakning.CastToWider<GenericListItems64>()),
legemiddelVirkestoff(legacy.legemiddelVirkestoff.CastToWider<GenericListItems64>()),
medForbrMatr(legacy.medForbrMatr.CastToWider<GenericListItems64>()),
naringsmiddel(legacy.naringsmiddel.CastToWider<GenericListItems64>()),
brystprotese(legacy.brystprotese.CastToWider<GenericListItems64>()),
legemiddeldose(legacy.legemiddeldose.CastToWider<GenericListItems64>()),
virkestoffMedStyrke(legacy.virkestoffMedStyrke.CastToWider<GenericListItems64>()),
virkestoff(legacy.virkestoff.CastToWider<GenericListItems64>()),
kodeverk(legacy.kodeverk.CastToWider<GenericListItems64>()),
refusjon(legacy.refusjon.CastToWider<GenericListItems64>()),
vilkar(legacy.vilkar.CastToWider<GenericListItems64>()),
varselSlv(legacy.varselSlv.CastToWider<GenericListItems64>()),
byttegruppe(legacy.byttegruppe.CastToWider<GenericListItems64>()),
interaksjon(legacy.interaksjon.CastToWider<GenericListItems64>()),
interaksjonIkkeVurdert(legacy.interaksjonIkkeVurdert.CastToWider<GenericListItems64>()),
strDosering(legacy.strDosering.CastToWider<GenericListItems64>())
{
}

PFest_V_0_2_0_or_later::PFest_V_0_2_0_or_later(const FestData &festData, GenericListItems64 legemiddelMerkevare, GenericListItems64 legemiddelpakning, GenericListItems64 legemiddelVirkestoff, GenericListItems64 legemiddeldose, GenericListItems64 kodeverk, Uint16List &uint16List, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        dato(festData.dato, strblock, cache),
        legemiddelMerkevare(legemiddelMerkevare),
        legemiddelpakning(legemiddelpakning),
        legemiddelVirkestoff(legemiddelVirkestoff),
        medForbrMatr(uint16List.StoreList(festData.medForbrMatr)),
        naringsmiddel(uint16List.StoreList(festData.naringsmiddel)),
        brystprotese(uint16List.StoreList(festData.brystprotese)),
        legemiddeldose(legemiddeldose),
        virkestoffMedStyrke(uint16List.StoreList(festData.virkestoffMedStyrke)),
        virkestoff(uint16List.StoreList(festData.virkestoff)),
        kodeverk(kodeverk),
        refusjon(uint16List.StoreList(festData.refusjon)),
        vilkar(uint16List.StoreList(festData.vilkar)),
        varselSlv(uint16List.StoreList(festData.varselSlv)),
        byttegruppe(uint16List.StoreList(festData.byttegruppe)),
        interaksjon(uint16List.StoreList(festData.interaksjon)),
        interaksjonIkkeVurdert(uint16List.StoreList(festData.interaksjonIkkeVurdert)),
        strDosering(uint16List.StoreList(festData.strDosering))
{
}

PFest_V_0_2_0::PFest_V_0_2_0(const PFest_V_0_0_0 &legacy) : PFest_V_0_2_0_or_later(legacy) {
}

PFest_V_0_2_0::PFest_V_0_2_0(const FestData &festData, Uint16List &uint16NewList, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        PFest_V_0_2_0_or_later(
                festData,
                uint16NewList.StoreList(ClipTo16bit(festData.legemiddelMerkevare_0_0_0)),
                uint16NewList.StoreList(ClipTo16bit(festData.legemiddelpakning_0_0_0)),
                uint16NewList.StoreList(ClipTo16bit(festData.legemiddelVirkestoff_0_0_0)),
                uint16NewList.StoreList(ClipTo16bit(festData.legemiddeldose_0_0_0)),
                uint16NewList.StoreList(festData.kodeverk_0_0_0),
                uint16NewList,
                strblock,
                cache
                ){
}

PFest_V_0_3_0::PFest_V_0_3_0(const FestData &festData, Uint32List &uint32List, Uint16List &uint16List, std::string &strblock,
                                      std::map<std::string, uint32_t> &cache) :
        PFest_V_0_2_0_or_later(
                festData,
                uint16List.StoreList(ClipTo16bit(festData.legemiddelMerkevare_0_0_0)),
                uint32List.StoreList(festData.legemiddelpakning_0_0_0),
                uint16List.StoreList(ClipTo16bit(festData.legemiddelVirkestoff_0_0_0)),
                uint16List.StoreList(ClipTo16bit(festData.legemiddeldose_0_0_0)),
                uint16List.StoreList(festData.kodeverk_0_3_0),
                uint16List,
                strblock,
                cache
                ){
}

PFest_V_0_4_0::PFest_V_0_4_0(const PFest_V_0_3_0 &legacy) : PFest_V_0_2_0_or_later(legacy) {}

PFest_V_0_4_0::PFest_V_0_4_0(const FestData &festData, Uint32List &uint32List, Uint16List &uint16List, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        PFest_V_0_2_0_or_later(
                festData,
                uint16List.StoreList(ClipTo16bit(festData.legemiddelMerkevare_0_4_0)),
                uint32List.StoreList(festData.legemiddelpakning_0_4_0),
                uint16List.StoreList(ClipTo16bit(festData.legemiddelVirkestoff_0_4_0)),
                uint16List.StoreList(ClipTo16bit(festData.legemiddeldose_0_4_0)),
                uint16List.StoreList(festData.kodeverk_0_3_0),
                uint16List,
                strblock,
                cache
        ){
}

PFest_V_1_3_0::PFest_V_1_3_0(const PFest_V_0_3_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32List) : PFest_V_0_2_0_or_later(legacy) {
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddelMerkevare);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddelMerkevare = uint32List.StoreList(indices);
    }
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddelVirkestoff);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddelVirkestoff = uint32List.StoreList(indices);
    }
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddeldose);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddeldose = uint32List.StoreList(indices);
    }
}
PFest_V_1_3_0::PFest_V_1_3_0(const PFest_V_0_4_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32List) : PFest_V_0_2_0_or_later(legacy) {
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddelMerkevare);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddelMerkevare = uint32List.StoreList(indices);
    }
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddelVirkestoff);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddelVirkestoff = uint32List.StoreList(indices);
    }
    {
        std::vector<uint32_t> indices{};
        {
            auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                     festDeserializer.numUint16List, legacy.legemiddeldose);
            for (auto index: indices16) {
                indices.emplace_back(index);
            }
        }
        legemiddeldose = uint32List.StoreList(indices);
    }
}

PFest_V_1_3_0::PFest_V_1_3_0(const FestData &festData, Uint32List &uint32List, Uint16List &uint16List, std::string &strblock,
                             std::map<std::string, uint32_t> &cache) :
        PFest_V_0_2_0_or_later(
                festData,
                uint32List.StoreList(festData.legemiddelMerkevare_0_4_0),
                uint32List.StoreList(festData.legemiddelpakning_1_3_0),
                uint32List.StoreList(festData.legemiddelVirkestoff_0_4_0),
                uint32List.StoreList(festData.legemiddeldose_0_4_0),
                uint16List.StoreList(festData.kodeverk_0_3_0),
                uint16List,
                strblock,
                cache
        ){
}

PFest::PFest(const PFest_V_0_0_0 &fest) : std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0>(fest) {}
PFest::PFest(const PFest_V_0_2_0 &fest) : std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0>(fest) {}
PFest::PFest(const PFest_V_0_3_0 &fest) : std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0>(fest) {}
PFest::PFest(const PFest_V_0_4_0 &fest) : std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0>(fest) {}
PFest::PFest(const PFest_V_1_3_0 &fest) : std::variant<PFest_V_0_0_0,PFest_V_0_2_0,PFest_V_0_3_0,PFest_V_0_4_0,PFest_V_1_3_0>(fest) {}
