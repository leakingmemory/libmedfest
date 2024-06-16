//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/PElement.h>
#include <Struct/Packed/FestUuid.h>
#include <Struct/Packed/TermList.h>
#include <Struct/Decoded/Element.h>

template <class T> constexpr T LastItemOf(std::vector<T> vec) {
    auto size = vec.size();
    if (size > 0) {
        return vec[size - 1];
    }
    return {};
}

PElement_0_0_0::PElement_0_0_0(const Element &element, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        PTerm(LastItemOf(element.GetTermList()), strblock, cache),
        id(element.GetId(), strblock, cache),
        kode(element.GetKode(), strblock, cache)
{
}

bool PElement_0_0_0::operator==(const PElement_0_0_0 &other) const {
    return PTerm::operator==(other) &&
            id == other.id &&
            kode == other.kode;
}

PElement_0_3_0::PElement_0_3_0(const Element &element, TermList &termList, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        id(element.GetId(), strblock, cache),
        kode(element.GetKode(), strblock, cache),
        term()
{
    std::vector<PTerm> terms{};
    {
        auto dTerms = element.GetTermList();
        for (const auto &dt : dTerms) {
            terms.emplace_back(dt, strblock, cache);
        }
    }
    term = termList.StoreList(terms);
}

bool PElement_0_3_0::operator==(const PElement_0_3_0 &other) const {
    return id == other.id &&
           kode == other.kode &&
           term == other.term;
}

PElement::PElement(const PElement_0_0_0 &element) : std::variant<PElement_0_0_0,PElement_0_3_0>(element)
{
}

PElement::PElement(const PElement_0_3_0 &element) : std::variant<PElement_0_0_0,PElement_0_3_0>(element)
{
}
