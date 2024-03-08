//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PElement.h>
#include <Struct/Packed/FestUuid.h>
#include <Struct/Decoded/Element.h>

PElement::PElement(const Element &element, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        PTerm(element.GetTerm(), strblock, cache),
        id(element.GetId(), strblock, cache),
        kode(element.GetKode(), strblock, cache)
{
}

bool PElement::operator==(const PElement &other) const {
    return PTerm::operator==(other) &&
            id == other.id &&
            kode == other.kode;
}