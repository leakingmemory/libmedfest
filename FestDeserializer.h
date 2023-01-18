//
// Created by sigsegv on 1/13/23.
//

#ifndef LEGEMFEST_FESTDESERIALIZER_H
#define LEGEMFEST_FESTDESERIALIZER_H

#include <string>
#include <functional>
#include <iostream>
#include "Struct/Packed/POppfLegemiddelMerkevare.h"
#include "Struct/Packed/PReseptgyldighet.h"
#include "Struct/Packed/PString.h"
#include "Struct/Decoded/Reseptgyldighet.h"
#include "Struct/Decoded/ValueWithCodeSet.h"

class FestDeserializer {
private:
    void *mapping;
    size_t mapsize;
    const POppfLegemiddelMerkevare *merkevare;
    const FestUuid *festUuid;
    const PFestId *festUuidList;
    const PValueWithCodeset *valueWithCodesetList;
    const PReseptgyldighet *reseptgyldighetList;
    const char *stringblock;
    size_t numMerkevare;
    size_t numFestUuid;
    size_t numFestUuidList;
    size_t numValueWithCodesetList;
    size_t numReseptgyldighet;
    size_t stringblocksize;
public:
    FestDeserializer(const std::string &filename);
    ~FestDeserializer();
    [[nodiscard]] std::vector<PString> GetStrings() const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighet() const;
    [[nodiscard]] std::vector<PValueWithCodeset> GetValueWithCodeset() const;
    [[nodiscard]] std::vector<FestUuid> GetFestIds() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists() const;
    void ForEachMerkevare(const std::function<void (const POppfLegemiddelMerkevare &)> &);
    [[nodiscard]] std::string Unpack(const PString &str) const;
    [[nodiscard]] Reseptgyldighet Unpack(const PReseptgyldighet &reseptgyldighet) const;
    [[nodiscard]] ValueWithDistinguishedName Unpack(const PValueWithDistinguishedName &valueWithDistinguishedName) const;
    [[nodiscard]] ValueWithCodeSet Unpack(const PValueWithCodeset &valueWithCodeset) const;
    [[nodiscard]] FestUuid Unpack(PFestId festId) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare &poppf) const;
    [[nodiscard]] Oppf Unpack(const POppf &poppf) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare &pmerkevare) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel &pLegemiddel) const;
    [[nodiscard]] LegemiddelCore Unpack(const PLegemiddelCore &pLegemiddelCore) const;
    [[nodiscard]] AdministreringLegemiddel Unpack(const PAdministreringLegemiddel &pAdministreringLegemiddel) const;
    [[nodiscard]] Preparatomtaleavsnitt Unpack(const PPreparatomtaleavsnitt &pPreparatomtaleavsnitt) const;
    [[nodiscard]] Lenke Unpack(const PLenke &lenke) const;
    template <typename T, typename S> [[nodiscard]] std::vector<T> Unpack(const T *list, S size, GenericListItems items) const {
        if (items.start < size) {
            std::vector<T> output{};
            S i = items.start;
            typeof(items.size) N = items.size;
            typeof(items.size) n = 0;
            while (i < size && n < N) {
                output.emplace_back(list[i]);
                ++i; ++n;
            }
            if (n < N) {
                std::cerr << "Error: GenericListItems end out of range\n";
            }
            return output;
        } else {
            std::cerr << "Error: GenericListItems start out of range\n";
            return {};
        }
    }
};


#endif //LEGEMFEST_FESTDESERIALIZER_H
