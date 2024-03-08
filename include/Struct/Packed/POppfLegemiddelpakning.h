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
class StringList;

class POppfLegemiddelpakning : public POppf, public PLegemiddelpakning {
    friend FestDeserializer;
public:
    POppfLegemiddelpakning(const OppfLegemiddelpakning &, PakningskomponentList &pakningskomponentList,
                           PakningsinfoList &pakningsinfoList,
                           PrisVareList &prisVareList, StringList &, FestUuidList &, std::vector<FestUuid> &uuidblock,
                           std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfLegemiddelpakning &) const;
};


#endif //LEGEMFEST_POPPFLEGEMIDDELPAKNING_H
