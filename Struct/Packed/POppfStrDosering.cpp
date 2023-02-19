//
// Created by sigsegv on 2/15/23.
//

#include "POppfStrDosering.h"
#include "../Decoded/OppfStrDosering.h"

POppfStrDosering::POppfStrDosering(const OppfStrDosering &oppfStrDosering, LegemiddelforbrukList &legemiddelforbrukList,
                                   DoseringList &doseringList, DoseFastTidspunktList &doseFastTidspunktList,
                                   std::vector<FestUuid> &idblock, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppfStrDosering, idblock, strblock, cache),
        PKortdose(oppfStrDosering.kortdose, legemiddelforbrukList, doseringList, doseFastTidspunktList, strblock, cache) {}

bool POppfStrDosering::operator==(const POppfStrDosering &other) const {
    return POppf::operator==(other) &&
           PKortdose::operator==(other);
}