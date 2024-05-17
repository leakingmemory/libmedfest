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
#include "Struct/Packed/POppfInteraksjon.h"
#include "Struct/Packed/POppfInteraksjonIkkeVurdert.h"
#include "Struct/Packed/PReferanse.h"
#include "Struct/Packed/PSubstansgruppe.h"
#include "Struct/Packed/PSubstans.h"
#include "Struct/Packed/PDoseFastTidspunkt.h"
#include "Struct/Packed/PDosering.h"
#include "Struct/Packed/PLegemiddelforbruk.h"
#include "Struct/Packed/POppfStrDosering.h"
#include "Struct/Packed/PFest.h"

class FestSerializer;

class FestDeserializer {
private:
    void *mapping;
    size_t mapsize;
    int versionMajor;
    int versionMinor;
    int versionPatch;
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
    const POppfInteraksjon *interaksjon;
    const POppfInteraksjonIkkeVurdert *interaksjonIkkeVurdert;
    const POppfStrDosering *strDosering;
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
    const PRefusjonskode_0_0_0 *refusjonskodeList_0_0_0;
    const PRefusjonskode *refusjonskodeList;
    const PReferanse *referanseList;
    const PSubstansgruppe *substansgruppeList;
    const PDoseFastTidspunkt *doseFastTidspunktList;
    const PDosering *doseringList;
    const PLegemiddelforbruk *legemiddelforbrukList;
    const PSubstans *substansList;
    const uint16_t *uint16List;
    const PFest *fests;
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
    size_t numInteraksjon;
    size_t numInteraksjonIkkeVurdert;
    size_t numStrDosering;
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
    size_t numRefusjonskode_0_0_0;
    size_t numRefusjonskode;
    size_t numReferanseList;
    size_t numSubstansgruppeList;
    size_t numSubstansList;
    size_t numDoseFastTidspunktList;
    size_t numDoseringList;
    size_t numLegemiddelforbrukList;
    size_t numUint16List;
    size_t numFests;
    size_t numStringList;
    size_t stringblocksize;
public:
    FestDeserializer(const std::string &filename);
    ~FestDeserializer();
    [[nodiscard]] int GetVersionMajor() const;
    [[nodiscard]] int GetVersionMinor() const;
    [[nodiscard]] int GetVersionPatch() const;
    [[nodiscard]] std::vector<POppfLegemiddelMerkevare> GetLegemiddelMerkevare() const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning> GetLegemiddelPakning() const;
    [[nodiscard]] std::vector<POppfLegemiddelVirkestoff> GetLegemiddelVirkestoff() const;
    [[nodiscard]] std::vector<POppfMedForbrMatr> GetMedForbrMatr() const;
    [[nodiscard]] std::vector<POppfNaringsmiddel> GetNaringsmiddel() const;
    [[nodiscard]] std::vector<POppfBrystprotese> GetBrystprotese() const;
    [[nodiscard]] std::vector<POppfLegemiddeldose> GetLegemiddeldose() const;
    [[nodiscard]] std::vector<POppfVirkestoffMedStyrke> GetVirkestoffMedStyrke() const;
    [[nodiscard]] std::vector<POppfVirkestoff> GetVirkestoff() const;
    [[nodiscard]] std::vector<POppfRefusjon> GetOppfRefusjon() const;
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
    [[nodiscard]] std::vector<PRefusjonskode_0_0_0> GetRefusjonskode_0_0_0() const;
    [[nodiscard]] std::vector<PRefusjonskode> GetRefusjonskode_0_1_0() const;
    [[nodiscard]] std::vector<PRefusjonskode> GetRefusjonskode() const;
    [[nodiscard]] std::vector<PReferanse> GetReferanse() const;
    [[nodiscard]] std::vector<PSubstansgruppe> GetSubstansgruppe() const;
    [[nodiscard]] std::vector<PSubstans> GetSubstans() const;
    [[nodiscard]] std::vector<PDoseFastTidspunkt> GetDoseFastTidspunkt() const;
    [[nodiscard]] std::vector<PDosering> GetDosering() const;
    [[nodiscard]] std::vector<PLegemiddelforbruk> GetLegemiddelforbruk() const;
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
    void ForEachInteraksjon(const std::function<void (const POppfInteraksjon &)> &) const;
    void ForEachInteraksjonIkkeVurdert(const std::function<void (const POppfInteraksjonIkkeVurdert &)> &) const;
    void ForEachStrDosering(const std::function<void (const POppfStrDosering &)> &) const;
    void ForEachFests(const std::function<void (const PFest &)> &) const;
    [[nodiscard]] FestVectors Unpack(const PFest &) const;
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
    [[nodiscard]] OppfInteraksjon Unpack(const POppfInteraksjon &poppf) const;
    [[nodiscard]] OppfInteraksjonIkkeVurdert Unpack(const POppfInteraksjonIkkeVurdert &poppf) const;
    [[nodiscard]] OppfStrDosering Unpack(const POppfStrDosering &poppf) const;
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
    [[nodiscard]] Interaksjon Unpack(const PInteraksjon &pInteraksjon) const;
    [[nodiscard]] InteraksjonIkkeVurdert Unpack(const PInteraksjonIkkeVurdert &pInteraksjonIkkeVurdert) const;
    [[nodiscard]] Kortdose Unpack(const PKortdose &pKortdose) const;
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
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode_0_0_0 &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode &pref) const;
    [[nodiscard]] Refusjonsgruppe Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const;
    [[nodiscard]] StrukturertVilkar Unpack(const PStrukturertVilkar &pStrukturertVilkar) const;
    [[nodiscard]] Referanseelement Unpack(const PReferanseelement &pReferanseelement) const;
    [[nodiscard]] Referanse Unpack(const PReferanse &pReferanse) const;
    [[nodiscard]] Substansgruppe Unpack(const PSubstansgruppe &pSubstansgruppe) const;
    [[nodiscard]] Substans Unpack(const PSubstans &pSubstans) const;
    [[nodiscard]] DoseFastTidspunkt Unpack(const PDoseFastTidspunkt &pDoseFastTidspunkt) const;
    [[nodiscard]] Dosering Unpack(const PDosering &pDosering) const;
    [[nodiscard]] Legemiddelforbruk Unpack(const PLegemiddelforbruk &pLegemiddelforbruk) const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfoList(const PLegemiddelpakning &) const;
    [[nodiscard]] std::vector<FestUuid> GetFestUuids(const GenericListItems &) const;
    template <typename T, typename S> [[nodiscard]] std::vector<T> Unpack(const T *list, S size, const GenericListItems &items) const {
        if (items.start < size) {
            std::vector<T> output{};
            S i = items.start;
            const std::remove_const<typeof(items.size)>::type N = items.size;
            std::remove_const<typeof(items.size)>::type n = 0;
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
    void Preload(FestSerializer &) const;
};


#endif //LEGEMFEST_FESTDESERIALIZER_H
