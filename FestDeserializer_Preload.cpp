//
// Created by sigsegv on 2/19/23.
//

#include "FestDeserializer.h"
#include "FestSerializer.h"

template <class T> void PL(std::vector<T> &serializer, const T *deserializer, size_t num) {
    serializer.reserve(num);
    for (typeof(num) i = 0; i < num; i++) {
        serializer.emplace_back(deserializer[i]);
    }
}

class FestDeserializerPreloader {
public:
    template <class List, class P> void Preload(List &list, const P *src, size_t num) {
        auto &listStorage = static_cast<GenericListStorage<P>&>(list);
        auto &vec = listStorage.list;
        PL(vec, src, num);
    }
};

void FestDeserializer::Preload(FestSerializer &festSerializer) {
    festSerializer.stringblock.clear();
    festSerializer.stringblock.append(stringblock, stringblocksize);
    PL(festSerializer.festidblock, festUuid, numFestUuid);
    PL(festSerializer.legemiddelMerkevare, merkevare, numMerkevare);
    PL(festSerializer.legemiddelpakning, pakning, numPakning);
    PL(festSerializer.legemiddelVirkestoff, legemiddelVirkestoff, numLegemiddelVirkestoff);
    PL(festSerializer.medForbrMatr, medForbrMatr, numMedForbrMatr);
    PL(festSerializer.naringsmiddel, naringsmiddel, numNaringsmiddel);
    PL(festSerializer.brystprotese, brystprotese, numBrystprotese);
    PL(festSerializer.legemiddeldose, legemiddeldose, numLegemiddeldose);
    PL(festSerializer.virkestoffMedStyrke, virkestoffMedStyrke, numVirkestoffMedStyrke);
    PL(festSerializer.virkestoff, virkestoff, numVirkestoff);
    PL(festSerializer.kodeverk, kodeverk, numKodeverk);
    PL(festSerializer.refusjon, refusjon, numRefusjon);
    PL(festSerializer.vilkar, vilkar, numVilkar);
    PL(festSerializer.varselSlv, varselSlv, numVarselSlv);
    PL(festSerializer.byttegruppe, byttegruppe, numByttegruppe);
    PL(festSerializer.interaksjon, interaksjon, numInteraksjon);
    PL(festSerializer.interaksjonIkkeVurdert, interaksjonIkkeVurdert, numInteraksjonIkkeVurdert);
    PL(festSerializer.strDosering, strDosering, numStrDosering);
    PL(festSerializer.fests, fests, numFests);
    FestDeserializerPreloader preloader{};
    preloader.Preload(festSerializer.festUuidList, festUuidList, numFestUuidList);
    preloader.Preload(festSerializer.valueWithCodesetList, valueWithCodesetList, numValueWithCodesetList);
    preloader.Preload(festSerializer.reseptgyldighetList, reseptgyldighetList, numReseptgyldighet);
    preloader.Preload(festSerializer.pakningskomponentList, pakningskomponentList, numPakningskomponent);
    preloader.Preload(festSerializer.pakningskomponentInfoList, pakningskomponentInfoList, numPakningskomponentInfo);
    preloader.Preload(festSerializer.pakningsinfoList, pakningsinfoList, numPakningsinfo);
    preloader.Preload(festSerializer.prisVareList, prisVareList, numPrisVare);
    preloader.Preload(festSerializer.refusjonList, refusjonList, numRefusjonList);
    preloader.Preload(festSerializer.elementList, elementList, numElement);
    preloader.Preload(festSerializer.refRefusjonsvilkarList, refRefusjonsvilkarList, numRefRefusjonsvilkar);
    preloader.Preload(festSerializer.refusjonskodeList, refusjonskodeList, numRefusjonskode);
    preloader.Preload(festSerializer.referanseList, referanseList, numReferanseList);
    preloader.Preload(festSerializer.substansgruppeList, substansgruppeList, numSubstansgruppeList);
    preloader.Preload(festSerializer.substansList, substansList, numSubstansList);
    preloader.Preload(festSerializer.doseFastTidspunktList, doseFastTidspunktList, numDoseFastTidspunktList);
    preloader.Preload(festSerializer.doseringList, doseringList, numDoseringList);
    preloader.Preload(festSerializer.legemiddelforbrukList, legemiddelforbrukList, numLegemiddelforbrukList);
    preloader.Preload(festSerializer.uint16List, uint16List, numUint16List);
    preloader.Preload(festSerializer.stringList, stringList, numStringList);
    for (const auto &pstr : GetStrings()) {
        std::string str = Unpack(pstr);
        if (festSerializer.stringblockCache.find(str) == festSerializer.stringblockCache.end()) {
            festSerializer.stringblockCache.insert_or_assign(str, pstr.offset);
        }
    }
}
