//
// Created by sigsegv on 1/9/23.
//

#ifndef LEGEMFEST_FESTSERIALIZER_H
#define LEGEMFEST_FESTSERIALIZER_H

#include "Fest/Fest.h"
#include "Struct/Packed/FestUuid.h"
#include "Struct/Packed/FestUuidList.h"
#include "Struct/Packed/ValueWithCodesetList.h"
#include "Struct/Packed/ReseptgyldighetList.h"
#include "Struct/Packed/POppfLegemiddelMerkevare.h"
#include "Struct/Packed/POppfLegemiddelpakning.h"
#include "Struct/Packed/PakningsinfoList.h"
#include "Struct/Packed/PrisVareList.h"
#include "Struct/Packed/PakningskomponentList.h"
#include <memory>
#include <string>
#include <fstream>

constexpr uint8_t alignment = 16;

struct FestFirstHeader {
    uint32_t numUuids : 24;
    uint8_t numReseptgyldighet;
    uint16_t numLegemiddelMerkevare;
    uint16_t numValueCodeset;
    uint16_t numPakningskomponent;
    uint16_t numPakningsinfo;
    uint16_t numPrisVare;
    uint16_t numUuidLists;
    uint16_t numPakning;
} __attribute__((__packed__));

class FestSerializer : private FestVisitor {
private:
    std::shared_ptr<Fest> fest;
    std::ofstream output;
    std::string stringblock{};
    std::vector<FestUuid> festidblock{};
    FestUuidList festUuidList{festidblock};
    ValueWithCodesetList valueWithCodesetList{};
    ReseptgyldighetList reseptgyldighetList{};
    PakningskomponentList pakningskomponentList{};
    PakningsinfoList pakningsinfoList{};
    PrisVareList prisVareList{};
    std::vector<POppfLegemiddelMerkevare> legemiddelMerkevare{};
    std::vector<POppfLegemiddelpakning> legemiddelpakning{};
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
    bool Visit(const OppfLegemiddelMerkevare &merkevare) override;
    bool Visit(const OppfLegemiddelpakning &pakning) override;
};


#endif //LEGEMFEST_FESTSERIALIZER_H
