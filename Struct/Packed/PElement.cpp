//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PElement.h>
#include <Struct/Packed/FestUuid.h>
#include <Struct/Decoded/Element.h>

template <class T> constexpr T LastItemOf(std::vector<T> vec) {
    auto size = vec.size();
    if (size > 0) {
        return vec[size - 1];
    }
    return {};
}

PElement::PElement(const Element &element, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        PTerm(LastItemOf(element.GetTerm()), strblock, cache),
        id(element.GetId(), strblock, cache),
        kode(element.GetKode(), strblock, cache)
{
}

bool PElement::operator==(const PElement &other) const {
    return PTerm::operator==(other) &&
            id == other.id &&
            kode == other.kode;
}