//
// Created by sigsegv on 1/29/23.
//

#ifndef LEGEMFEST_STRINGLIST_H
#define LEGEMFEST_STRINGLIST_H

#include "GenericListStorage.h"
#include "PString.h"

class StringList : GenericListStorage<PString> {
public:
    GenericListItems StoreList(const std::vector<PString> &);
    GenericListItems StoreList(const std::vector<std::string> &, std::string &strblock, std::map<std::string,uint32_t> &cache);
    [[nodiscard]] std::vector<PString> GetStorageList() const;
    [[nodiscard]] size_t size() const;
};


#endif //LEGEMFEST_STRINGLIST_H
