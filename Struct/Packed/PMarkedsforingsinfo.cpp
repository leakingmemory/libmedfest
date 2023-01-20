//
// Created by sigsegv on 1/19/23.
//

#include "PMarkedsforingsinfo.h"
#include "../Decoded/Markedsforingsinfo.h"

PMarkedsforingsinfo::PMarkedsforingsinfo(const Markedsforingsinfo &markedsforingsinfo, std::string &strblock) :
        markedsforingsdato(markedsforingsinfo.GetMarkedsforingsdato(), strblock),
        varenrUtgaende(markedsforingsinfo.GetVarenrUtgaende(), strblock),
        midlUtgattDato(markedsforingsinfo.GetMidlUtgattDato(), strblock),
        avregDato(markedsforingsinfo.GetAvregDato(), strblock) {
}