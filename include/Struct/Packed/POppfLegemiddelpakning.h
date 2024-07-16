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

class POppfLegemiddelpakning_0_0_0 : public POppf, public PLegemiddelpakning_0_0_0 {
    friend FestDeserializer;
public:
    POppfLegemiddelpakning_0_0_0(const OppfLegemiddelpakning &, PakningskomponentList &pakningskomponentList,
                           PakningsinfoList &pakningsinfoList,
                           PrisVareList &prisVareList, StringList &, FestUuidList_0_0_0 &, std::vector<FestUuid> &uuidblock,
                           std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfLegemiddelpakning_0_0_0 &) const;
};

class POppfLegemiddelpakning_0_4_0 : public POppf, public PLegemiddelpakning_0_4_0 {
    friend FestDeserializer;
public:
    POppfLegemiddelpakning_0_4_0(const OppfLegemiddelpakning &, PakningskomponentList &pakningskomponentList,
                           PakningsinfoList &pakningsinfoList,
                           PrisVareList &prisVareList, StringList &, FestUuidList_0_4_0 &, std::vector<FestUuid> &uuidblock,
                           std::string &strblock, std::map<std::string,uint32_t> &cache);
    POppfLegemiddelpakning_0_4_0(const POppfLegemiddelpakning_0_0_0 &);
    bool operator == (const POppfLegemiddelpakning_0_4_0 &) const;
};

class POppfLegemiddelpakning : public POppf, public PLegemiddelpakning {
public:
    POppfLegemiddelpakning(const POppfLegemiddelpakning_0_0_0 &);
    POppfLegemiddelpakning(const POppfLegemiddelpakning_0_4_0 &);
};

#endif //LEGEMFEST_POPPFLEGEMIDDELPAKNING_H
