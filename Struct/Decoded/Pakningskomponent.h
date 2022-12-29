//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_PAKNINGSKOMPONENT_H
#define LEGEMFEST_PAKNINGSKOMPONENT_H

#include "PakningskomponentInfo.h"

class Pakningskomponent : public PakningskomponentInfo {
private:
    int antall;
public:
    Pakningskomponent() : PakningskomponentInfo(), antall(0) {}
    Pakningskomponent(const PakningskomponentInfo &info, int antall) : PakningskomponentInfo(info), antall(antall) {}
    [[nodiscard]] int GetAntall() const;
};


#endif //LEGEMFEST_PAKNINGSKOMPONENT_H
