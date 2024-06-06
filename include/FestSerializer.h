//
// Created by sigsegv on 1/9/23.
//

#ifndef LEGEMFEST_FESTSERIALIZER_H
#define LEGEMFEST_FESTSERIALIZER_H

#include "Fest/Fest.h"
#include "Struct/Packed/FestUuid.h"
#include "Struct/Packed/FestUuidList.h"
#include "Struct/Packed/StringList.h"
#include "Struct/Packed/ValueWithCodesetList.h"
#include "Struct/Packed/ReseptgyldighetList.h"
#include "Struct/Packed/POppfLegemiddelMerkevare.h"
#include "Struct/Packed/POppfLegemiddelpakning.h"
#include "Struct/Packed/PakningsinfoList.h"
#include "Struct/Packed/PrisVareList.h"
#include "Struct/Packed/PakningskomponentList.h"
#include "Struct/Packed/PakningskomponentInfoList.h"
#include "Struct/Packed/RefusjonList.h"
#include "Struct/Packed/ElementList.h"
#include "Struct/Packed/RefRefusjonsvilkarList.h"
#include "Struct/Packed/RefusjonskodeList.h"
#include "Struct/Packed/ReferanseList.h"
#include "Struct/Packed/SubstansgruppeList.h"
#include "Struct/Packed/SubstansList.h"
#include "Struct/Packed/DoseFastTidspunktList.h"
#include "Struct/Packed/DoseringList.h"
#include "Struct/Packed/LegemiddelforbrukList.h"
#include "Struct/Packed/POppfLegemiddelVirkestoff.h"
#include "Struct/Packed/POppfHandelsvare.h"
#include "Struct/Packed/POppfLegemiddeldose.h"
#include "Struct/Packed/POppfVirkestoffMedStyrke.h"
#include "Struct/Packed/POppfVirkestoff.h"
#include "Struct/Packed/POppfKodeverk.h"
#include "Struct/Packed/POppfRefusjon.h"
#include "Struct/Packed/POppfVilkar.h"
#include "Struct/Packed/POppfVarselSlv.h"
#include "Struct/Packed/POppfByttegruppe.h"
#include "Struct/Packed/POppfInteraksjon.h"
#include "Struct/Packed/POppfInteraksjonIkkeVurdert.h"
#include "Struct/Packed/POppfStrDosering.h"
#include "Struct/Packed/PackException.h"
#include "Struct/Packed/Uint16List.h"
#include "Struct/Packed/PFest.h"
#include "FestData.h"
#include "DbVersion.h"
#include <memory>
#include <string>
#include <fstream>
#include <map>
#include <functional>

constexpr uint8_t alignment = 16;

struct FestFirstHeader {
    uint64_t magic;
    uint32_t numUuids : 24;
    uint8_t numReseptgyldighet;
    uint16_t numLegemiddelMerkevare;
    uint16_t numValueCodeset;
    uint16_t numPakningskomponent;
    uint16_t numPakningskomponentInfo;
    uint16_t numPakningsinfo;
    uint16_t numPrisVare;
    uint16_t numUuidLists;
    uint16_t numPakning;
    uint16_t numRefusjonList;
    uint16_t numLegemiddelVirkestoff;
    uint16_t numStringList;
    uint16_t numMedForbrMatr;
    uint16_t numNaringsmiddel;
    uint16_t numBrystprotese;
    uint16_t numLegemiddeldose;
    uint16_t numVirkestoffMedStyrke;
    uint16_t numVirkestoff;
    uint16_t numElement;
    uint16_t numKodeverk;
    uint16_t numRefRefusjonsvilkar;
    uint16_t numRefusjonskode_0_0_0;
    uint16_t numRefusjon;
    uint16_t numVilkar;
    uint16_t numVarselSlv;
    uint16_t numByttegruppe;
    uint16_t numReferanseList;
    uint16_t numSubstansgruppeList;
    uint16_t numSubstansList;
    uint16_t numInteraksjon;
    uint16_t numInteraksjonIkkeVurdert;
    uint16_t numDoseFastTidspunktList;
    uint16_t numDoseringList;
    uint16_t numLegemiddelforbrukList;
    uint16_t numStrDosering;
    uint32_t numUint16List : 22;
    uint16_t numFests : 10;
} __attribute__((__packed__));

struct FestSecondHeaderV0_1_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
} __attribute__((__packed__));

struct FestSecondHeader {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t reservedZ;
} __attribute__((__packed__));

struct FestTrailer {
    uint32_t reserved;
    uint32_t secondHeaderOffset;
    uint64_t magic;
} __attribute__((__packed__));

class FestDeserializer;

class FestSerializer : private FestVisitor {
    friend FestDeserializer;
private:
    std::ofstream output;
    std::string stringblock{};
    std::map<std::string,uint32_t> stringblockCache{};
    std::vector<FestUuid> festidblock{};
    FestUuidList festUuidList{festidblock};
    ValueWithCodesetList valueWithCodesetList{};
    ReseptgyldighetList reseptgyldighetList{};
    PakningskomponentList pakningskomponentList{};
    PakningskomponentInfoList pakningskomponentInfoList{};
    PakningsinfoList pakningsinfoList{};
    PrisVareList prisVareList{};
    RefusjonList refusjonList{};
    ElementList elementList{};
    RefRefusjonsvilkarList refRefusjonsvilkarList{};
    RefusjonskodeList_0_0_0 refusjonskodeList_0_0_0{};
    RefusjonskodeList refusjonskodeList{};
    ReferanseList referanseList{};
    SubstansgruppeList substansgruppeList{};
    SubstansList substansList{};
    DoseFastTidspunktList doseFastTidspunktList{};
    DoseringList doseringList{};
    LegemiddelforbrukList legemiddelforbrukList{};
    Uint16List_V_0_0_0 uint16List_V_0_0_0{};
    Uint16List uint16List{};
    StringList stringList{};
    std::vector<POppfLegemiddelMerkevare> legemiddelMerkevare{};
    std::vector<POppfLegemiddelpakning> legemiddelpakning{};
    std::vector<POppfLegemiddelVirkestoff> legemiddelVirkestoff{};
    std::vector<POppfMedForbrMatr> medForbrMatr{};
    std::vector<POppfNaringsmiddel> naringsmiddel{};
    std::vector<POppfBrystprotese> brystprotese{};
    std::vector<POppfLegemiddeldose> legemiddeldose{};
    std::vector<POppfVirkestoffMedStyrke> virkestoffMedStyrke{};
    std::vector<POppfVirkestoff> virkestoff{};
    std::vector<POppfKodeverk> kodeverk{};
    std::vector<POppfRefusjon> refusjon{};
    std::vector<POppfVilkar> vilkar{};
    std::vector<POppfVarselSlv> varselSlv{};
    std::vector<POppfByttegruppe> byttegruppe{};
    std::vector<POppfInteraksjon> interaksjon{};
    std::vector<POppfInteraksjonIkkeVurdert> interaksjonIkkeVurdert{};
    std::vector<POppfStrDosering> strDosering{};
    std::vector<PFest_V_0_0_0> fests_V_0_0_0{};
    std::vector<PFest> fests{};
    std::map<std::string,std::shared_ptr<FestData>> festMap{};
    int percentDone;
public:
    FestSerializer(const std::string &filename);
    FestSerializer(const FestSerializer &) = delete;
    FestSerializer(FestSerializer &&) = delete;
    FestSerializer &operator =(const FestSerializer &) = delete;
    FestSerializer &operator =(FestSerializer &&) = delete;
    bool is_open() {
        return output.is_open();
    }
    bool Serialize(const Fest &fest);
    bool Write();
private:
    template <class T> uint16_t Add(std::vector<T> &list, const T &obj) {
        for (typename std::remove_const<typeof(list.size())>::type i = 0; i < list.size(); i++) {
            if (list[i] == obj) {
                if (i >= (1 << 16)) {
                    throw PackException("List size out of bounds");
                }
                return (uint16_t) i;
            }
        }
        auto sz = list.size();
        list.emplace_back(obj);
        if (sz >= (1 << 16)) {
            throw PackException("List size out of bounds");
        }
        return (uint16_t) sz;
    }
    void Add(const std::string &, const std::function<void (FestData &)> &);

    void Progress(int done, int total) override;
    virtual void ProgressFinished(bool success);
    bool Visit(const std::string &fest, const OppfLegemiddelMerkevare &merkevare) override;
    bool Visit(const std::string &fest, const OppfLegemiddelpakning &pakning) override;
    bool Visit(const std::string &fest, const OppfLegemiddelVirkestoff &virkestoff) override;
    bool Visit(const std::string &fest, const OppfMedForbrMatr &medForbrMatr) override;
    bool Visit(const std::string &fest, const OppfNaringsmiddel &naringsmiddel) override;
    bool Visit(const std::string &fest, const OppfBrystprotese &brystprotese) override;
    bool Visit(const std::string &fest, const OppfLegemiddeldose &legemiddeldose) override;
    bool Visit(const std::string &fest, const OppfVirkestoffMedStyrke &virkestoffMedStyrke) override;
    bool Visit(const std::string &fest, const OppfVirkestoff &virkestoff) override;
    bool Visit(const std::string &fest, const OppfKodeverk &kodeverk) override;
    bool Visit(const std::string &fest, const OppfRefusjon &refusjon) override;
    bool Visit(const std::string &fest, const OppfVilkar &vilkar) override;
    bool Visit(const std::string &fest, const OppfVarselSlv &varselSlv) override;
    bool Visit(const std::string &fest, const OppfByttegruppe &byttegruppe) override;
    bool Visit(const std::string &fest, const OppfInteraksjon &interaksjon) override;
    bool Visit(const std::string &fest, const OppfInteraksjonIkkeVurdert &interaksjonIkkeVurdert) override;
    bool Visit(const std::string &fest, const OppfStrDosering &strDosering) override;
};


#endif //LEGEMFEST_FESTSERIALIZER_H
