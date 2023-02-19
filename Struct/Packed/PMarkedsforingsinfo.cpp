//
// Created by sigsegv on 1/19/23.
//

#include "PMarkedsforingsinfo.h"
#include "../Decoded/Markedsforingsinfo.h"

PMarkedsforingsinfo::PMarkedsforingsinfo(const Markedsforingsinfo &markedsforingsinfo,
                                         std::string &strblock, std::map<std::string,uint32_t> &cache) :
        markedsforingsdato(markedsforingsinfo.GetMarkedsforingsdato(), strblock, cache),
        varenrUtgaende(markedsforingsinfo.GetVarenrUtgaende(), strblock, cache),
        midlUtgattDato(markedsforingsinfo.GetMidlUtgattDato(), strblock, cache),
        avregDato(markedsforingsinfo.GetAvregDato(), strblock, cache) {
}

bool PMarkedsforingsinfo::operator==(const PMarkedsforingsinfo &other) const {
    return markedsforingsdato == other.markedsforingsdato &&
           varenrUtgaende == other.varenrUtgaende &&
           midlUtgattDato == other.midlUtgattDato &&
           avregDato == other.avregDato;
}