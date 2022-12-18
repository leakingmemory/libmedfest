//
// Created by sigsegv on 12/18/22.
//

#include "LegemiddelVirkestoff.h"

Refusjon LegemiddelVirkestoff::GetRefusjon() const {
    return refusjon;
}

std::vector<std::string> LegemiddelVirkestoff::GetRefLegemiddelMerkevare() const {
    return refLegemiddelMerkevare;
}

std::vector<std::string> LegemiddelVirkestoff::GetRefPakning() const {
    return refPakning;
}

EnhetForskrivning LegemiddelVirkestoff::GetForskrivningsenhetResept() const {
    return forskrivningsenhetResept;
}