//
// Created by sigsegv on 2/19/23.
//

#include "FestVectors.h"
#include "Struct/Packed/PackException.h"
#include "FestDeserializer.h"

constexpr bool CheckRange(size_t start, size_t size, size_t sizeUuint16List) {
    return start >= sizeUuint16List || size > sizeUuint16List || (start + size) > sizeUuint16List;
}

template <GenericListItems64 PFest_V_0_2_0_or_later::* V> void CheckRange(const PFest_V_0_2_0_or_later &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

template <GenericListItems32 PFest_V_0_2_0_or_later::* V> void CheckRange(const PFest_V_0_2_0_or_later &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

template <GenericListItems32 PFest_V_0_0_0::* V> void CheckRange(const PFest_V_0_0_0 &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

FestVectors::FestVectors(const PFest_V_0_2_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List) :
        festV(fest),
        dato(dato),
        legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
        legemiddelMerkevare_1_3_0(nullptr),
        legemiddelpakning_0_0_0(&(uint16List[fest.legemiddelpakning.start])),
        legemiddelpakning_0_3_0(nullptr),
        legemiddelVirkestoff(&(uint16List[fest.legemiddelVirkestoff.start])),
        legemiddelVirkestoff_1_3_0(nullptr),
        medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
        naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
        brystprotese(&(uint16List[fest.brystprotese.start])),
        legemiddeldose(&(uint16List[fest.legemiddeldose.start])),
        legemiddeldose_1_3_0(nullptr),
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
    CheckRange<&PFest_V_0_2_0::legemiddelMerkevare>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::legemiddelpakning>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::legemiddelVirkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::legemiddeldose>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0::strDosering>(fest, sizeUint16List);
}

FestVectors::FestVectors(const PFest_V_0_3_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List) :
        festV(fest),
        dato(dato),
        legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
        legemiddelMerkevare_1_3_0(nullptr),
        legemiddelpakning_0_0_0(nullptr),
        legemiddelpakning_0_3_0(&(uint32List[fest.legemiddelpakning.start])),
        legemiddelVirkestoff(&(uint16List[fest.legemiddelVirkestoff.start])),
        legemiddelVirkestoff_1_3_0(nullptr),
        medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
        naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
        brystprotese(&(uint16List[fest.brystprotese.start])),
        legemiddeldose(&(uint16List[fest.legemiddeldose.start])),
        legemiddeldose_1_3_0(nullptr),
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
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelMerkevare>(static_cast<const PFest_V_0_2_0_or_later &>(fest), sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelpakning>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelVirkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddeldose>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::strDosering>(fest, sizeUint16List);
}

FestVectors::FestVectors(const PFest_V_0_4_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List) :
        festV(fest),
        dato(dato),
        legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
        legemiddelMerkevare_1_3_0(nullptr),
        legemiddelpakning_0_0_0(nullptr),
        legemiddelpakning_0_3_0(&(uint32List[fest.legemiddelpakning.start])),
        legemiddelVirkestoff(&(uint16List[fest.legemiddelVirkestoff.start])),
        legemiddelVirkestoff_1_3_0(nullptr),
        medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
        naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
        brystprotese(&(uint16List[fest.brystprotese.start])),
        legemiddeldose(&(uint16List[fest.legemiddeldose.start])),
        legemiddeldose_1_3_0(nullptr),
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
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelMerkevare>(static_cast<const PFest_V_0_2_0_or_later &>(fest), sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelpakning>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelVirkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddeldose>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::strDosering>(fest, sizeUint16List);
}

FestVectors::FestVectors(const PFest_V_1_3_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List, const uint32_t *uint32List, size_t sizeUint32List) :
        festV(fest),
        dato(dato),
        legemiddelMerkevare(nullptr),
        legemiddelMerkevare_1_3_0(&(uint32List[fest.legemiddelMerkevare.start])),
        legemiddelpakning_0_0_0(nullptr),
        legemiddelpakning_0_3_0(&(uint32List[fest.legemiddelpakning.start])),
        legemiddelVirkestoff(nullptr),
        legemiddelVirkestoff_1_3_0(&(uint32List[fest.legemiddelVirkestoff.start])),
        medForbrMatr(&(uint16List[fest.medForbrMatr.start])),
        naringsmiddel(&(uint16List[fest.naringsmiddel.start])),
        brystprotese(&(uint16List[fest.brystprotese.start])),
        legemiddeldose(nullptr),
        legemiddeldose_1_3_0(&(uint32List[fest.legemiddeldose.start])),
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
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelMerkevare>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelpakning>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddelVirkestoff>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::medForbrMatr>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::naringsmiddel>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::brystprotese>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::legemiddeldose>(fest, sizeUint32List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoffMedStyrke>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::virkestoff>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::kodeverk>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::refusjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::vilkar>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::varselSlv>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::byttegruppe>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjon>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::interaksjonIkkeVurdert>(fest, sizeUint16List);
    CheckRange<&PFest_V_0_2_0_or_later::strDosering>(fest, sizeUint16List);
}

FestVectors::FestVectors(const PFest_V_0_0_0 &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List) :
    festV(fest),
    dato(dato),
    legemiddelMerkevare(&(uint16List[fest.legemiddelMerkevare.start])),
    legemiddelMerkevare_1_3_0(nullptr),
    legemiddelpakning_0_0_0(&(uint16List[fest.legemiddelpakning.start])),
    legemiddelpakning_0_3_0(nullptr),
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

template <typename T> std::vector<T> ItemsAsVector(const T *ptr, const GenericListItems64 &items) {
    std::vector<T> result{};
    for (int i = 0; i < items.size; i++) {
        result.push_back(ptr[i]);
    }
    return result;
}

template <typename T> std::vector<T> ItemsAsVector(const T *ptr, const GenericListItems32 &items) {
    std::vector<T> result{};
    for (int i = 0; i < items.size; i++) {
        result.push_back(ptr[i]);
    }
    return result;
}

template <typename T, typename I> std::vector<T> ObjectsAsVector(const std::vector<T> &objects, const std::vector<I> &indices) {
    std::vector<T> result{};
    for (const I &index : indices) {
        if (index < 0 || index >= objects.size()) {
            throw PackException("Index out of range");
        }
        result.push_back(objects[index]);
    }
    return result;
}

template <typename O, typename T, typename I> std::vector<O> ObjectsAsVector(const std::vector<T> &objects, const std::vector<I> &indices) {
    std::vector<O> result{};
    for (const I &index : indices) {
        if (index < 0 || index >= objects.size()) {
            throw PackException("Index out of range");
        }
        result.push_back(objects[index]);
    }
    return result;
}

#define AsVector(name, listFunc) { \
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {               \
        auto indices = ItemsAsVector(name, std::get<PFest_V_1_3_0>(festV).name); \
        auto objects = festDeserializer.listFunc(); \
        return ObjectsAsVector(objects, indices);              \
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {               \
        auto indices = ItemsAsVector(name, std::get<PFest_V_0_4_0>(festV).name); \
        auto objects = festDeserializer.listFunc(); \
        return ObjectsAsVector(objects, indices);              \
    } else if (std::holds_alternative<PFest_V_0_3_0>(festV)) {               \
        auto indices = ItemsAsVector(name, std::get<PFest_V_0_3_0>(festV).name); \
        auto objects = festDeserializer.listFunc(); \
        return ObjectsAsVector(objects, indices);              \
    } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {               \
        auto indices = ItemsAsVector(name, std::get<PFest_V_0_2_0>(festV).name); \
        auto objects = festDeserializer.listFunc(); \
        return ObjectsAsVector(objects, indices);              \
    } else {\
        auto indices = ItemsAsVector(name, std::get<PFest_V_0_0_0>(festV).name); \
        auto objects = festDeserializer.listFunc(); \
        return ObjectsAsVector(objects, indices);              \
    }\
}

std::vector<POppfLegemiddelMerkevare> FestVectors::GetLegemiddelMerkevare(const FestDeserializer &festDeserializer) const {
    std::vector<POppfLegemiddelMerkevare> oppfs{};
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelMerkevare_1_3_0, std::get<PFest_V_1_3_0>(festV).legemiddelMerkevare);
        auto objects = festDeserializer.GetLegemiddelMerkevare_0_4_0();
        auto intermediate = ObjectsAsVector(objects, indices);
        oppfs.reserve(intermediate.size());
        for (const auto &oppf : intermediate) {
            oppfs.emplace_back(oppf);
        }
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelMerkevare, std::get<PFest_V_0_4_0>(festV).legemiddelMerkevare);
        auto objects = festDeserializer.GetLegemiddelMerkevare_0_4_0();
        auto intermediate = ObjectsAsVector(objects, indices);
        oppfs.reserve(intermediate.size());
        for (const auto &oppf : intermediate) {
            oppfs.emplace_back(oppf);
        }
    } else {
        std::vector<POppfLegemiddelMerkevare_0_0_0> raw{};
        if (std::holds_alternative<PFest_V_0_3_0>(festV)) {
            auto indices = ItemsAsVector(legemiddelMerkevare, std::get<PFest_V_0_3_0>(festV).legemiddelMerkevare);
            auto objects = festDeserializer.GetLegemiddelMerkevare_0_0_0();
            raw = ObjectsAsVector(objects, indices);
        } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {
            auto indices = ItemsAsVector(legemiddelMerkevare, std::get<PFest_V_0_2_0>(festV).legemiddelMerkevare);
            auto objects = festDeserializer.GetLegemiddelMerkevare_0_0_0();
            raw = ObjectsAsVector(objects, indices);
        } else {
            auto indices = ItemsAsVector(legemiddelMerkevare, std::get<PFest_V_0_0_0>(festV).legemiddelMerkevare);
            auto objects = festDeserializer.GetLegemiddelMerkevare_0_0_0();
            raw = ObjectsAsVector(objects, indices);
        }
        oppfs.reserve(raw.size());
        for (const auto &r : raw) {
            oppfs.emplace_back(r);
        }
    }
    return oppfs;
}

std::vector<POppfLegemiddelpakning> FestVectors::GetLegemiddelPakning(const FestDeserializer &festDeserializer) const {
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelpakning_0_3_0, std::get<PFest_V_1_3_0>(festV).legemiddelpakning);
        auto objects = festDeserializer.GetLegemiddelPakning_1_3_0();
        return ObjectsAsVector<POppfLegemiddelpakning>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelpakning_0_3_0, std::get<PFest_V_0_4_0>(festV).legemiddelpakning);
        auto objects = festDeserializer.GetLegemiddelPakning_0_4_0();
        return ObjectsAsVector<POppfLegemiddelpakning>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelpakning_0_3_0, std::get<PFest_V_0_3_0>(festV).legemiddelpakning);
        auto objects = festDeserializer.GetLegemiddelPakning_0_0_0();
        return ObjectsAsVector<POppfLegemiddelpakning>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelpakning_0_0_0, std::get<PFest_V_0_2_0>(festV).legemiddelpakning);
        auto objects = festDeserializer.GetLegemiddelPakning_0_0_0();
        return ObjectsAsVector<POppfLegemiddelpakning>(objects, indices);
    } else {
        auto indices = ItemsAsVector(legemiddelpakning_0_0_0, std::get<PFest_V_0_0_0>(festV).legemiddelpakning);
        auto objects = festDeserializer.GetLegemiddelPakning_0_0_0();
        return ObjectsAsVector<POppfLegemiddelpakning>(objects, indices);
    }
}

std::vector<POppfLegemiddelVirkestoff> FestVectors::GetLegemiddelVirkestoff(const FestDeserializer &festDeserializer) const {
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelVirkestoff_1_3_0, std::get<PFest_V_1_3_0>(festV).legemiddelVirkestoff);
        auto objects = festDeserializer.GetLegemiddelVirkestoff_0_4_0();
        return ObjectsAsVector<POppfLegemiddelVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelVirkestoff, std::get<PFest_V_0_4_0>(festV).legemiddelVirkestoff);
        auto objects = festDeserializer.GetLegemiddelVirkestoff_0_4_0();
        return ObjectsAsVector<POppfLegemiddelVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelVirkestoff, std::get<PFest_V_0_3_0>(festV).legemiddelVirkestoff);
        auto objects = festDeserializer.GetLegemiddelVirkestoff_0_0_0();
        return ObjectsAsVector<POppfLegemiddelVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {
        auto indices = ItemsAsVector(legemiddelVirkestoff, std::get<PFest_V_0_2_0>(festV).legemiddelVirkestoff);
        auto objects = festDeserializer.GetLegemiddelVirkestoff_0_0_0();
        return ObjectsAsVector<POppfLegemiddelVirkestoff>(objects, indices);
    } else {
        auto indices = ItemsAsVector(legemiddelVirkestoff, std::get<PFest_V_0_0_0>(festV).legemiddelVirkestoff);
        auto objects = festDeserializer.GetLegemiddelVirkestoff_0_0_0();
        return ObjectsAsVector<POppfLegemiddelVirkestoff>(objects, indices);
    }
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
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddeldose_1_3_0, std::get<PFest_V_1_3_0>(festV).legemiddeldose);
        auto objects = festDeserializer.GetLegemiddeldose_0_4_0();
        return ObjectsAsVector<POppfLegemiddeldose>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {
        auto indices = ItemsAsVector(legemiddeldose, std::get<PFest_V_0_4_0>(festV).legemiddeldose);
        auto objects = festDeserializer.GetLegemiddeldose_0_4_0();
        return ObjectsAsVector<POppfLegemiddeldose>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_3_0>(festV)) {
        auto indices = ItemsAsVector(legemiddeldose, std::get<PFest_V_0_3_0>(festV).legemiddeldose);
        auto objects = festDeserializer.GetLegemiddeldose_0_0_0();
        return ObjectsAsVector<POppfLegemiddeldose>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {
        auto indices = ItemsAsVector(legemiddeldose, std::get<PFest_V_0_2_0>(festV).legemiddeldose);
        auto objects = festDeserializer.GetLegemiddeldose_0_0_0();
        return ObjectsAsVector<POppfLegemiddeldose>(objects, indices);
    } else {
        auto indices = ItemsAsVector(legemiddeldose, std::get<PFest_V_0_0_0>(festV).legemiddeldose);
        auto objects = festDeserializer.GetLegemiddeldose_0_0_0();
        return ObjectsAsVector<POppfLegemiddeldose>(objects, indices);
    }
}

std::vector<POppfVirkestoffMedStyrke> FestVectors::GetVirkestoffMedStyrke(const FestDeserializer &festDeserializer) const {
    AsVector(virkestoffMedStyrke, GetVirkestoffMedStyrke);
}

std::vector<POppfVirkestoff> FestVectors::GetVirkestoff(const FestDeserializer &festDeserializer) const {
    if (std::holds_alternative<PFest_V_1_3_0>(festV)) {
        auto indices = ItemsAsVector(virkestoff, std::get<PFest_V_1_3_0>(festV).virkestoff);
        auto objects = festDeserializer.GetVirkestoff_0_4_0();
        return ObjectsAsVector<POppfVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_4_0>(festV)) {
        auto indices = ItemsAsVector(virkestoff, std::get<PFest_V_0_4_0>(festV).virkestoff);
        auto objects = festDeserializer.GetVirkestoff_0_4_0();
        return ObjectsAsVector<POppfVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_3_0>(festV)) {
        auto indices = ItemsAsVector(virkestoff, std::get<PFest_V_0_3_0>(festV).virkestoff);
        auto objects = festDeserializer.GetVirkestoff_0_0_0();
        return ObjectsAsVector<POppfVirkestoff>(objects, indices);
    } else if (std::holds_alternative<PFest_V_0_2_0>(festV)) {
        auto indices = ItemsAsVector(virkestoff, std::get<PFest_V_0_2_0>(festV).virkestoff);
        auto objects = festDeserializer.GetVirkestoff_0_0_0();
        return ObjectsAsVector<POppfVirkestoff>(objects, indices);
    } else {
        auto indices = ItemsAsVector(virkestoff, std::get<PFest_V_0_0_0>(festV).virkestoff);
        auto objects = festDeserializer.GetVirkestoff_0_0_0();
        return ObjectsAsVector<POppfVirkestoff>(objects, indices);
    }
}

std::vector<POppfRefusjon_0_0_0> FestVectors::GetRefusjon_0_0_0(const FestDeserializer &festDeserializer) const {
    AsVector(refusjon, GetOppfRefusjon_0_0_0);
}

std::vector<POppfRefusjon_1_4_0> FestVectors::GetRefusjon_1_4_0(const FestDeserializer &festDeserializer) const {
    AsVector(refusjon, GetOppfRefusjon_1_4_0);
}

std::vector<POppfRefusjon> FestVectors::GetRefusjon(const FestDeserializer &festDeserializer) const {
    std::vector<POppfRefusjon> result{};
    if (festDeserializer.GetVersionMajor() > 1 || (festDeserializer.GetVersionMajor() == 1 && festDeserializer.GetVersionMinor() >= 4)) {
        auto raw = GetRefusjon_1_4_0(festDeserializer);
        result.reserve(raw.size());
        for (const auto &r : raw) {
            result.emplace_back(r);
        }
    } else {
        auto raw = GetRefusjon_0_0_0(festDeserializer);
        result.reserve(raw.size());
        for (const auto &r : raw) {
            result.emplace_back(r);
        }
    }
    return result;
}

std::vector<POppfVilkar> FestVectors::GetVilkar(const FestDeserializer &festDeserializer) const {
    AsVector(vilkar, GetOppfVilkar);
}

std::vector<POppfVarselSlv_0_4_0> FestVectors::GetVarselSlv_0_4_0(const FestDeserializer &festDeserializer) const {
    AsVector(varselSlv, GetVarselSlv_0_4_0);
}

std::vector<POppfVarselSlv_0_0_0> FestVectors::GetVarselSlv_0_0_0(const FestDeserializer &festDeserializer) const {
    AsVector(varselSlv, GetVarselSlv_0_0_0);
}

std::vector<POppfVarselSlv> FestVectors::GetVarselSlv(const FestDeserializer &festDeserializer) const {
    std::vector<POppfVarselSlv> result{};
    if (festDeserializer.GetVersionMajor() > 1 ||
        (festDeserializer.GetVersionMajor() == 1 && festDeserializer.GetVersionMinor() > 0) ||
        (festDeserializer.GetVersionMajor() == 0 && festDeserializer.GetVersionMinor() > 3)) {
        auto varselSlvVec = GetVarselSlv_0_4_0(festDeserializer);
        result.reserve(varselSlvVec.size());
        for (const auto &varselSlv : varselSlvVec) {
            result.emplace_back(varselSlv);
        }
    } else {
        auto varselSlvVec = GetVarselSlv_0_0_0(festDeserializer);
        result.reserve(varselSlvVec.size());
        for (const auto &varselSlv : varselSlvVec) {
            result.emplace_back(varselSlv);
        }
    }
    return result;
}

std::vector<POppfKodeverk_0_0_0> FestVectors::GetKodeverk_0_0_0(const FestDeserializer &festDeserializer) const {
    AsVector(kodeverk, GetOppfKodeverk_0_0_0);
}

std::vector<POppfKodeverk_0_3_0> FestVectors::GetKodeverk_0_3_0(const FestDeserializer &festDeserializer) const {
    AsVector(kodeverk, GetOppfKodeverk_0_3_0);
}

std::vector<POppfKodeverk> FestVectors::GetKodeverk(const FestDeserializer &festDeserializer) const {
    std::vector<POppfKodeverk> kodeverk{};
    if (festDeserializer.GetVersionMajor() > 0 || festDeserializer.GetVersionMinor() > 2) {
        auto kodeverk_0_3_0 = GetKodeverk_0_3_0(festDeserializer);
        kodeverk.reserve(kodeverk_0_3_0.size());
        for (const auto &k : kodeverk_0_3_0) {
            kodeverk.emplace_back(k);
        }
    } else {
        auto kodeverk_0_0_0 = GetKodeverk_0_0_0(festDeserializer);
        kodeverk.reserve(kodeverk_0_0_0.size());
        for (const auto &k : kodeverk_0_0_0) {
            kodeverk.emplace_back(k);
        }
    }
    return kodeverk;
}

std::vector<POppfByttegruppe> FestVectors::GetByttegruppe(const FestDeserializer &festDeserializer) const {
    AsVector(byttegruppe, GetByttegruppe);
}

std::vector<POppfInteraksjon> FestVectors::GetInteraksjon(const FestDeserializer &festDeserializer) const {
    AsVector(interaksjon, GetInteraksjon);
}

std::vector <POppfInteraksjonIkkeVurdert> FestVectors::GetInteraksjonIkkeVurdert(const FestDeserializer &festDeserializer) const {
    AsVector(interaksjonIkkeVurdert, GetInteraksjonIkkeVurdert);
}

std::vector<POppfStrDosering> FestVectors::GetStrDosering(const FestDeserializer &festDeserializer) const {
    AsVector(strDosering, GetStrDosering);
}
