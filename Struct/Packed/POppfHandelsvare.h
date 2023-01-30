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

template <class T, class P> class POppfHandelsvare : public POppf, public P {
public:
    POppfHandelsvare(const Oppf &oppf, const T &handelsvare, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock) :
            POppf(oppf, uuidblock, strblock),
            P(handelsvare, prisVareList, stringList, strblock) {}
};

class POppfMedForbrMatr : public POppfHandelsvare<MedForbrMatr, PMedForbrMatr> {
public:
    POppfMedForbrMatr(const OppfMedForbrMatr &oppfMedForbrMatr, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock);
};

class POppfNaringsmiddel : public POppfHandelsvare<Naringsmiddel, PNaringsmiddel> {
public:
    POppfNaringsmiddel(const OppfNaringsmiddel &naringsmiddel, PrisVareList &prisVareList, StringList &stringList, std::vector<FestUuid> &uuidblock, std::string &strblock);
};

#endif //LEGEMFEST_POPPFHANDELSVARE_H
