//
// Created by sigsegv on 2/14/23.
//

#ifndef LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
#define LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H

#include "GenericListStorage.h"
#include "PDoseFastTidspunkt.h"

class DoseFastTidspunktList : private GenericListStorage<PDoseFastTidspunkt> {
public:
    GenericListItems StoreList(const std::vector<PDoseFastTidspunkt> &);
    std::vector<PDoseFastTidspunkt> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_DOSEFASTTIDSPUNKTLIST_H
