//
// Created by sigsegv on 2/15/23.
//

#ifndef LEGEMFEST_POPPFSTRDOSERING_H
#define LEGEMFEST_POPPFSTRDOSERING_H

#include "POppf.h"
#include "PKortdose.h"

class FestDeserializer;
class OppfStrDosering;
class LegemiddelforbrukList;
class DoseringList;
class DoseFastTidspunktList;
class FestUuid;

class POppfStrDosering : public POppf, public PKortdose {
    friend FestDeserializer;
public:
    POppfStrDosering(const OppfStrDosering &, LegemiddelforbrukList &, DoseringList &, DoseFastTidspunktList &,
                     std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string,uint32_t> &cache);
    bool operator == (const POppfStrDosering &) const;
};


#endif //LEGEMFEST_POPPFSTRDOSERING_H
