//
// Created by sigsegv on 1/29/23.
//

#include "POppfHandelsvare.h"
#include "../Decoded/OppfHandelsvare.h"

POppfMedForbrMatr::POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock) :
        POppfHandelsvare<MedForbrMatr, PMedForbrMatr>(oppfMedForbrMatr, oppfMedForbrMatr.medForbrMatr, prisVareList, stringList, uuidblock, strblock) {}
