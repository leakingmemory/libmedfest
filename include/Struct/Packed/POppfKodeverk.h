//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_POPPFKODEVERK_H
#define LEGEMFEST_POPPFKODEVERK_H

#include "POppf.h"
#include "PInfo.h"
#include "GenericListStorage.h"

class FestDeserializer;
class OppfKodeverk;
class ElementList;

class POppfKodeverk : public POppf, public PInfo {
    friend FestDeserializer;
private:
    GenericListItems32 elements;
public:
    POppfKodeverk(const OppfKodeverk &, ElementList &, std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfKodeverk &) const;
};


#endif //LEGEMFEST_POPPFKODEVERK_H
