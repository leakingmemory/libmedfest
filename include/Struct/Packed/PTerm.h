//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PTERM_H
#define LEGEMFEST_PTERM_H

#include "PValueWithDistinguishedName.h"
#include <map>

class FestDeserializer_0;
class FestDeserializer_1;
class Term;

class PTerm {
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    PValueWithDistinguishedName sprak;
    PString term;
    PString beskrivelseTerm;
public:
    PTerm(const Term &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PTerm &other) const;
};


#endif //LEGEMFEST_PTERM_H
