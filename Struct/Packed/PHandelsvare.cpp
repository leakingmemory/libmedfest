//
// Created by sigsegv on 1/29/23.
//

#include "PHandelsvare.h"
#include "PrisVareList.h"
#include "../Decoded/Handelsvare.h"

PHandelsvare::PHandelsvare(const Handelsvare &handelsvare, PrisVareList &prisVareList, StringList &stringList, std::string &strblock) :
        nr(handelsvare.GetNr(), strblock),
        navn(handelsvare.GetNavn(), strblock),
        produktInfoVare(handelsvare.GetProduktInfoVare(), strblock),
        leverandor(handelsvare.GetLeverandor(), strblock),
        prisVare(),
        refusjon(handelsvare.GetRefusjon(), stringList, strblock) {
    std::vector<PPrisVare> prisVare{};
    for (const auto &pv : handelsvare.GetPrisVare()) {
        prisVare.emplace_back(pv, strblock);
    }
    this->prisVare = prisVareList.StoreList(prisVare);
}

PMedForbrMatr::PMedForbrMatr(const MedForbrMatr &medForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::string &strblock) :
        PHandelsvare(medForbrMatr, prisVareList, stringList, strblock) {}

PNaringsmiddel::PNaringsmiddel(const Naringsmiddel &naringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::string &strblock) :
        PHandelsvare(naringsmiddel, prisVareList, stringList, strblock) {}

PBrystprotese::PBrystprotese(const Brystprotese &brystprotese, PrisVareList &prisVareList, StringList &stringList, std::string &strblock) :
        PHandelsvare(brystprotese, prisVareList, stringList, strblock) {}

