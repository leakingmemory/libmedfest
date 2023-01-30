//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_PHANDELSVARE_H
#define LEGEMFEST_PHANDELSVARE_H

#include "PProduktInfoVare.h"
#include "PLeverandor.h"
#include "PRefusjon.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Handelsvare;
class PrisVareList;
class MedForbrMatr;
class Naringsmiddel;
class Brystprotese;

class PHandelsvare {
    friend FestDeserializer;
private:
    PString nr;
    PString navn;
    PProduktInfoVare produktInfoVare;
    PLeverandor leverandor;
    GenericListItems prisVare;
    PRefusjon refusjon;
public:
    PHandelsvare(const Handelsvare &handelsvare, PrisVareList &prisVareList, StringList &stringList, std::string &strblock);
};

class PMedForbrMatr : public PHandelsvare {
public:
    PMedForbrMatr(const MedForbrMatr &medForbrMatr, PrisVareList &, StringList &, std::string &strblock);
};

class PNaringsmiddel : public PHandelsvare {
public:
    PNaringsmiddel(const Naringsmiddel &naringsmiddel, PrisVareList &, StringList &, std::string &strblock);
};

class PBrystprotese : public PHandelsvare {
public:
    PBrystprotese(const Brystprotese &brystprotese, PrisVareList &, StringList &, std::string &strblock);
};

#endif //LEGEMFEST_PHANDELSVARE_H
