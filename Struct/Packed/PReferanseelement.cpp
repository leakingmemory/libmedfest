//
// Created by sigsegv on 2/9/23.
//

#include <Struct/Packed/PReferanseelement.h>
#include <Struct/Packed/FestUuidList.h>
#include <Struct/Decoded/Referanseelement.h>

PReferanseelement_0_0_0::PReferanseelement_0_0_0(const Referanseelement &referanseelement, FestUuidList_0_0_0 &festUuidList,
                                     std::string &strblock, std::map<std::string, uint32_t> &cache) :
        klasse(referanseelement.klasse, strblock, cache),
        refs(festUuidList.StoreList(referanseelement.refs))
{
}

bool PReferanseelement_0_0_0::operator==(const PReferanseelement_0_0_0 &other) const {
    return klasse == other.klasse &&
           refs == other.refs;
}

PReferanseelement_0_4_0::PReferanseelement_0_4_0(const Referanseelement &referanseelement, FestUuidList_0_4_0 &festUuidList,
                                     std::string &strblock, std::map<std::string, uint32_t> &cache) :
        klasse(referanseelement.klasse, strblock, cache),
        refs(festUuidList.StoreList(referanseelement.refs))
{
}

PReferanseelement_0_4_0::PReferanseelement_0_4_0(const PReferanseelement_0_0_0 &r) :
        klasse(r.klasse),
        refs(r.refs.CastToWider<GenericListItems64>())
{
}

bool PReferanseelement_0_4_0::operator==(const PReferanseelement_0_4_0 &other) const {
    return klasse == other.klasse &&
           refs == other.refs;
}

PReferanseelement::PReferanseelement(const PReferanseelement_0_0_0 &r) : std::variant<PReferanseelement_0_0_0,PReferanseelement_0_4_0>(r) {}
PReferanseelement::PReferanseelement(const PReferanseelement_0_4_0 &r) : std::variant<PReferanseelement_0_0_0,PReferanseelement_0_4_0>(r) {}
