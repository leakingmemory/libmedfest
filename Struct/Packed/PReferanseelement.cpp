//
// Created by sigsegv on 2/9/23.
//

#include <Struct/Packed/PReferanseelement.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/Referanseelement.h>

PReferanseelement::PReferanseelement(const Referanseelement &referanseelement, FestUuidList &festUuidList,
                                     std::string &strblock, std::map<std::string, uint32_t> &cache) :
        klasse(referanseelement.klasse, strblock, cache),
        refs(festUuidList.StoreList(referanseelement.refs))
{
}

bool PReferanseelement::operator==(const PReferanseelement &other) const {
    return klasse == other.klasse &&
           refs == other.refs;
}