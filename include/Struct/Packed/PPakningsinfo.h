//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_PPAKNINGSINFO_H
#define LEGEMFEST_PPAKNINGSINFO_H

#include "PFestId.h"
#include "PString.h"
#include "PValueWithCodeset.h"
#include "PValueUnit.h"
#include "GenericListStorage.h"
#include "PakningskomponentList.h"

class FestDeserializer;
class Pakningsinfo;

class PPakningsinfo {
    friend FestDeserializer;
private:
    PFestId merkevareId;
    PString pakningsstr;
    PValueWithCodeset enhetPakning;
    PValueWithCodeset pakningstype;
    PValueUnit ddd;
    PString mengde;
    GenericListItems32 pakningskomponent;
    double statistikkfaktor;
    uint16_t antall;
    uint16_t multippel;
public:
    PPakningsinfo(const Pakningsinfo &, std::vector<FestUuid> &uuidblock, PakningskomponentList &pakningskomponentList,
                  std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PPakningsinfo &) const;

    [[nodiscard]] PFestId GetMerkevareId() const {
        return merkevareId;
    }

    [[nodiscard]] PString GetPakningsstr() const {
        return pakningsstr;
    }

    [[nodiscard]] PValueWithCodeset GetEnhetPakning() const {
        return enhetPakning;
    }

    [[nodiscard]] PValueWithCodeset GetPakningstype() const {
        return pakningstype;
    }

    [[nodiscard]] PValueUnit GetDDD() const {
        return ddd;
    }

    [[nodiscard]] PString GetMengde() const {
        return mengde;
    }

    [[nodiscard]] GenericListItems32 GetPakningskomponent() const {
        return pakningskomponent;
    }

    [[nodiscard]] double GetStatistikkfaktor() const {
        return statistikkfaktor;
    }

    [[nodiscard]] uint16_t GetAntall() const {
        return antall;
    }

    [[nodiscard]] uint16_t GetMultippel() const {
        return multippel;
    }
};


#endif //LEGEMFEST_PPAKNINGSINFO_H
