//
// Created by sigsegv on 1/29/23.
//

#include "POppfHandelsvare.h"
#include "../Decoded/OppfHandelsvare.h"

POppfMedForbrMatr::POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<MedForbrMatr, PMedForbrMatr>(oppfMedForbrMatr, oppfMedForbrMatr.medForbrMatr, prisVareList, stringList, uuidblock, strblock, cache) {}

POppfNaringsmiddel::POppfNaringsmiddel(const OppfNaringsmiddel &oppfNaringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<Naringsmiddel, PNaringsmiddel>(oppfNaringsmiddel, oppfNaringsmiddel.naringsmiddel, prisVareList, stringList, uuidblock, strblock, cache) {}

POppfBrystprotese::POppfBrystprotese(const OppfBrystprotese &oppfBrystprotese, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<Brystprotese, PBrystprotese>(oppfBrystprotese, oppfBrystprotese.brystprotese, prisVareList, stringList, uuidblock, strblock, cache) {}
