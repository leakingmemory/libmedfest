//
// Created by sigsegv on 2/9/23.
//

#include "PReferanseelement.h"
#include "FestUuidList.h"
#include "../Decoded/Referanseelement.h"

PReferanseelement::PReferanseelement(const Referanseelement &referanseelement, FestUuidList &festUuidList,
                                     std::string &strblock, std::map<std::string, uint32_t> &cache) :
        klasse(referanseelement.klasse, strblock, cache),
        refs(festUuidList.StoreList(referanseelement.refs))
{
}
