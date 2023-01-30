//
// Created by sigsegv on 1/29/23.
//

#include "POppfHandelsvare.h"
#include "../Decoded/OppfHandelsvare.h"

POppfMedForbrMatr::POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock) :
        POppfHandelsvare<MedForbrMatr, PMedForbrMatr>(oppfMedForbrMatr, oppfMedForbrMatr.medForbrMatr, prisVareList, stringList, uuidblock, strblock) {}

POppfNaringsmiddel::POppfNaringsmiddel(const OppfNaringsmiddel &oppfNaringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock) :
        POppfHandelsvare<Naringsmiddel, PNaringsmiddel>(oppfNaringsmiddel, oppfNaringsmiddel.naringsmiddel, prisVareList, stringList, uuidblock, strblock) {}
