//
// Created by sigsegv on 1/13/23.
//

#ifndef LEGEMFEST_FESTDESERIALIZER_H
#define LEGEMFEST_FESTDESERIALIZER_H

#include <string>
#include "Struct/Packed/POppfLegemiddelMerkevare.h"
#include "Struct/Packed/PReseptgyldighet.h"
#include "Struct/Packed/PString.h"

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
    [[nodiscard]] std::string Unpack(const PString &str) const;
};


#endif //LEGEMFEST_FESTDESERIALIZER_H
