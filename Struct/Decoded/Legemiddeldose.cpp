//
// Created by sigsegv on 12/29/22.
//

#include <Struct/Decoded/Legemiddeldose.h>

Preparattype Legemiddeldose::GetPreparattype() const {
    return preparattype;
}

std::string Legemiddeldose::GetId() const {
    return id;
}

std::string Legemiddeldose::GetLmrLopenr() const {
    return lmrLopenr;
}

ValueUnit Legemiddeldose::GetMengde() const {
    return mengde;
}

std::vector<std::string> Legemiddeldose::GetRefLegemiddelMerkevare() const {
    return refLegemiddelMerkevare;
}

std::vector<std::string> Legemiddeldose::GetRefPakning() const {
    return refPakning;
}

std::vector<PakningskomponentInfo> Legemiddeldose::GetPakningskomponent() const {
    return pakningskomponent;
}

Pakningstype Legemiddeldose::GetPakningstype() const {
    return pakningstype;
}
