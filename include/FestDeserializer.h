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

struct FestDbQuota {
    std::string name{};
    uint64_t total{0};
    uint64_t compatMax{0};
    uint64_t hardMax{0};
};

class FestDeserializer {
    friend PFest_V_0_3_0;
    friend PFest_V_0_4_0;
    friend PFest_V_1_3_0;
private:
    void *mapping;
    size_t mapsize;
    int versionMajor;
    int versionMinor;
    int versionPatch;
    const POppfLegemiddelMerkevare_0_0_0 *merkevare_0_0_0;
    const POppfLegemiddelMerkevare_0_4_0 *merkevare_0_4_0;
    const POppfLegemiddelpakning_0_0_0 *pakning_0_0_0;
    const POppfLegemiddelpakning_0_4_0 *pakning_0_4_0;
    const POppfLegemiddelpakning_1_3_0 *pakning_1_3_0;
    const POppfLegemiddelVirkestoff_0_0_0 *legemiddelVirkestoff_0_0_0;
    const POppfLegemiddelVirkestoff_0_4_0 *legemiddelVirkestoff_0_4_0;
    const POppfMedForbrMatr *medForbrMatr;
    const POppfNaringsmiddel *naringsmiddel;
    const POppfBrystprotese *brystprotese;
    const POppfLegemiddeldose_0_0_0 *legemiddeldose_0_0_0;
    const POppfLegemiddeldose_0_4_0 *legemiddeldose_0_4_0;
    const POppfVirkestoffMedStyrke *virkestoffMedStyrke;
    const POppfVirkestoff_0_0_0 *virkestoff_0_0_0;
    const POppfVirkestoff_0_4_0 *virkestoff_0_4_0;
    const POppfKodeverk_0_0_0 *kodeverk_0_0_0;
    const POppfKodeverk_0_3_0 *kodeverk_0_3_0;
    const POppfRefusjon_0_0_0 *refusjon_0_0_0;
    const POppfRefusjon_1_4_0 *refusjon_1_4_0;
    const POppfVilkar *vilkar;
    const POppfVarselSlv_0_0_0 *varselSlv_0_0_0;
    const POppfVarselSlv_0_4_0 *varselSlv_0_4_0;
    const POppfByttegruppe *byttegruppe;
    const POppfInteraksjon *interaksjon;
    const POppfInteraksjonIkkeVurdert *interaksjonIkkeVurdert;
    const POppfStrDosering *strDosering;
    const FestUuid *festUuid;
    const PFestId *festUuidList_0_0_0;
    const PFestId *festUuidList_0_4_0;
    const PValueWithCodeset *valueWithCodesetList;
    const PReseptgyldighet *reseptgyldighetList;
    const PPakningskomponent *pakningskomponentList;
    const PPakningskomponentInfo *pakningskomponentInfoList;
    const PPakningsinfo *pakningsinfoList;
    const PPrisVare *prisVareList;
    const PRefusjon *refusjonList;
    const PElement_0_0_0 *elementList_0_0_0;
    const PElement_0_3_0 *elementList_0_3_0;
    const PTerm *termList;
    const PRefRefusjonsvilkar_0_0_0 *refRefusjonsvilkarList_0_0_0;
    const PRefRefusjonsvilkar_1_2_0 *refRefusjonsvilkarList_1_2_0;
    const PRefusjonskode_0_0_0 *refusjonskodeList_0_0_0;
    const PRefusjonskode_0_1_0 *refusjonskodeList_0_1_0;
    const PRefusjonskode_1_2_0 *refusjonskodeList_1_2_0;
    const PReferanse *referanseList;
    const PSubstansgruppe *substansgruppeList;
    const PDoseFastTidspunkt *doseFastTidspunktList;
    const PDosering *doseringList;
    const PLegemiddelforbruk *legemiddelforbrukList;
    const PSubstans *substansList;
    const uint16_t *uint16List_V_0_0_0;
    const uint16_t *uint16List;
    const uint32_t *uint32List;
    const PFest_V_0_0_0 *fests_V_0_0_0;
    const PFest_V_0_2_0 *fests_V_0_2_0;
    const PFest_V_0_3_0 *fests_V_0_3_0;
    const PFest_V_0_4_0 *fests_V_0_4_0;
    const PFest_V_1_3_0 *fests_V_1_3_0;
    const PString *stringList;
    const PRefusjonsgruppe *refusjonsgruppeList;
    const char *stringblock;
    size_t numMerkevare_0_0_0;
    size_t numMerkevare_0_4_0;
    size_t numPakning_0_0_0;
    size_t numPakning_0_4_0;
    size_t numPakning_1_3_0;
    size_t numLegemiddelVirkestoff_0_0_0;
    size_t numLegemiddelVirkestoff_0_4_0;
    size_t numMedForbrMatr;
    size_t numNaringsmiddel;
    size_t numBrystprotese;
    size_t numLegemiddeldose_0_0_0;
    size_t numLegemiddeldose_0_4_0;
    size_t numVirkestoffMedStyrke;
    size_t numVirkestoff_0_0_0;
    size_t numVirkestoff_0_4_0;
    size_t numKodeverk_0_0_0;
    size_t numKodeverk_0_3_0;
    size_t numRefusjon_0_0_0;
    size_t numRefusjon_1_4_0;
    size_t numVilkar;
    size_t numVarselSlv_0_0_0;
    size_t numVarselSlv_0_4_0;
    size_t numByttegruppe;
    size_t numInteraksjon;
    size_t numInteraksjonIkkeVurdert;
    size_t numStrDosering;
    size_t numFestUuid;
    size_t numFestUuidList_0_0_0;
    size_t numFestUuidList_0_4_0;
    size_t numValueWithCodesetList;
    size_t numReseptgyldighet;
    size_t numPakningskomponent;
    size_t numPakningskomponentInfo;
    size_t numPakningsinfo;
    size_t numPrisVare;
    size_t numRefusjonList;
    size_t numElement_0_0_0;
    size_t numElement_0_3_0;
    size_t numTerm;
    size_t numRefRefusjonsvilkar_0_0_0;
    size_t numRefRefusjonsvilkar_1_2_0;
    size_t numRefusjonskode_0_0_0;
    size_t numRefusjonskode_0_1_0;
    size_t numRefusjonskode_1_2_0;
    size_t numReferanseList;
    size_t numSubstansgruppeList;
    size_t numSubstansList;
    size_t numDoseFastTidspunktList;
    size_t numDoseringList;
    size_t numLegemiddelforbrukList;
    size_t numUint16List_V_0_0_0;
    size_t numUint16List;
    size_t numUint32List;
    size_t numFests_V_0_0_0;
    size_t numFests_V_0_2_0;
    size_t numFests_V_0_3_0;
    size_t numFests_V_0_4_0;
    size_t numFests_V_1_3_0;
    size_t numStringList;
    size_t numRefusjonsgruppeList;
    size_t stringblocksize;
public:
    FestDeserializer(const std::string &filename);
    FestDeserializer(const void *data, size_t size);
    void Init();
    ~FestDeserializer();
    [[nodiscard]] int GetVersionMajor() const;
    [[nodiscard]] int GetVersionMinor() const;
    [[nodiscard]] int GetVersionPatch() const;
    [[nodiscard]] std::vector<POppfLegemiddelMerkevare_0_0_0> GetLegemiddelMerkevare_0_0_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelMerkevare_0_4_0> GetLegemiddelMerkevare_0_4_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelMerkevare> GetLegemiddelMerkevare() const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning_0_0_0> GetLegemiddelPakning_0_0_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning_0_4_0> GetLegemiddelPakning_0_4_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning_1_3_0> GetLegemiddelPakning_1_3_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelpakning> GetLegemiddelPakning() const;
    [[nodiscard]] std::vector<POppfLegemiddelVirkestoff_0_0_0> GetLegemiddelVirkestoff_0_0_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelVirkestoff_0_4_0> GetLegemiddelVirkestoff_0_4_0() const;
    [[nodiscard]] std::vector<POppfLegemiddelVirkestoff> GetLegemiddelVirkestoff() const;
    [[nodiscard]] std::vector<POppfMedForbrMatr> GetMedForbrMatr() const;
    [[nodiscard]] std::vector<POppfNaringsmiddel> GetNaringsmiddel() const;
    [[nodiscard]] std::vector<POppfBrystprotese> GetBrystprotese() const;
    [[nodiscard]] std::vector<POppfLegemiddeldose_0_0_0> GetLegemiddeldose_0_0_0() const;
    [[nodiscard]] std::vector<POppfLegemiddeldose_0_4_0> GetLegemiddeldose_0_4_0() const;
    [[nodiscard]] std::vector<POppfLegemiddeldose> GetLegemiddeldose() const;
    [[nodiscard]] std::vector<POppfVirkestoffMedStyrke> GetVirkestoffMedStyrke() const;
    [[nodiscard]] std::vector<POppfVirkestoff_0_0_0> GetVirkestoff_0_0_0() const;
    [[nodiscard]] std::vector<POppfVirkestoff_0_4_0> GetVirkestoff_0_4_0() const;
    [[nodiscard]] std::vector<POppfVirkestoff> GetVirkestoff() const;
    [[nodiscard]] std::vector<POppfRefusjon_0_0_0> GetOppfRefusjon_0_0_0() const;
    [[nodiscard]] std::vector<POppfRefusjon_1_4_0> GetOppfRefusjon_1_4_0() const;
    [[nodiscard]] std::vector<POppfRefusjon> GetOppfRefusjon() const;
    [[nodiscard]] std::vector<POppfKodeverk_0_0_0> GetOppfKodeverk_0_0_0() const;
    [[nodiscard]] std::vector<POppfKodeverk_0_3_0> GetOppfKodeverk_0_3_0() const;
    [[nodiscard]] std::vector<PString> GetStrings() const;
    [[nodiscard]] std::vector<PPrisVare> GetPrisVare() const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfo() const;
    [[nodiscard]] std::vector<PPakningskomponent> GetPakningskomponent() const;
    [[nodiscard]] std::vector<PPakningskomponentInfo> GetPakningskomponentInfo() const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighet() const;
    [[nodiscard]] std::vector<PValueWithCodeset> GetValueWithCodeset() const;
    [[nodiscard]] std::vector<FestUuid> GetFestIds() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists_0_0_0() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists_0_4_0() const;
    [[nodiscard]] std::vector<PFestId> GetFestIdLists() const;
    [[nodiscard]] std::vector<PRefusjon> GetRefusjon() const;
    [[nodiscard]] std::vector<PElement_0_0_0> GetElement_0_0_0() const;
    [[nodiscard]] std::vector<PElement_0_3_0> GetElement_0_3_0() const;
    [[nodiscard]] std::vector<PElement> GetElement() const;
    [[nodiscard]] std::vector<PRefRefusjonsvilkar_0_0_0> GetRefRefusjonsvilkar_0_0_0() const;
    [[nodiscard]] std::vector<PRefRefusjonsvilkar_1_2_0> GetRefRefusjonsvilkar_1_2_0() const;
    [[nodiscard]] std::vector<PRefRefusjonsvilkar> GetRefRefusjonsvilkar() const;
    [[nodiscard]] std::vector<PRefusjonskode_0_0_0> GetRefusjonskode_0_0_0() const;
    [[nodiscard]] std::vector<PRefusjonskode_0_1_0> GetRefusjonskode_0_1_0() const;
    [[nodiscard]] std::vector<PRefusjonskode_1_2_0> GetRefusjonskode_1_2_0() const;
    [[nodiscard]] std::vector<PRefusjonskode> GetRefusjonskode() const;
    [[nodiscard]] std::vector<PReferanse> GetReferanse() const;
    [[nodiscard]] std::vector<PSubstansgruppe> GetSubstansgruppe() const;
    [[nodiscard]] std::vector<PSubstans> GetSubstans() const;
    [[nodiscard]] std::vector<PDoseFastTidspunkt> GetDoseFastTidspunkt() const;
    [[nodiscard]] std::vector<PDosering> GetDosering() const;
    [[nodiscard]] std::vector<PLegemiddelforbruk> GetLegemiddelforbruk() const;
    [[nodiscard]] std::vector<PString> GetStringList() const;
    void ForEachMerkevare_0_0_0(const std::function<void (const POppfLegemiddelMerkevare_0_0_0 &)> &) const;
    void ForEachMerkevare_0_4_0(const std::function<void (const POppfLegemiddelMerkevare_0_4_0 &)> &) const;
    void ForEachMerkevare(const std::function<void (const POppfLegemiddelMerkevare &)> &) const;
    void ForEachPakning_0_0_0(const std::function<void (const POppfLegemiddelpakning_0_0_0 &)> &) const;
    void ForEachPakning_0_4_0(const std::function<void (const POppfLegemiddelpakning_0_4_0 &)> &) const;
    void ForEachPakning_1_3_0(const std::function<void (const POppfLegemiddelpakning_1_3_0 &)> &) const;
    void ForEachPakning(const std::function<void (const POppfLegemiddelpakning &)> &) const;
    void ForEachLegemiddelVirkestoff_0_0_0(const std::function<void (const POppfLegemiddelVirkestoff_0_0_0 &)> &) const;
    void ForEachLegemiddelVirkestoff_0_4_0(const std::function<void (const POppfLegemiddelVirkestoff_0_4_0 &)> &) const;
    void ForEachLegemiddelVirkestoff(const std::function<void (const POppfLegemiddelVirkestoff &)> &) const;
    void ForEachMedForbrMatr(const std::function<void (const POppfMedForbrMatr &)> &) const;
    void ForEachNaringsmiddel(const std::function<void (const POppfNaringsmiddel &)> &) const;
    void ForEachBrystprotese(const std::function<void (const POppfBrystprotese &)> &) const;
    void ForEachLegemiddeldose_0_0_0(const std::function<void (const POppfLegemiddeldose_0_0_0 &)> &) const;
    void ForEachLegemiddeldose_0_4_0(const std::function<void (const POppfLegemiddeldose_0_4_0 &)> &) const;
    void ForEachLegemiddeldose(const std::function<void (const POppfLegemiddeldose &)> &) const;
    void ForEachVirkestoffMedStyrke(const std::function<void (const POppfVirkestoffMedStyrke &)> &) const;
    void ForEachVirkestoff_0_0_0(const std::function<void (const POppfVirkestoff_0_0_0 &)> &) const;
    void ForEachVirkestoff_0_4_0(const std::function<void (const POppfVirkestoff_0_4_0 &)> &) const;
    void ForEachVirkestoff(const std::function<void (const POppfVirkestoff &)> &) const;
    void ForEachKodeverk_0_0_0(const std::function<void (const POppfKodeverk_0_0_0 &)> &) const;
    void ForEachKodeverk_0_3_0(const std::function<void (const POppfKodeverk_0_3_0 &)> &) const;
    void ForEachKodeverk(const std::function<void (const POppfKodeverk &)> &) const;
    void ForEachRefusjon_0_0_0(const std::function<void (const POppfRefusjon_0_0_0 &)> &) const;
    void ForEachRefusjon_1_4_0(const std::function<void (const POppfRefusjon_1_4_0 &)> &) const;
    void ForEachRefusjon(const std::function<void (const POppfRefusjon &)> &) const;
    void ForEachVilkar(const std::function<void (const POppfVilkar &)> &) const;
    void ForEachVarselSlv_0_0_0(const std::function<void (const POppfVarselSlv_0_0_0 &)> &) const;
    void ForEachVarselSlv_0_4_0(const std::function<void (const POppfVarselSlv_0_4_0 &)> &) const;
    void ForEachVarselSlv(const std::function<void (const POppfVarselSlv &)> &) const;
    void ForEachByttegruppe(const std::function<void (const POppfByttegruppe &)> &) const;
    void ForEachInteraksjon(const std::function<void (const POppfInteraksjon &)> &) const;
    void ForEachInteraksjonIkkeVurdert(const std::function<void (const POppfInteraksjonIkkeVurdert &)> &) const;
    void ForEachStrDosering(const std::function<void (const POppfStrDosering &)> &) const;
    void ForEachFests_V_0_0_0(const std::function<void (const PFest_V_0_0_0 &)> &) const;
    void ForEachFests_V_0_2_0(const std::function<void (const PFest_V_0_2_0 &)> &) const;
    void ForEachFests_V_0_3_0(const std::function<void (const PFest_V_0_3_0 &)> &) const;
    void ForEachFests_V_0_4_0(const std::function<void (const PFest_V_0_4_0 &)> &) const;
    void ForEachFests_V_1_3_0(const std::function<void (const PFest_V_1_3_0 &)> &) const;
    void ForEachFests(const std::function<void (const PFest &)> &) const;
    [[nodiscard]] FestVectors Unpack(const PFest_V_0_0_0 &) const;
    [[nodiscard]] FestVectors Unpack(const PFest_V_0_2_0 &) const;
    [[nodiscard]] FestVectors Unpack(const PFest_V_0_3_0 &) const;
    [[nodiscard]] FestVectors Unpack(const PFest_V_0_4_0 &) const;
    [[nodiscard]] FestVectors Unpack(const PFest_V_1_3_0 &) const;
    [[nodiscard]] FestVectors Unpack(const PFest &) const;
    [[nodiscard]] std::string Unpack(const PString &str) const;
    [[nodiscard]] Reseptgyldighet Unpack(const PReseptgyldighet &reseptgyldighet) const;
    [[nodiscard]] ValueWithDistinguishedName Unpack(const PValueWithDistinguishedName &valueWithDistinguishedName) const;
    [[nodiscard]] ValueWithCodeSet Unpack(const PValueWithCodeset &valueWithCodeset) const;
    [[nodiscard]] ValueUnit Unpack(const PValueUnit &valueUnit) const;
    [[nodiscard]] FestUuid Unpack(PFestId festId) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare_0_0_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare_0_4_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelMerkevare Unpack(const POppfLegemiddelMerkevare &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning_0_0_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning_0_4_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning_1_3_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelpakning Unpack(const POppfLegemiddelpakning &poppf) const;
    [[nodiscard]] OppfLegemiddelVirkestoff Unpack(const POppfLegemiddelVirkestoff_0_0_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelVirkestoff Unpack(const POppfLegemiddelVirkestoff_0_4_0 &poppf) const;
    [[nodiscard]] OppfLegemiddelVirkestoff Unpack(const POppfLegemiddelVirkestoff &poppf) const;
    [[nodiscard]] OppfMedForbrMatr Unpack(const POppfMedForbrMatr &poppf) const;
    [[nodiscard]] OppfNaringsmiddel Unpack(const POppfNaringsmiddel &poppf) const;
    [[nodiscard]] OppfBrystprotese Unpack(const POppfBrystprotese &poppf) const;
    [[nodiscard]] OppfLegemiddeldose Unpack(const POppfLegemiddeldose_0_0_0 &poppf) const;
    [[nodiscard]] OppfLegemiddeldose Unpack(const POppfLegemiddeldose_0_4_0 &poppf) const;
    [[nodiscard]] OppfLegemiddeldose Unpack(const POppfLegemiddeldose &poppf) const;
    [[nodiscard]] OppfVirkestoffMedStyrke Unpack(const POppfVirkestoffMedStyrke &poppf) const;
    [[nodiscard]] OppfVirkestoff Unpack(const POppfVirkestoff_0_0_0 &poppf) const;
    [[nodiscard]] OppfVirkestoff Unpack(const POppfVirkestoff_0_4_0 &poppf) const;
    [[nodiscard]] OppfVirkestoff Unpack(const POppfVirkestoff &poppf) const;
    [[nodiscard]] OppfKodeverk Unpack(const POppfKodeverk_0_0_0 &poppf) const;
    [[nodiscard]] OppfKodeverk Unpack(const POppfKodeverk_0_3_0 &poppf) const;
    [[nodiscard]] OppfKodeverk Unpack(const POppfKodeverk &poppf) const;
    [[nodiscard]] OppfRefusjon Unpack(const POppfRefusjon_0_0_0 &poppf) const;
    [[nodiscard]] OppfRefusjon Unpack(const POppfRefusjon_1_4_0 &poppf) const;
    [[nodiscard]] OppfRefusjon Unpack(const POppfRefusjon &poppf) const;
    [[nodiscard]] OppfVilkar Unpack(const POppfVilkar &poppf) const;
    [[nodiscard]] OppfVarselSlv Unpack(const POppfVarselSlv_0_0_0 &poppf) const;
    [[nodiscard]] OppfVarselSlv Unpack(const POppfVarselSlv_0_4_0 &poppf) const;
    [[nodiscard]] OppfVarselSlv Unpack(const POppfVarselSlv &poppf) const;
    [[nodiscard]] OppfByttegruppe Unpack(const POppfByttegruppe &poppf) const;
    [[nodiscard]] OppfInteraksjon Unpack(const POppfInteraksjon &poppf) const;
    [[nodiscard]] OppfInteraksjonIkkeVurdert Unpack(const POppfInteraksjonIkkeVurdert &poppf) const;
    [[nodiscard]] OppfStrDosering Unpack(const POppfStrDosering &poppf) const;
    [[nodiscard]] Oppf Unpack(const POppf &poppf) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare_0_0_0 &pmerkevare) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare_0_4_0 &pmerkevare) const;
    [[nodiscard]] LegemiddelMerkevare Unpack(const PLegemiddelMerkevare &pmerkevare) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning_0_0_0 &ppakning) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning_0_4_0 &ppakning) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning_1_3_0 &ppakning) const;
    [[nodiscard]] Legemiddelpakning Unpack(const PLegemiddelpakning &ppakning) const;
    [[nodiscard]] LegemiddelVirkestoff Unpack(const PLegemiddelVirkestoff_0_0_0 &pvirkestoff) const;
    [[nodiscard]] LegemiddelVirkestoff Unpack(const PLegemiddelVirkestoff_0_4_0 &pvirkestoff) const;
    [[nodiscard]] LegemiddelVirkestoff Unpack(const PLegemiddelVirkestoff &pvirkestoff) const;
    [[nodiscard]] Handelsvare Unpack(const PHandelsvare &pHandelsvare) const;
    [[nodiscard]] Legemiddeldose Unpack(const PLegemiddeldose_0_0_0 &pLegemiddeldose) const;
    [[nodiscard]] Legemiddeldose Unpack(const PLegemiddeldose_0_4_0 &pLegemiddeldose) const;
    [[nodiscard]] Legemiddeldose Unpack(const PLegemiddeldose &pLegemiddeldose) const;
    [[nodiscard]] VirkestoffMedStyrke Unpack(const PVirkestoffMedStyrke &pVirkestoffMedStyrke) const;
    [[nodiscard]] Virkestoff Unpack(const PVirkestoff_0_0_0 &pVirkestoff) const;
    [[nodiscard]] Virkestoff Unpack(const PVirkestoff_0_4_0 &pVirkestoff) const;
    [[nodiscard]] Virkestoff Unpack(const PVirkestoff &pVirkestoff) const;
    [[nodiscard]] Info Unpack(const PInfo &pInfo) const;
    [[nodiscard]] Refusjonshjemmel Unpack(const PRefusjonshjemmel_0_0_0 &pRefusjonshjemmel) const;
    [[nodiscard]] Refusjonshjemmel Unpack(const PRefusjonshjemmel_1_4_0 &pRefusjonshjemmel) const;
    [[nodiscard]] Refusjonshjemmel Unpack(const PRefusjonshjemmel &pRefusjonshjemmel) const;
    [[nodiscard]] Vilkar Unpack(const PVilkar &pVilkar) const;
    [[nodiscard]] VarselSlv Unpack(const PVarselSlv_0_0_0 &pVarselSlv) const;
    [[nodiscard]] VarselSlv Unpack(const PVarselSlv_0_4_0 &pVarselSlv) const;
    [[nodiscard]] VarselSlv Unpack(const PVarselSlv &pVarselSlv) const;
    [[nodiscard]] Byttegruppe Unpack(const PByttegruppe &pByttegruppe) const;
    [[nodiscard]] Interaksjon Unpack(const PInteraksjon &pInteraksjon) const;
    [[nodiscard]] InteraksjonIkkeVurdert Unpack(const PInteraksjonIkkeVurdert &pInteraksjonIkkeVurdert) const;
    [[nodiscard]] Kortdose Unpack(const PKortdose &pKortdose) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel_0_0_0 &pLegemiddel) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel_0_4_0 &pLegemiddel) const;
    [[nodiscard]] Legemiddel Unpack(const PLegemiddel &pLegemiddel) const;
    [[nodiscard]] LegemiddelCore Unpack(const PLegemiddelCore_0_0_0 &pLegemiddelCore) const;
    [[nodiscard]] LegemiddelCore Unpack(const PLegemiddelCore_0_4_0 &pLegemiddelCore) const;
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
    [[nodiscard]] Element Unpack(const PElement_0_0_0 &pElement) const;
    [[nodiscard]] Element Unpack(const PElement_0_3_0 &pElement) const;
    [[nodiscard]] Element Unpack(const PElement &pElement) const;
    [[nodiscard]] Term Unpack(const PTerm &pTerm) const;
    [[nodiscard]] RefRefusjonsvilkar Unpack(const PRefRefusjonsvilkar_0_0_0 &pref) const;
    [[nodiscard]] RefRefusjonsvilkar Unpack(const PRefRefusjonsvilkar_1_2_0 &pref) const;
    [[nodiscard]] RefRefusjonsvilkar Unpack(const PRefRefusjonsvilkar &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode_0_0_0 &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode_0_1_0 &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode_1_2_0 &pref) const;
    [[nodiscard]] Refusjonskode Unpack(const PRefusjonskode &pref) const;
    [[nodiscard]] Refusjonsgruppe Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const;
    [[nodiscard]] StrukturertVilkar Unpack(const PStrukturertVilkar &pStrukturertVilkar) const;
    [[nodiscard]] Referanseelement Unpack(const PReferanseelement_0_0_0 &pReferanseelement) const;
    [[nodiscard]] Referanseelement Unpack(const PReferanseelement_0_4_0 &pReferanseelement) const;
    [[nodiscard]] Referanseelement Unpack(const PReferanseelement &pReferanseelement) const;
    [[nodiscard]] Referanse Unpack(const PReferanse &pReferanse) const;
    [[nodiscard]] Substansgruppe Unpack(const PSubstansgruppe &pSubstansgruppe) const;
    [[nodiscard]] Substans Unpack(const PSubstans &pSubstans) const;
    [[nodiscard]] DoseFastTidspunkt Unpack(const PDoseFastTidspunkt &pDoseFastTidspunkt) const;
    [[nodiscard]] Dosering Unpack(const PDosering &pDosering) const;
    [[nodiscard]] Legemiddelforbruk Unpack(const PLegemiddelforbruk &pLegemiddelforbruk) const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfoList(const PLegemiddelpakning_0_0_0 &) const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfoList(const PLegemiddelpakning_0_4_0 &) const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfoList(const PLegemiddelpakning_1_3_0 &) const;
    [[nodiscard]] std::vector<PPakningsinfo> GetPakningsinfoList(const PLegemiddelpakning &) const;
    [[nodiscard]] std::vector<PElement_0_0_0> GetElementList(const POppfKodeverk_0_0_0 &) const;
    [[nodiscard]] std::vector<PElement_0_3_0> GetElementList(const POppfKodeverk_0_3_0 &) const;
    [[nodiscard]] std::vector<PElement> GetElementList(const POppfKodeverk &) const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighetList(const PLegemiddelMerkevare_0_0_0 &) const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighetList(const PLegemiddelMerkevare_0_4_0 &) const;
    [[nodiscard]] std::vector<PReseptgyldighet> GetReseptgyldighetList(const PLegemiddelMerkevare &) const;
    [[nodiscard]] std::vector<FestUuid> GetRefMerkevare(const PLegemiddelVirkestoff &pvirkestoff) const;
    [[nodiscard]] std::vector<FestUuid> GetFestUuids(const GenericListItems32 &) const;
    [[nodiscard]] std::vector<FestUuid> GetFestUuids(const GenericListItems64 &) const;
    [[nodiscard]] std::vector<FestUuid> GetFestUuids(const std::variant<GenericListItems32,GenericListItems64> &) const;
    [[nodiscard]] std::vector<FestDbQuota> GetQuotas() const;
    template <typename T, typename S, GenericListItemType ItemType> [[nodiscard]] std::vector<T> Unpack(const T *list, S size, const ItemType &items) const {
        if (items.start < size) {
            std::vector<T> output{};
            S i = items.start;
            const typename ItemType::int_type N = items.size;
            typename ItemType::int_type n = 0;
            while (i < size && n < N) {
                output.emplace_back(list[i]);
                ++i; ++n;
            }
            if (n < N) {
                std::cerr << "Error: GenericListItems end out of range\n";
            }
            return output;
        } else if (items.start == 0 && items.size == 0) {
            return {};
        } else {
            std::cerr << "Error: GenericListItems start out of range\n";
            return {};
        }
    }
    void Preload(FestSerializer &) const;
};


#endif //LEGEMFEST_FESTDESERIALIZER_H
