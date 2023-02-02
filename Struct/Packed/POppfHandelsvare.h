//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_POPPFHANDELSVARE_H
#define LEGEMFEST_POPPFHANDELSVARE_H

#include "POppf.h"
#include "PHandelsvare.h"

class PrisVareList;
class FestUuidList;
class OppfMedForbrMatr;
class OppfNaringsmiddel;
class OppfBrystprotese;

template <class T, class P> class POppfHandelsvare : public POppf, public P {
public:
    POppfHandelsvare(const Oppf &oppf, const T &handelsvare, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache) :
            POppf(oppf, uuidblock, strblock, cache),
            P(handelsvare, prisVareList, stringList, strblock, cache) {}
};

class POppfMedForbrMatr : public POppfHandelsvare<MedForbrMatr, PMedForbrMatr> {
public:
    POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class POppfNaringsmiddel : public POppfHandelsvare<Naringsmiddel, PNaringsmiddel> {
public:
    POppfNaringsmiddel(const OppfNaringsmiddel &naringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

class POppfBrystprotese : public POppfHandelsvare<Brystprotese, PBrystprotese> {
public:
    POppfBrystprotese(const OppfBrystprotese &brystprotese, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
};

#endif //LEGEMFEST_POPPFHANDELSVARE_H
