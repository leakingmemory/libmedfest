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
#include <memory>
#include <string>
#include <fstream>

constexpr uint8_t alignment = 16;

struct FestFirstHeader {
    uint32_t numUuids : 24;
    uint8_t numReseptgyldighet;
    uint16_t numLegemiddelMerkevare;
    uint16_t numValueCodeset;
    uint32_t numUuidLists : 24;
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
    std::vector<POppfLegemiddelMerkevare> legemiddelMerkevare{};
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
};


#endif //LEGEMFEST_FESTSERIALIZER_H
