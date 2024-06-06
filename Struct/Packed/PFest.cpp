//
// Created by sigsegv on 2/18/23.
//

#include <Struct/Packed/PFest.h>
#include <Struct/Packed/Uint16List.h>
#include <FestSerializer.h>

PFest_V_0_0_0::PFest_V_0_0_0(const FestData &festData, Uint16List_V_0_0_0 &uint16List, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        dato(festData.dato, strblock, cache),
        legemiddelMerkevare(uint16List.StoreList(festData.legemiddelMerkevare)),
        legemiddelpakning(uint16List.StoreList(festData.legemiddelpakning)),
        legemiddelVirkestoff(uint16List.StoreList(festData.legemiddelVirkestoff)),
        medForbrMatr(uint16List.StoreList(festData.medForbrMatr)),
        naringsmiddel(uint16List.StoreList(festData.naringsmiddel)),
        brystprotese(uint16List.StoreList(festData.brystprotese)),
        legemiddeldose(uint16List.StoreList(festData.legemiddeldose)),
        virkestoffMedStyrke(uint16List.StoreList(festData.virkestoffMedStyrke)),
        virkestoff(uint16List.StoreList(festData.virkestoff)),
        kodeverk(uint16List.StoreList(festData.kodeverk)),
        refusjon(uint16List.StoreList(festData.refusjon)),
        vilkar(uint16List.StoreList(festData.vilkar)),
        varselSlv(uint16List.StoreList(festData.varselSlv)),
        byttegruppe(uint16List.StoreList(festData.byttegruppe)),
        interaksjon(uint16List.StoreList(festData.interaksjon)),
        interaksjonIkkeVurdert(uint16List.StoreList(festData.interaksjonIkkeVurdert)),
        strDosering(uint16List.StoreList(festData.strDosering))
{
}

PFest::PFest(const PFest_V_0_0_0 &legacy) :
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

PFest::PFest(const FestData &festData, Uint16List &uint16List, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        dato(festData.dato, strblock, cache),
        legemiddelMerkevare(uint16List.StoreList(festData.legemiddelMerkevare)),
        legemiddelpakning(uint16List.StoreList(festData.legemiddelpakning)),
        legemiddelVirkestoff(uint16List.StoreList(festData.legemiddelVirkestoff)),
        medForbrMatr(uint16List.StoreList(festData.medForbrMatr)),
        naringsmiddel(uint16List.StoreList(festData.naringsmiddel)),
        brystprotese(uint16List.StoreList(festData.brystprotese)),
        legemiddeldose(uint16List.StoreList(festData.legemiddeldose)),
        virkestoffMedStyrke(uint16List.StoreList(festData.virkestoffMedStyrke)),
        virkestoff(uint16List.StoreList(festData.virkestoff)),
        kodeverk(uint16List.StoreList(festData.kodeverk)),
        refusjon(uint16List.StoreList(festData.refusjon)),
        vilkar(uint16List.StoreList(festData.vilkar)),
        varselSlv(uint16List.StoreList(festData.varselSlv)),
        byttegruppe(uint16List.StoreList(festData.byttegruppe)),
        interaksjon(uint16List.StoreList(festData.interaksjon)),
        interaksjonIkkeVurdert(uint16List.StoreList(festData.interaksjonIkkeVurdert)),
        strDosering(uint16List.StoreList(festData.strDosering))
{
}