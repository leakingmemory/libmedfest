//
// Created by sigsegv on 2/19/23.
//

#include "FestVectors.h"
#include "Struct/Packed/PackException.h"

constexpr bool CheckRange(size_t start, size_t size, size_t sizeUuint16List) {
    return start >= sizeUuint16List || size > sizeUuint16List || (start + size) > sizeUuint16List;
}

template <GenericListItems PFest::* V> void CheckRange(const PFest &fest, size_t sizeUuint16List) {
    if (CheckRange((fest.*V).start, (fest.*V).size, sizeUuint16List)) {
        throw PackException("Range error with FEST items list");
    }
}

FestVectors::FestVectors(const PFest &fest, const std::string &dato, const uint16_t *uint16List, size_t sizeUint16List) :
    fest(fest),
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

std::string FestVectors::GetDato() const {
    return dato;
}
