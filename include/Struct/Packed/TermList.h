//
// Created by sigsegv on 6/15/24.
//

#ifndef LIBMEDFEST_TERMLIST_H
#define LIBMEDFEST_TERMLIST_H

#include "GenericListStorage.h"
#include "PTerm.h"

class FestDeserializerPreloader_0;
class FestDeserializerPreloader_1;

class TermList : private GenericListStorage64<PTerm> {
    friend FestDeserializerPreloader_0;
    friend FestDeserializerPreloader_1;
public:
    GenericListItems64 StoreList(const std::vector<PTerm> &elements);
    std::vector<PTerm> GetStorageList() const;
    size_t size() const;
};


#endif //LIBMEDFEST_TERMLIST_H
