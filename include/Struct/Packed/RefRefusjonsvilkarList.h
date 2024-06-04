//
// Created by sigsegv on 2/5/23.
//

#ifndef LEGEMFEST_REFREFUSJONSVILKARLIST_H
#define LEGEMFEST_REFREFUSJONSVILKARLIST_H

#include "PRefRefusjonsvilkar.h"
#include "GenericListStorage.h"

class FestDeserializerPreloader;

class RefRefusjonsvilkarList : private GenericListStorage32<PRefRefusjonsvilkar> {
    friend FestDeserializerPreloader;
public:
    GenericListItems32 StoreList(std::vector<PRefRefusjonsvilkar> &list);
    std::vector<PRefRefusjonsvilkar> GetStorageList() const;
    size_t size() const;
};


#endif //LEGEMFEST_REFREFUSJONSVILKARLIST_H
