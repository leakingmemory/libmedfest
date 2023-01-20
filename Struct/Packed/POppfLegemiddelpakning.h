//
// Created by sigsegv on 1/18/23.
//

#ifndef LEGEMFEST_POPPFLEGEMIDDELPAKNING_H
#define LEGEMFEST_POPPFLEGEMIDDELPAKNING_H

#include "POppf.h"
#include "PLegemiddelpakning.h"
#include <vector>

class FestDeserializer;
class OppfLegemiddelpakning;
class PakningsinfoList;
class PrisVareList;
class FestUuidList;

class POppfLegemiddelpakning : public POppf, public PLegemiddelpakning {
    friend FestDeserializer;
public:
    POppfLegemiddelpakning(const OppfLegemiddelpakning &, PakningskomponentList &pakningskomponentList,
                           PakningsinfoList &pakningsinfoList,
                           PrisVareList &prisVareList, FestUuidList &festUuidList, std::vector<FestUuid> &uuidblock,
                           std::string &strblock);
};


#endif //LEGEMFEST_POPPFLEGEMIDDELPAKNING_H
