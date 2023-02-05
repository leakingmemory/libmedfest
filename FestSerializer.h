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
#include "Struct/Packed/POppfLegemiddelVirkestoff.h"
#include "Struct/Packed/POppfHandelsvare.h"
#include "Struct/Packed/POppfLegemiddeldose.h"
#include "Struct/Packed/POppfVirkestoffMedStyrke.h"
#include "Struct/Packed/POppfVirkestoff.h"
#include "Struct/Packed/POppfKodeverk.h"
#include <memory>
#include <string>
#include <fstream>
#include <map>

constexpr uint8_t alignment = 16;

struct FestFirstHeader {
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
    uint16_t numRefusjon;
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
} __attribute__((__packed__));

class FestSerializer : private FestVisitor {
private:
    std::shared_ptr<Fest> fest;
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
    StringList stringList{};
    ElementList elementList{};
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
    int percentDone;
public:
    FestSerializer(std::shared_ptr<Fest> fest, const std::string &filename);
    FestSerializer(const FestSerializer &) = delete;
    FestSerializer(FestSerializer &&) = delete;
    FestSerializer &operator =(const FestSerializer &) = delete;
    FestSerializer &operator =(FestSerializer &&) = delete;
    bool is_open() {
        return output.is_open();
    }
    bool Serialize();
    bool Write();
private:
    void Progress(int done, int total) override;
    bool Visit(const OppfLegemiddelMerkevare &merkevare) override;
    bool Visit(const OppfLegemiddelpakning &pakning) override;
    bool Visit(const OppfLegemiddelVirkestoff &virkestoff) override;
    bool Visit(const OppfMedForbrMatr &medForbrMatr) override;
    bool Visit(const OppfNaringsmiddel &naringsmiddel) override;
    bool Visit(const OppfBrystprotese &brystprotese) override;
    bool Visit(const OppfLegemiddeldose &legemiddeldose) override;
    bool Visit(const OppfVirkestoffMedStyrke &virkestoffMedStyrke) override;
    bool Visit(const OppfVirkestoff &virkestoff) override;
    bool Visit(const OppfKodeverk &kodeverk) override;
};


#endif //LEGEMFEST_FESTSERIALIZER_H
