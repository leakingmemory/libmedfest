//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
#define LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H

#include "GenericListStorage.h"
#include "PDoseFastTidspunkt.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class DoseFastTidspunktList : private GenericListStorage32<PDoseFastTidspunkt> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems32 StoreList(const std::vector<PDoseFastTidspunkt> &);
    std::vector<PDoseFastTidspunkt> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
