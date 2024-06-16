//
// Created by sigsegv on 6/15/24.
//

#ifndef LIBMEDFEST_TERMLIST_H
#define LIBMEDFEST_TERMLIST_H

#include "GenericListStorage.h"
#include "PTerm.h"

class FestDeserializerPreloader;

class TermList : private GenericListStorage64<PTerm> {
    friend FestDeserializerPreloader;
public:
    GenericListItems64 StoreList(const std::vector<PTerm> &elements);
    std::vector<PTerm> GetStorageList() const;
    size_t size() const;
};


#endif //LIBMEDFEST_TERMLIST_H
