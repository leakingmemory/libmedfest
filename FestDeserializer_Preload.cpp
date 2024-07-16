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
    festSerializer.minimumMajorVersion = versionMajor;
    festSerializer.stringblock.clear();
    festSerializer.stringblock.append(stringblock, stringblocksize);
    PL(festSerializer.festidblock, festUuid, numFestUuid);
    PL(festSerializer.legemiddelMerkevare_0_0_0, merkevare_0_0_0, numMerkevare_0_0_0);
    PL(festSerializer.legemiddelpakning_0_0_0, pakning_0_0_0, numPakning_0_0_0);
    PL(festSerializer.legemiddelVirkestoff_0_0_0, legemiddelVirkestoff_0_0_0, numLegemiddelVirkestoff_0_0_0);
    PL(festSerializer.legemiddeldose_0_0_0, legemiddeldose_0_0_0, numLegemiddeldose_0_0_0);
    PL(festSerializer.virkestoff_0_0_0, virkestoff_0_0_0, numVirkestoff_0_0_0);
    PL(festSerializer.varselSlv_0_0_0, varselSlv_0_0_0, numVarselSlv_0_0_0);
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        PL(festSerializer.legemiddelMerkevare_0_4_0, merkevare_0_4_0, numMerkevare_0_4_0);
        PL(festSerializer.legemiddelpakning_0_4_0, pakning_0_4_0, numPakning_0_4_0);
        PL(festSerializer.legemiddelVirkestoff_0_4_0, legemiddelVirkestoff_0_4_0, numLegemiddelVirkestoff_0_4_0);
        PL(festSerializer.legemiddeldose_0_4_0, legemiddeldose_0_4_0, numLegemiddeldose_0_4_0);
        PL(festSerializer.virkestoff_0_4_0, virkestoff_0_4_0, numVirkestoff_0_4_0);
        PL(festSerializer.varselSlv_0_4_0, varselSlv_0_4_0, numVarselSlv_0_4_0);
    } else {
        {
            std::function<POppfLegemiddelMerkevare_0_4_0 (const POppfLegemiddelMerkevare_0_0_0 &)> convert{[this, &festSerializer](const POppfLegemiddelMerkevare_0_0_0 &src) {
                POppfLegemiddelMerkevare_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.legemiddelMerkevare_0_4_0, merkevare_0_0_0, numMerkevare_0_0_0, convert);
        }
        {
            std::function<POppfLegemiddelpakning_0_4_0 (const POppfLegemiddelpakning_0_0_0 &)> convert{[this, &festSerializer](const POppfLegemiddelpakning_0_0_0 &src) {
                POppfLegemiddelpakning_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.legemiddelpakning_0_4_0, pakning_0_0_0, numPakning_0_0_0, convert);
        }
        {
            std::function<POppfLegemiddelVirkestoff_0_4_0 (const POppfLegemiddelVirkestoff_0_0_0 &)> convert{[this, &festSerializer](const POppfLegemiddelVirkestoff_0_0_0 &src) {
                POppfLegemiddelVirkestoff_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.legemiddelVirkestoff_0_4_0, legemiddelVirkestoff_0_0_0, numLegemiddelVirkestoff_0_0_0, convert);
        }
        {
            std::function<POppfLegemiddeldose_0_4_0 (const POppfLegemiddeldose_0_0_0 &)> convert{[](const POppfLegemiddeldose_0_0_0 &src) {
                POppfLegemiddeldose_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.legemiddeldose_0_4_0, legemiddeldose_0_0_0, numLegemiddeldose_0_0_0, convert);
        }
        {
            std::function<POppfVirkestoff_0_4_0 (const POppfVirkestoff_0_0_0 &)> convert{[] (const POppfVirkestoff_0_0_0 &src) -> POppfVirkestoff_0_4_0 {
                POppfVirkestoff_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.virkestoff_0_4_0, virkestoff_0_0_0, numVirkestoff_0_0_0, convert);
        }
        {
            std::function<POppfVarselSlv_0_4_0 (const POppfVarselSlv_0_0_0 &)> convert{[] (const POppfVarselSlv_0_0_0 &src) -> POppfVarselSlv_0_4_0 {
                POppfVarselSlv_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.varselSlv_0_4_0, varselSlv_0_0_0, numVarselSlv_0_0_0, convert);
        }
    }
    PL(festSerializer.medForbrMatr, medForbrMatr, numMedForbrMatr);
    PL(festSerializer.naringsmiddel, naringsmiddel, numNaringsmiddel);
    PL(festSerializer.brystprotese, brystprotese, numBrystprotese);
    PL(festSerializer.virkestoffMedStyrke, virkestoffMedStyrke, numVirkestoffMedStyrke);
    PL(festSerializer.kodeverk_0_0_0, kodeverk_0_0_0, numKodeverk_0_0_0);
    PL(festSerializer.refusjon, refusjon, numRefusjon);
    PL(festSerializer.vilkar, vilkar, numVilkar);
    PL(festSerializer.byttegruppe, byttegruppe, numByttegruppe);
    PL(festSerializer.interaksjon, interaksjon, numInteraksjon);
    PL(festSerializer.interaksjonIkkeVurdert, interaksjonIkkeVurdert, numInteraksjonIkkeVurdert);
    PL(festSerializer.strDosering, strDosering, numStrDosering);
    PL(festSerializer.fests_V_0_0_0, fests_V_0_0_0, numFests_V_0_0_0);
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        PL(festSerializer.fests_V_0_4_0, fests_V_0_4_0, numFests_V_0_4_0);
        PL(festSerializer.fests_V_0_3_0, fests_V_0_3_0, numFests_V_0_3_0);
        PL(festSerializer.fests_V_0_2_0, fests_V_0_2_0, numFests_V_0_2_0);
    } else if (versionMajor > 0 || versionMinor >= 3) {
        {
            std::function<PFest_V_0_4_0 (const PFest_V_0_3_0 &)> convert{[this, &festSerializer](const PFest_V_0_3_0 &src) {
                PFest_V_0_4_0 dst{src};
                return dst;
            }};
            PL(festSerializer.fests_V_0_4_0, fests_V_0_3_0, numFests_V_0_3_0, convert);
        }
        PL(festSerializer.fests_V_0_3_0, fests_V_0_3_0, numFests_V_0_3_0);
        PL(festSerializer.fests_V_0_2_0, fests_V_0_2_0, numFests_V_0_2_0);
    } else if (versionMinor >= 2) {
        {
            std::function<PFest_V_0_4_0 (const PFest_V_0_2_0 &)> convert{[this, &festSerializer](const PFest_V_0_2_0 &src) {
                PFest_V_0_4_0 dst{src, *this, festSerializer.uint32List};
                return dst;
            }};
            PL(festSerializer.fests_V_0_4_0, fests_V_0_2_0, numFests_V_0_2_0, convert);
        }
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
            std::function<PFest_V_0_4_0 (const PFest_V_0_0_0 &)> convert{[this, &festSerializer](const PFest_V_0_0_0 &src) {
                PFest_V_0_4_0 dst{src, *this, festSerializer.uint32List};
                return dst;
            }};
            PL(festSerializer.fests_V_0_4_0, fests_V_0_0_0, numFests_V_0_0_0, convert);
        }
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
    if (versionMajor > 1 || (versionMajor == 1 && versionMinor > 0) || (versionMajor == 0 && versionMinor > 3)) {
        preloader.Preload(festSerializer.festUuidList_0_0_0, festUuidList_0_0_0, numFestUuidList_0_0_0);
        preloader.Preload(festSerializer.festUuidList_0_4_0, festUuidList_0_4_0, numFestUuidList_0_4_0);
    } else {
        preloader.Preload(festSerializer.festUuidList_0_0_0, festUuidList_0_0_0, numFestUuidList_0_0_0);
        preloader.Preload(festSerializer.festUuidList_0_4_0, festUuidList_0_0_0, numFestUuidList_0_0_0);
    }
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
