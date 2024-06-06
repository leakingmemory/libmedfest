//
// Created by sigsegv on 2/19/23.
//

#include "FestVectors.h"
#include "Struct/Packed/PackException.h"
#include "FestDeserializer.h"

constexpr bool CheckRange(size_t start, size_t size, size_t sizeUuint16List) {
    return start >= sizeUuint16List || size > sizeUuint16List || (start + size) > sizeUuint16List;
}

template <GenericListItems64 PFest::* V> void CheckRange(const PFest &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

template <GenericListItems32 PFest::* V> void CheckRange(const PFest &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

template <GenericListItems32 PFest_V_0_0_0::* V> void CheckRange(const PFest_V_0_0_0 &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

FestVectors::FestVectors(const PFest &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List) :
        fest_V_0_0_0(), fest(fest), isFestV_0_2_0(true),
        dato(dato),
        legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
        legemiddelpakning(&(uint16List[fest.legemiddelpakning.start])),
        legemiddelVirkestoff(&(uint16List[fest.legemiddelVirkestoff.start])),
        medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
        naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
        brystprotese(&(uint16List[fest.brystprotese.start])),
        legemiddeldose(&(uint16List[fest.legemiddeldose.start])),
        virkestoffMedStyrke(&(uint16List[fest.virkestoffMedStyrke.start])),
        virkestoff(&(uint16List[fest.virkestoff.start])),
        kodeverk(&(uint16List[fest.kodeverk.start])),
        refusjon(&(uint16List[fest.refusjon.start])),
        vilkar(&(uint16List[fest.vilkar.start])),
        varselSlv(&(uint16List[fest.varselSlv.start])),
        byttegruppe(&(uint16List[fest.byttegruppe.start])),
        interaksjon(&(uint16List[fest.interaksjon.start])),
        interaksjonIkkeVurdert(&(uint16List[fest.interaksjonIkkeVurdert.start])),
        strDosering(&(uint16List[fest.strDosering.start]))
{
    CheckRange<&PFest::legemiddelMerkevare>(fest, sizeUint16List);
    CheckRange<&PFest::legemiddelpakning>(fest, sizeUint16List);
    CheckRange<&PFest::legemiddelVirkestoff>(fest, sizeUint16List);
    CheckRange<&PFest::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest::legemiddeldose>(fest, sizeUint16List);
    CheckRange<&PFest::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest::strDosering>(fest, sizeUint16List);
}

FestVectors::FestVectors(const PFest_V_0_0_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List) :
    fest_V_0_0_0(fest), fest(), isFestV_0_2_0(false),
    dato(dato),
    legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
    legemiddelpakning(&(uint16List[fest.legemiddelpakning.start])),
    legemiddelVirkestoff(&(uint16List[fest.legemiddelVirkestoff.start])),
    medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
    naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
    brystprotese(&(uint16List[fest.brystprotese.start])),
    legemiddeldose(&(uint16List[fest.legemiddeldose.start])),
    virkestoffMedStyrke(&(uint16List[fest.virkestoffMedStyrke.start])),
    virkestoff(&(uint16List[fest.virkestoff.start])),
    kodeverk(&(uint16List[fest.kodeverk.start])),
    refusjon(&(uint16List[fest.refusjon.start])),
    vilkar(&(uint16List[fest.vilkar.start])),
    varselSlv(&(uint16List[fest.varselSlv.start])),
    byttegruppe(&(uint16List[fest.byttegruppe.start])),
    interaksjon(&(uint16List[fest.interaksjon.start])),
    interaksjonIkkeVurdert(&(uint16List[fest.interaksjonIkkeVurdert.start])),
    strDosering(&(uint16List[fest.strDosering.start]))
{
    CheckRange<&PFest_V_0_0_0::legemiddelMerkevare>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::legemiddelpakning>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::legemiddelVirkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::legemiddeldose>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_0_0::strDosering>(fest, sizeUint16List);
}

std::string FestVectors::GetDato() const {
    return dato;
}

template <typename T> std::vector<T> AsVector(const T *ptr, const GenericListItems64 &items) {
    std::vector<T> result{};
    for (int i = 0; i < items.size; i++) {
        result.push_back(ptr[i]);
    }
    return result;
}

template <typename T> std::vector<T> AsVector(const T *ptr, const GenericListItems32 &items) {
    std::vector<T> result{};
    for (int i = 0; i < items.size; i++) {
        result.push_back(ptr[i]);
    }
    return result;
}

template <typename T, typename I> std::vector<T> AsVector(const std::vector<T> &objects, const std::vector<I> &indices) {
    std::vector<T> result{};
    for (const I &index : indices) {
        if (index < 0 || index >= objects.size()) {
            throw PackException("Index out of range");
        }
        result.push_back(objects[index]);
    }
    return result;
}

#define AsVector(name, listFunc) { \
    if (isFestV_0_2_0) {               \
        auto indices = AsVector(name, fest.name); \
        auto objects = festDeserializer.listFunc(); \
        return AsVector(objects, indices);              \
    } else {\
        auto indices = AsVector(name, fest_V_0_0_0.name); \
        auto objects = festDeserializer.listFunc(); \
        return AsVector(objects, indices);              \
    }\
}

std::vector<POppfLegemiddelMerkevare> FestVectors::GetLegemiddelMerkevare(const FestDeserializer &festDeserializer) const {
    AsVector(legemiddelMerkevare, GetLegemiddelMerkevare);
}

std::vector<POppfLegemiddelpakning> FestVectors::GetLegemiddelPakning(const FestDeserializer &festDeserializer) const {
    AsVector(legemiddelpakning, GetLegemiddelPakning);
}

std::vector<POppfLegemiddelVirkestoff> FestVectors::GetLegemiddelVirkestoff(const FestDeserializer &festDeserializer) const {
    AsVector(legemiddelVirkestoff, GetLegemiddelVirkestoff);
}

std::vector<POppfMedForbrMatr> FestVectors::GetMedForbrMatr(const FestDeserializer &festDeserializer) const {
    AsVector(medForbrMatr, GetMedForbrMatr);
}

std::vector<POppfNaringsmiddel> FestVectors::GetNaringsmiddel(const FestDeserializer &festDeserializer) const {
    AsVector(naringsmiddel, GetNaringsmiddel);
}

std::vector<POppfBrystprotese> FestVectors::GetBrystprotese(const FestDeserializer &festDeserializer) const {
    AsVector(brystprotese, GetBrystprotese);
}

std::vector<POppfLegemiddeldose> FestVectors::GetLegemiddeldose(const FestDeserializer &festDeserializer) const {
    AsVector(legemiddeldose, GetLegemiddeldose);
}

std::vector<POppfVirkestoffMedStyrke> FestVectors::GetVirkestoffMedStyrke(const FestDeserializer &festDeserializer) const {
    AsVector(virkestoffMedStyrke, GetVirkestoffMedStyrke);
}

std::vector<POppfVirkestoff> FestVectors::GetVirkestoff(const FestDeserializer &festDeserializer) const {
    AsVector(virkestoff, GetVirkestoff);
}

std::vector<POppfRefusjon> FestVectors::GetRefusjon(const FestDeserializer &festDeserializer) const {
    AsVector(refusjon, GetOppfRefusjon);
}

std::vector<POppfKodeverk> FestVectors::GetKodeverk(const FestDeserializer &festDeserializer) const {
    AsVector(kodeverk, GetOppfKodeverk);
}
