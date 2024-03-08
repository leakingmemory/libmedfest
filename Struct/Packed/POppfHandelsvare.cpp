//
// Created by sigsegv on 1/29/23.
//

#include <Struct/Packed/POppfHandelsvare.h>
#include <Struct/Decoded/OppfHandelsvare.h>

POppfMedForbrMatr::POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<MedForbrMatr, PMedForbrMatr>(oppfMedForbrMatr, oppfMedForbrMatr.medForbrMatr, prisVareList, stringList, uuidblock, strblock, cache) {}

bool POppfMedForbrMatr::operator==(const POppfMedForbrMatr &other) const {
    return POppfHandelsvare<MedForbrMatr, PMedForbrMatr>::operator==(other);
}

POppfNaringsmiddel::POppfNaringsmiddel(const OppfNaringsmiddel &oppfNaringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<Naringsmiddel, PNaringsmiddel>(oppfNaringsmiddel, oppfNaringsmiddel.naringsmiddel, prisVareList, stringList, uuidblock, strblock, cache) {}

bool POppfNaringsmiddel::operator==(const POppfNaringsmiddel &other) const {
    return POppfHandelsvare<Naringsmiddel, PNaringsmiddel>::operator==(other);
}

POppfBrystprotese::POppfBrystprotese(const OppfBrystprotese &oppfBrystprotese, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppfHandelsvare<Brystprotese, PBrystprotese>(oppfBrystprotese, oppfBrystprotese.brystprotese, prisVareList, stringList, uuidblock, strblock, cache) {}

bool POppfBrystprotese::operator==(const POppfBrystprotese &other) const {
    return POppfHandelsvare<Brystprotese, PBrystprotese>::operator==(other);
}