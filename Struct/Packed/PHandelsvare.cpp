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

PMedForbrMatr::PMedForbrMatr(const MedForbrMatr &medForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(medForbrMatr, prisVareList, stringList, strblock, cache) {}

PNaringsmiddel::PNaringsmiddel(const Naringsmiddel &naringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(naringsmiddel, prisVareList, stringList, strblock, cache) {}

PBrystprotese::PBrystprotese(const Brystprotese &brystprotese, PrisVareList &prisVareList, StringList &stringList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        PHandelsvare(brystprotese, prisVareList, stringList, strblock, cache) {}

