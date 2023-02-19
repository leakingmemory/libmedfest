//
// Created by sigsegv on 1/29/23.
//

#include "PHandelsvare.h"
#include "PrisVareList.h"
#include "../Decoded/Handelsvare.h"

PHandelsvare::PHandelsvare(const Handelsvare &handelsvare, PrisVareList &prisVareList, StringList &stringList,
                           std::string &strblock, std::map<std::string,uint32_t> &cache) :
        nr(handelsvare.GetNr(), strblock, cache),
        navn(handelsvare.GetNavn(), strblock, cache),
        produktInfoVare(handelsvare.GetProduktInfoVare(), strblock, cache),
        leverandor(handelsvare.GetLeverandor(), strblock, cache),
        prisVare(),
        refusjon(handelsvare.GetRefusjon(), stringList, strblock, cache) {
    std::vector<PPrisVare> prisVare{};
    for (const auto &pv : handelsvare.GetPrisVare()) {
        prisVare.emplace_back(pv, strblock, cache);
    }
    this->prisVare = prisVareList.StoreList(prisVare);
}

bool PHandelsvare::operator==(const PHandelsvare &other) const {
    return nr == other.nr &&
           navn == other.navn &&
           produktInfoVare == other.produktInfoVare &&
           leverandor == other.leverandor &&
           prisVare == other.prisVare &&
           refusjon == other.refusjon;
}

PMedForbrMatr::PMedForbrMatr(const MedForbrMatr &medForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(medForbrMatr, prisVareList, stringList, strblock, cache) {}

bool PMedForbrMatr::operator==(const PMedForbrMatr &other) const {
    return PHandelsvare::operator==(other);
}
PNaringsmiddel::PNaringsmiddel(const Naringsmiddel &naringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(naringsmiddel, prisVareList, stringList, strblock, cache) {}

bool PNaringsmiddel::operator==(const PNaringsmiddel &other) const {
    return PHandelsvare::operator==(other);
}

PBrystprotese::PBrystprotese(const Brystprotese &brystprotese, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(brystprotese, prisVareList, stringList, strblock, cache) {}

bool PBrystprotese::operator==(const PBrystprotese &other) const {
    return PHandelsvare::operator==(other);
}
