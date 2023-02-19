//
// Created by sigsegv on 2/18/23.
//

#include "PFest.h"
#include "Uint16List.h"
#include "../../FestSerializer.h"

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