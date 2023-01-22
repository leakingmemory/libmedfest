//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_LEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_LEGEMIDDELVIRKESTOFF_H

#include "Legemiddel.h"
#include "Refusjon.h"
#include "EnhetForskrivning.h"

class LegemiddelVirkestoff : public Legemiddel {
private:
    std::string id;
    std::vector<Refusjon> refusjon;
    std::vector<std::string> refLegemiddelMerkevare;
    std::vector<std::string> refPakning;
    EnhetForskrivning forskrivningsenhetResept;
public:
    LegemiddelVirkestoff() : Legemiddel(), id(), refusjon(), refLegemiddelMerkevare(), refPakning(),
                             forskrivningsenhetResept() {}
    LegemiddelVirkestoff(const Legemiddel &legemiddel, const std::string &id, const std::vector<Refusjon> &refusjon,
                         const std::vector<std::string> &refLegemiddelMerkevare,
                         const std::vector<std::string> &refPakning, const EnhetForskrivning &forskrivningsenhetResept) :
            Legemiddel(legemiddel), id(id), refusjon(refusjon), refLegemiddelMerkevare(refLegemiddelMerkevare),
            refPakning(refPakning), forskrivningsenhetResept(forskrivningsenhetResept) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::vector<Refusjon> GetRefusjon() const;
    [[nodiscard]] std::vector<std::string> GetRefLegemiddelMerkevare() const;
    [[nodiscard]] std::vector<std::string> GetRefPakning() const;
    [[nodiscard]] EnhetForskrivning GetForskrivningsenhetResept() const;
};


#endif //LEGEMFEST_LEGEMIDDELVIRKESTOFF_H
