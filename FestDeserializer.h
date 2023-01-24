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
#include "Struct/Decoded/ValueUnit.h"
#include "Struct/Decoded/Pakningskomponent.h"
#include "Struct/Decoded/Pakningsinfo.h"
#include "Struct/Decoded/PrisVare.h"
#include "Struct/Decoded/Markedsforingsinfo.h"
#include "Struct/Decoded/PakningByttegruppe.h"
#include "Struct/Packed/PPakningskomponent.h"
#include "Struct/Packed/PPakningsinfo.h"
#include "Struct/Packed/PPrisVare.h"
#include "Struct/Packed/POppfLegemiddelpakning.h"

class FestDeserializer {
private:
    void *mapping;
    size_t mapsize;
    const POppfLegemiddelMerkevare *merkevare;
    const POppfLegemiddelpakning *pakning;
    const FestUuid *festUuid;
    const PFestId *festUuidList;
    const PValueWithCodeset *valueWithCodesetList;
    const PReseptgyldighet *reseptgyldighetList;
    const PPakningskomponent *pakningskomponentList;
    const PPakningsinfo *pakningsinfoList;
    const PPrisVare *prisVareList;
    const char *stringblock;
    size_t numMerkevare;
    size_t numPakning;
    size_t numFestUuid;
    size_t numFestUuidList;
    size_t numValueWithCodesetList;
    size_t numReseptgyldighet;
    size_t numPakningskomponent;
    size_t numPakningsinfo;
    size_t numPrisVare;
    size_t stringblocksize;
public:
    FestDeserializer(const std::string &filename);
    ~FestDeserializer();
    [[nodiscard]] std::vector<PString> GetStrings() const;
    [[nodiscard]] std::vector<PPrisVare> GetPrisVare() const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfo() const;
    [[nodiscard]] std::vector<PPakningskomponent> GetPakningskomponent() const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighet() const;
    [[nodiscard]] std::vector<PValueWithCodeset> GetValueWithCodeset() const;
    [[nodiscard]] std::vector<FestUuid> GetFestIds() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists() const;
    void ForEachMerkevare(const std::function<void (const POppfLegemiddelMerkevare &)> &);
    void ForEachPakning(const std::function<void (const POppfLegemiddelpakning &)> &);
    [[nodiscard]] std::string Unpack(const PString &str) const;
    [[nodiscard]] Reseptgyldighet Unpack(const PReseptgyldighet &reseptgyldighet) const;
    [[nodiscard]] ValueWithDistinguishedName Unpack(const PValueWithDistinguishedName &valueWithDistinguishedName) const;
    [[nodiscard]] ValueWithCodeSet Unpack(const PValueWithCodeset &valueWithCodeset) const;
    [[nodiscard]] ValueUnit Unpack(const PValueUnit &valueUnit) const;
    [[nodiscard]] FestUuid Unpack(PFestId festId) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning &poppf) const;
    [[nodiscard]] Oppf Unpack(const POppf &poppf) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare &pmerkevare) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning &ppakning) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel &pLegemiddel) const;
    [[nodiscard]] LegemiddelCore Unpack(const PLegemiddelCore &pLegemiddelCore) const;
    [[nodiscard]] AdministreringLegemiddel Unpack(const PAdministreringLegemiddel &pAdministreringLegemiddel) const;
    [[nodiscard]] Preparatomtaleavsnitt Unpack(const PPreparatomtaleavsnitt &pPreparatomtaleavsnitt) const;
    [[nodiscard]] Lenke Unpack(const PLenke &lenke) const;
    [[nodiscard]] Pakningskomponent Unpack(const PPakningskomponent &pPakningskomponent) const;
    [[nodiscard]] Pakningsinfo Unpack(const PPakningsinfo &pakningsinfo) const;
    [[nodiscard]] PrisVare Unpack(const PPrisVare &prisVare) const;
    [[nodiscard]] Markedsforingsinfo Unpack(const PMarkedsforingsinfo &pmarkedsforingsinfo) const;
    [[nodiscard]] Refusjon Unpack(const PRefusjon &pRefusjon) const;
    [[nodiscard]] PakningByttegruppe Unpack(const PPakningByttegruppe &pPakningByttegruppe) const;
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
