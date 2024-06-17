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

template <class T, class S> void PL(std::vector<T> &serializer, const S *deserializer, size_t num, const std::function<T (const S &)> &convert) {
    serializer.reserve(num);
    for (typeof(num) i = 0; i < num; i++) {
        T obj = convert(deserializer[i]);
        serializer.emplace_back(obj);
    }
}

class FestDeserializerPreloader {
public:
    template <GenericListStorage32Type List, class P> void Preload(List &list, const P *src, size_t num) {
        auto &listStorage = static_cast<GenericListStorage32<P>&>(list);
        auto &vec = listStorage.list;
        PL(vec, src, num);
    }
    template <GenericListStorage64Type List, class P> void Preload(List &list, const P *src, size_t num) {
        auto &listStorage = static_cast<GenericListStorage64<P>&>(list);
        auto &vec = listStorage.list;
        PL(vec, src, num);
    }
    template <class List, class P, class S> void Preload(List &list, const S *src, size_t num, const std::function<P (const S &)> &convert) {
        auto &listStorage = static_cast<GenericListStorage32<P>&>(list);
        auto &vec = listStorage.list;
        PL(vec, src, num, convert);
    }
};

void FestDeserializer::Preload(FestSerializer &festSerializer) const {
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
    PL(festSerializer.kodeverk_0_0_0, kodeverk_0_0_0, numKodeverk_0_0_0);
    PL(festSerializer.refusjon, refusjon, numRefusjon);
    PL(festSerializer.vilkar, vilkar, numVilkar);
    PL(festSerializer.varselSlv, varselSlv, numVarselSlv);
    PL(festSerializer.byttegruppe, byttegruppe, numByttegruppe);
    PL(festSerializer.interaksjon, interaksjon, numInteraksjon);
    PL(festSerializer.interaksjonIkkeVurdert, interaksjonIkkeVurdert, numInteraksjonIkkeVurdert);
    PL(festSerializer.strDosering, strDosering, numStrDosering);
    PL(festSerializer.fests_V_0_0_0, fests_V_0_0_0, numFests_V_0_0_0);
    if (versionMajor > 0 || versionMinor >= 3) {
        PL(festSerializer.fests_V_0_3_0, fests_V_0_3_0, numFests_V_0_3_0);
        PL(festSerializer.fests_V_0_2_0, fests_V_0_2_0, numFests_V_0_2_0);
    } else if (versionMinor >= 2) {
        {
            std::function<PFest_V_0_3_0 (const PFest_V_0_2_0 &)> convert{[this, &festSerializer](const PFest_V_0_2_0 &src) {
                PFest_V_0_3_0 dst{src, *this, festSerializer.uint32List};
                return dst;
            }};
            PL(festSerializer.fests_V_0_3_0, fests_V_0_2_0, numFests_V_0_2_0, convert);
        }
        PL(festSerializer.fests_V_0_2_0, fests_V_0_2_0, numFests_V_0_2_0);
    } else {
        {
            std::function<PFest_V_0_3_0 (const PFest_V_0_0_0 &)> convert{[this, &festSerializer](const PFest_V_0_0_0 &src) {
                PFest_V_0_3_0 dst{src, *this, festSerializer.uint32List};
                return dst;
            }};
            PL(festSerializer.fests_V_0_3_0, fests_V_0_0_0, numFests_V_0_0_0, convert);
        }
        {
            std::function<PFest_V_0_2_0 (const PFest_V_0_0_0 &)> convert{[](const PFest_V_0_0_0 &src) {
                PFest_V_0_2_0 dst{src};
                return dst;
            }};
            PL(festSerializer.fests_V_0_2_0, fests_V_0_0_0, numFests_V_0_0_0, convert);
        }
    }
    FestDeserializerPreloader preloader{};
    preloader.Preload(festSerializer.festUuidList, festUuidList, numFestUuidList);
    preloader.Preload(festSerializer.valueWithCodesetList, valueWithCodesetList, numValueWithCodesetList);
    preloader.Preload(festSerializer.reseptgyldighetList, reseptgyldighetList, numReseptgyldighet);
    preloader.Preload(festSerializer.pakningskomponentList, pakningskomponentList, numPakningskomponent);
    preloader.Preload(festSerializer.pakningskomponentInfoList, pakningskomponentInfoList, numPakningskomponentInfo);
    preloader.Preload(festSerializer.pakningsinfoList, pakningsinfoList, numPakningsinfo);
    preloader.Preload(festSerializer.prisVareList, prisVareList, numPrisVare);
    preloader.Preload(festSerializer.refusjonList, refusjonList, numRefusjonList);
    preloader.Preload(festSerializer.elementList_0_0_0, elementList_0_0_0, numElement_0_0_0);
    preloader.Preload(festSerializer.elementList_0_3_0, elementList_0_3_0, numElement_0_3_0);
    preloader.Preload(festSerializer.termList, termList, numTerm);
    preloader.Preload(festSerializer.refRefusjonsvilkarList, refRefusjonsvilkarList, numRefRefusjonsvilkar);
    preloader.Preload(static_cast<GenericListStorage32<PRefusjonskode_0_0_0> &>(festSerializer.refusjonskodeList_0_0_0), refusjonskodeList_0_0_0, numRefusjonskode_0_0_0);
    if (versionMajor > 0 || versionMinor >= 1) {
        preloader.Preload(festSerializer.refusjonskodeList, refusjonskodeList, numRefusjonskode);
    } else {
        std::function<PRefusjonskode (const PRefusjonskode_0_0_0 &)> convert{[] (const PRefusjonskode_0_0_0 &src) {
            PRefusjonskode dst{src};
            return dst;
        }};
        preloader.Preload(festSerializer.refusjonskodeList, refusjonskodeList_0_0_0, numRefusjonskode_0_0_0, convert);
    }
    preloader.Preload(festSerializer.referanseList, referanseList, numReferanseList);
    preloader.Preload(festSerializer.substansgruppeList, substansgruppeList, numSubstansgruppeList);
    preloader.Preload(festSerializer.substansList, substansList, numSubstansList);
    preloader.Preload(festSerializer.doseFastTidspunktList, doseFastTidspunktList, numDoseFastTidspunktList);
    preloader.Preload(festSerializer.doseringList, doseringList, numDoseringList);
    preloader.Preload(festSerializer.legemiddelforbrukList, legemiddelforbrukList, numLegemiddelforbrukList);
    preloader.Preload(static_cast<GenericListStorage32<uint16_t> &>(festSerializer.uint16List_V_0_0_0), uint16List_V_0_0_0, numUint16List_V_0_0_0);
    if (versionMajor > 0 || versionMinor >= 2) {
        preloader.Preload(festSerializer.uint16List, uint16List, numUint16List);
    } else {
        preloader.Preload(festSerializer.uint16List, uint16List_V_0_0_0, numUint16List_V_0_0_0);
    }
    if (versionMajor > 0 || versionMinor >= 3) {
        preloader.Preload(festSerializer.uint32List, uint32List, numUint32List);
    }
    preloader.Preload(festSerializer.stringList, stringList, numStringList);
    for (const auto &pstr : GetStrings()) {
        std::string str = Unpack(pstr);
        if (festSerializer.stringblockCache.find(str) == festSerializer.stringblockCache.end()) {
            festSerializer.stringblockCache.insert_or_assign(str, pstr.offset);
        }
    }
    if (versionMajor > 0 || versionMinor >= 3) {
        PL(festSerializer.kodeverk_0_3_0, kodeverk_0_3_0, numKodeverk_0_3_0);
    } else {
        std::function<POppfKodeverk_0_3_0 (const POppfKodeverk_0_0_0 &)> convert{[this, &festSerializer] (const POppfKodeverk_0_0_0 &src) {
            POppfKodeverk_0_3_0 dst{src, *this, festSerializer.elementList_0_3_0, festSerializer.termList, festSerializer.stringblock, festSerializer.stringblockCache};
            return dst;
        }};
        PL(festSerializer.kodeverk_0_3_0, kodeverk_0_0_0, numKodeverk_0_0_0, convert);
    }
}
