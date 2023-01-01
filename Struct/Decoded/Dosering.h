//
// Created by sigsegv on 12/31/22.
//

#ifndef LEGEMFEST_DOSERING_H
#define LEGEMFEST_DOSERING_H

#include "DoseFastTidspunkt.h"
#include <vector>

class Dosering {
private:
    std::vector<DoseFastTidspunkt> doseFastTidspunkt;
public:
    Dosering() : doseFastTidspunkt() {}
    Dosering(const std::vector<DoseFastTidspunkt> &doseFastTidspunkt) : doseFastTidspunkt(doseFastTidspunkt) {}
    [[nodiscard]] std::vector<DoseFastTidspunkt> GetDoseFastTidspunkt() const;
};


#endif //LEGEMFEST_DOSERING_H
