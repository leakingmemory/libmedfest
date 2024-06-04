//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
#define LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H

#include "GenericListStorage.h"
#include "PDoseFastTidspunkt.h"

class FestDeserializerPreloader;

class DoseFastTidspunktList : private GenericListStorage32<PDoseFastTidspunkt> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(const std::vector<PDoseFastTidspunkt> &);
    std::vector<PDoseFastTidspunkt> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
