//
// Created by sigsegv on 2/9/23.
//

#ifndef LEGEMFEST_PREFERANSEELEMENT_H
#define LEGEMFEST_PREFERANSEELEMENT_H

#include "PValueWithDistinguishedName.h"
#include "GenericListStorage.h"

class FestDeserializer;
class Referanseelement;
class FestUuidList;

class PReferanseelement {
    friend FestDeserializer;
private:
    PValueWithDistinguishedName klasse;
    GenericListItems refs;
public:
    PReferanseelement(const Referanseelement &, FestUuidList &, std::string &strblock, std::map<std::string,uint32_t> &cache);
};


#endif //LEGEMFEST_PREFERANSEELEMENT_H
