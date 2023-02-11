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
#include "Struct/Packed/PRefRefusjonsvilkar.h"
#include "Struct/Packed/PRefusjonskode.h"
#include "Struct/Packed/POppfLegemiddelpakning.h"
#include "Struct/Packed/POppfLegemiddelVirkestoff.h"
#include "Struct/Packed/POppfHandelsvare.h"
#include "Struct/Packed/POppfLegemiddeldose.h"
#include "Struct/Packed/POppfVirkestoffMedStyrke.h"
#include "Struct/Packed/POppfVirkestoff.h"
#include "Struct/Packed/POppfKodeverk.h"
#include "Struct/Packed/POppfRefusjon.h"
#include "Struct/Packed/POppfVilkar.h"
#include "Struct/Packed/PElement.h"
#include "Struct/Packed/POppfVarselSlv.h"
#include "Struct/Packed/POppfByttegruppe.h"

class FestDeserializer {
private:
    void *mapping;
    size_t mapsize;
    const POppfLegemiddelMerkevare *merkevare;
    const POppfLegemiddelpakning *pakning;
    const POppfLegemiddelVirkestoff *legemiddelVirkestoff;
    const POppfMedForbrMatr *medForbrMatr;
    const POppfNaringsmiddel *naringsmiddel;
    const POppfBrystprotese *brystprotese;
    const POppfLegemiddeldose *legemiddeldose;
    const POppfVirkestoffMedStyrke *virkestoffMedStyrke;
    const POppfVirkestoff *virkestoff;
    const POppfKodeverk *kodeverk;
    const POppfRefusjon *refusjon;
    const POppfVilkar *vilkar;
    const POppfVarselSlv *varselSlv;
    const POppfByttegruppe *byttegruppe;
    const FestUuid *festUuid;
    const PFestId *festUuidList;
    const PValueWithCodeset *valueWithCodesetList;
    const PReseptgyldighet *reseptgyldighetList;
    const PPakningskomponent *pakningskomponentList;
    const PPakningskomponentInfo *pakningskomponentInfoList;
    const PPakningsinfo *pakningsinfoList;
    const PPrisVare *prisVareList;
    const PRefusjon *refusjonList;
    const PElement *elementList;
    const PRefRefusjonsvilkar *refRefusjonsvilkarList;
    const PRefusjonskode *refusjonskodeList;
    const PString *stringList;
    const char *stringblock;
    size_t numMerkevare;
    size_t numPakning;
    size_t numLegemiddelVirkestoff;
    size_t numMedForbrMatr;
    size_t numNaringsmiddel;
    size_t numBrystprotese;
    size_t numLegemiddeldose;
    size_t numVirkestoffMedStyrke;
    size_t numVirkestoff;
    size_t numKodeverk;
    size_t numRefusjon;
    size_t numVilkar;
    size_t numVarselSlv;
    size_t numByttegruppe;
    size_t numFestUuid;
    size_t numFestUuidList;
    size_t numValueWithCodesetList;
    size_t numReseptgyldighet;
    size_t numPakningskomponent;
    size_t numPakningskomponentInfo;
    size_t numPakningsinfo;
    size_t numPrisVare;
    size_t numRefusjonList;
    size_t numElement;
    size_t numRefRefusjonsvilkar;
    size_t numRefusjonskode;
    size_t numStringList;
    size_t stringblocksize;
public:
    FestDeserializer(const std::string &filename);
    ~FestDeserializer();
    [[nodiscard]] std::vector<PString> GetStrings() const;
    [[nodiscard]] std::vector<PPrisVare> GetPrisVare() const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfo() const;
    [[nodiscard]] std::vector<PPakningskomponent> GetPakningskomponent() const;
    [[nodiscard]] std::vector<PPakningskomponentInfo> GetPakningskomponentInfo() const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighet() const;
    [[nodiscard]] std::vector<PValueWithCodeset> GetValueWithCodeset() const;
    [[nodiscard]] std::vector<FestUuid> GetFestIds() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists() const;
    [[nodiscard]] std::vector<PRefusjon> GetRefusjon() const;
    [[nodiscard]] std::vector<PElement> GetElement() const;
    [[nodiscard]] std::vector<PRefRefusjonsvilkar> GetRefRefusjonsvilkar() const;
    [[nodiscard]] std::vector<PRefusjonskode> GetRefusjonskode() const;
    [[nodiscard]] std::vector<PString> GetStringList() const;
    void ForEachMerkevare(const std::function<void (const POppfLegemiddelMerkevare &)> &) const;
    void ForEachPakning(const std::function<void (const POppfLegemiddelpakning &)> &) const;
    void ForEachLegemiddelVirkestoff(const std::function<void (const POppfLegemiddelVirkestoff &)> &) const;
    void ForEachMedForbrMatr(const std::function<void (const POppfMedForbrMatr &)> &) const;
    void ForEachNaringsmiddel(const std::function<void (const POppfNaringsmiddel &)> &) const;
    void ForEachBrystprotese(const std::function<void (const POppfBrystprotese &)> &) const;
    void ForEachLegemiddeldose(const std::function<void (const POppfLegemiddeldose &)> &) const;
    void ForEachVirkestoffMedStyrke(const std::function<void (const POppfVirkestoffMedStyrke &)> &) const;
    void ForEachVirkestoff(const std::function<void (const POppfVirkestoff &)> &) const;
    void ForEachKodeverk(const std::function<void (const POppfKodeverk &)> &) const;
    void ForEachRefusjon(const std::function<void (const POppfRefusjon &)> &) const;
    void ForEachVilkar(const std::function<void (const POppfVilkar &)> &) const;
    void ForEachVarselSlv(const std::function<void (const POppfVarselSlv &)> &) const;
    void ForEachByttegruppe(const std::function<void (const POppfByttegruppe &)> &) const;
    [[nodiscard]] std::string Unpack(const PString &str) const;
    [[nodiscard]] Reseptgyldighet Unpack(const PReseptgyldighet &reseptgyldighet) const;
    [[nodiscard]] ValueWithDistinguishedName Unpack(const PValueWithDistinguishedName &valueWithDistinguishedName) const;
    [[nodiscard]] ValueWithCodeSet Unpack(const PValueWithCodeset &valueWithCodeset) const;
    [[nodiscard]] ValueUnit Unpack(const PValueUnit &valueUnit) const;
    [[nodiscard]] FestUuid Unpack(PFestId festId) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning &poppf) const;
    [[nodiscard]] OppfLegemiddelVirkestoff Unpack(const POppfLegemiddelVirkestoff &poppf) const;
    [[nodiscard]] OppfMedForbrMatr Unpack(const POppfMedForbrMatr &poppf) const;
    [[nodiscard]] OppfNaringsmiddel Unpack(const POppfNaringsmiddel &poppf) const;
    [[nodiscard]] OppfBrystprotese Unpack(const POppfBrystprotese &poppf) const;
    [[nodiscard]] OppfLegemiddeldose Unpack(const POppfLegemiddeldose &poppf) const;
    [[nodiscard]] OppfVirkestoffMedStyrke Unpack(const POppfVirkestoffMedStyrke &poppf) const;
    [[nodiscard]] OppfVirkestoff Unpack(const POppfVirkestoff &poppf) const;
    [[nodiscard]] OppfKodeverk Unpack(const POppfKodeverk &poppf) const;
    [[nodiscard]] OppfRefusjon Unpack(const POppfRefusjon &poppf) const;
    [[nodiscard]] OppfVilkar Unpack(const POppfVilkar &poppf) const;
    [[nodiscard]] OppfVarselSlv Unpack(const POppfVarselSlv &poppf) const;
    [[nodiscard]] OppfByttegruppe Unpack(const POppfByttegruppe &poppf) const;
    [[nodiscard]] Oppf Unpack(const POppf &poppf) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare &pmerkevare) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning &ppakning) const;
    [[nodiscard]] LegemiddelVirkestoff Unpack(const PLegemiddelVirkestoff &pvirkestoff) const;
    [[nodiscard]] Handelsvare Unpack(const PHandelsvare &pHandelsvare) const;
    [[nodiscard]] Legemiddeldose Unpack(const PLegemiddeldose &pLegemiddeldose) const;
    [[nodiscard]] VirkestoffMedStyrke Unpack(const PVirkestoffMedStyrke &pVirkestoffMedStyrke) const;
    [[nodiscard]] Virkestoff Unpack(const PVirkestoff &pVirkestoff) const;
    [[nodiscard]] Info Unpack(const PInfo &pInfo) const;
    [[nodiscard]] Refusjonshjemmel Unpack(const PRefusjonshjemmel &pRefusjonshjemmel) const;
    [[nodiscard]] Vilkar Unpack(const PVilkar &pVilkar) const;
    [[nodiscard]] VarselSlv Unpack(const PVarselSlv &pVarselSlv) const;
    [[nodiscard]] Byttegruppe Unpack(const PByttegruppe &pByttegruppe) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel &pLegemiddel) const;
    [[nodiscard]] LegemiddelCore Unpack(const PLegemiddelCore &pLegemiddelCore) const;
    [[nodiscard]] AdministreringLegemiddel Unpack(const PAdministreringLegemiddel &pAdministreringLegemiddel) const;
    [[nodiscard]] Preparatomtaleavsnitt Unpack(const PPreparatomtaleavsnitt &pPreparatomtaleavsnitt) const;
    [[nodiscard]] Lenke Unpack(const PLenke &lenke) const;
    [[nodiscard]] Pakningskomponent Unpack(const PPakningskomponent &pPakningskomponent) const;
    [[nodiscard]] PakningskomponentInfo Unpack(const PPakningskomponentInfo &pPakningskomponentInfo) const;
    [[nodiscard]] Pakningsinfo Unpack(const PPakningsinfo &pakningsinfo) const;
    [[nodiscard]] PrisVare Unpack(const PPrisVare &prisVare) const;
    [[nodiscard]] Markedsforingsinfo Unpack(const PMarkedsforingsinfo &pmarkedsforingsinfo) const;
    [[nodiscard]] Refusjon Unpack(const PRefusjon &pRefusjon) const;
    [[nodiscard]] PakningByttegruppe Unpack(const PPakningByttegruppe &pPakningByttegruppe) const;
    [[nodiscard]] ProduktInfoVare Unpack(const PProduktInfoVare &pProduktInfoVare) const;
    [[nodiscard]] Leverandor Unpack(const PLeverandor &pLeverandor) const;
    [[nodiscard]] Element Unpack(const PElement &pElement) const;
    [[nodiscard]] Term Unpack(const PTerm &pTerm) const;
    [[nodiscard]] RefRefusjonsvilkar Unpack(const PRefRefusjonsvilkar &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode &pref) const;
    [[nodiscard]] Refusjonsgruppe Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const;
    [[nodiscard]] StrukturertVilkar Unpack(const PStrukturertVilkar &pStrukturertVilkar) const;
    [[nodiscard]] Referanseelement Unpack(const PReferanseelement &pReferanseelement) const;
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
