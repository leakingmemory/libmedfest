//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_LEGEMIDDELDOSE_H
#define LEGEMFEST_LEGEMIDDELDOSE_H

#include "LegemiddelCore.h"
#include "Preparattype.h"
#include "ValueUnit.h"
#include "PakningskomponentInfo.h"

class Legemiddeldose : public LegemiddelCore {
private:
    Preparattype preparattype;
    std::string id;
    std::string lmrLopenr;
    ValueUnit mengde;
    std::vector<std::string> refLegemiddelMerkevare;
    std::vector<std::string> refPakning;
    std::vector<PakningskomponentInfo> pakningskomponent;
    Pakningstype pakningstype;
public:
    Legemiddeldose() : LegemiddelCore(), preparattype(), id(), lmrLopenr(), mengde(), refLegemiddelMerkevare(),
                       refPakning(), pakningskomponent(), pakningstype() {}
    Legemiddeldose(const LegemiddelCore &legemiddelCore, const Preparattype &preparattype, const std::string &id,
                   const std::string &lmrLopenr, const ValueUnit &mengde,
                   const std::vector<std::string> &refLegemiddelMerkevare, const std::vector<std::string> &refPakning,
                   const std::vector<PakningskomponentInfo> &pakningskomponent, const Pakningstype &pakningstype) :
            LegemiddelCore(legemiddelCore), preparattype(preparattype), id(id), lmrLopenr(lmrLopenr), mengde(mengde),
            refLegemiddelMerkevare(refLegemiddelMerkevare), refPakning(refPakning),
            pakningskomponent(pakningskomponent), pakningstype(pakningstype) {}
    [[nodiscard]] Preparattype GetPreparattype() const;
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetLmrLopenr() const;
    [[nodiscard]] ValueUnit GetMengde() const;
    [[nodiscard]] std::vector<std::string> GetRefLegemiddelMerkevare() const;
    [[nodiscard]] std::vector<std::string> GetRefPakning() const;
    [[nodiscard]] std::vector<PakningskomponentInfo> GetPakningskomponent() const;
    [[nodiscard]] Pakningstype GetPakningstype() const;
};


#endif //LEGEMFEST_LEGEMIDDELDOSE_H
