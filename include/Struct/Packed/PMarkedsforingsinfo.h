//
// Created by sigsegv on 1/19/23.
//

#ifndef LEGEMFEST_PMARKEDSFORINGSINFO_H
#define LEGEMFEST_PMARKEDSFORINGSINFO_H

#include "PString.h"

class FestDeserializer;
class Markedsforingsinfo;

class PMarkedsforingsinfo {
    friend FestDeserializer;
private:
    PString markedsforingsdato;
    PString varenrUtgaende;
    PString midlUtgattDato;
    PString avregDato;
public:
    PMarkedsforingsinfo(const Markedsforingsinfo &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PMarkedsforingsinfo &) const;
};


#endif //LEGEMFEST_PMARKEDSFORINGSINFO_H
