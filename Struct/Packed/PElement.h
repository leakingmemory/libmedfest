//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_PELEMENT_H
#define LEGEMFEST_PELEMENT_H

#include "PTerm.h"
#include "PFestId.h"

class FestDeserializer;
class Element;

class PElement : public PTerm {
    friend FestDeserializer;
private:
    PString id;
    PString kode;
public:
    PElement(const Element &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const PElement &other) const;
};


#endif //LEGEMFEST_PELEMENT_H
