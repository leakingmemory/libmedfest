//
// Created by sigsegv on 2/5/26.
//

#ifndef LIBMEDFEST_FESTHEADERS_H
#define LIBMEDFEST_FESTHEADERS_H

#include "Struct/Packed/packed.h"

constexpr uint8_t alignment = 16;

PACK(struct FestFirstHeader {
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
    uint16_t numRefRefusjonsvilkar_0_0_0;
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
});

PACK(struct FestSecondHeaderV0_1_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
});

PACK(struct FestSecondHeader_0_2_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t reservedZ;
});

PACK(struct FestSecondHeader_0_3_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t numKodeverk;
    uint32_t numElementList;
    uint32_t numTermList;
    uint32_t numUint32List;
    uint32_t numPakning;
});

PACK(struct FestSecondHeader_1_1_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t numKodeverk;
    uint32_t numElementList;
    uint32_t numTermList;
    uint32_t numUint32List;
    uint32_t numPakning_0_3_0;
    uint32_t numPakning_0_4_0;
    uint32_t numMerkevare;
    uint32_t numLegemiddelVirkestoff;
    uint32_t numLegemiddeldose;
    uint32_t numFestUuidList;
    uint32_t numVirkestoff;
    uint32_t numVarselSlv;
});

PACK(struct FestSecondHeader_1_2_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode_0_1_0;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t numKodeverk;
    uint32_t numElementList;
    uint32_t numTermList;
    uint32_t numUint32List;
    uint32_t numPakning_0_3_0;
    uint32_t numPakning_0_4_0;
    uint32_t numMerkevare;
    uint32_t numLegemiddelVirkestoff;
    uint32_t numLegemiddeldose;
    uint32_t numFestUuidList;
    uint32_t numVirkestoff;
    uint32_t numVarselSlv;
    uint16_t numRefRefusjonsvilkar_1_2_0;
    uint16_t numRefusjonskode_1_2_0;
});

PACK(struct FestSecondHeader_1_3_0 {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode_0_1_0;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t numKodeverk;
    uint32_t numElementList;
    uint32_t numTermList;
    uint32_t numUint32List;
    uint32_t numPakning_0_3_0;
    uint32_t numPakning_0_4_0;
    uint32_t numMerkevare;
    uint32_t numLegemiddelVirkestoff;
    uint32_t numLegemiddeldose;
    uint32_t numFestUuidList;
    uint32_t numVirkestoff;
    uint32_t numVarselSlv;
    uint16_t numRefRefusjonsvilkar_1_2_0;
    uint16_t numRefusjonskode_1_2_0;
    uint32_t numPakning_1_3_0;
});

PACK(struct FestSecondHeader {
    uint64_t magic;
    uint32_t stringblockSize;
    uint16_t secondHeaderSize;
    uint16_t numRefusjonskode_0_1_0;
    uint32_t numUint16NewList;
    uint16_t numFests;
    uint16_t numKodeverk;
    uint32_t numElementList;
    uint32_t numTermList;
    uint32_t numUint32List;
    uint32_t numPakning_0_3_0;
    uint32_t numPakning_0_4_0;
    uint32_t numMerkevare;
    uint32_t numLegemiddelVirkestoff;
    uint32_t numLegemiddeldose;
    uint32_t numFestUuidList;
    uint32_t numVirkestoff;
    uint32_t numVarselSlv;
    uint16_t numRefRefusjonsvilkar_1_2_0;
    uint16_t numRefusjonskode_1_2_0;
    uint32_t numPakning_1_3_0;
    uint32_t numRefusjon_1_4_0;
    uint32_t numRefusjonsgruppeList;
});

PACK(struct FestTrailer {
    uint32_t reserved;
    uint32_t secondHeaderOffset;
    uint64_t magic;
});

class FestDeserializer;

#endif //LIBMEDFEST_FESTHEADERS_H