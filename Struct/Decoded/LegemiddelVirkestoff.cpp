//
// Created by sigsegv on 12/18/22.
//

#include <Struct/Decoded/LegemiddelVirkestoff.h>

std::string LegemiddelVirkestoff::GetId() const {
    return id;
}

std::vector<Refusjon> LegemiddelVirkestoff::GetRefusjon() const {
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