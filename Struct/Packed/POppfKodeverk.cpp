//
// Created by sigsegv on 2/5/23.
//

#include <Struct/Packed/POppfKodeverk.h>
#include <Struct/Packed/ElementList.h>
#include <Struct/Packed/PElement.h>
#include <Struct/Decoded/OppfKodeverk.h>

POppfKodeverk_0_0_0::POppfKodeverk_0_0_0(const OppfKodeverk &oppf, ElementList_0_0_0 &elementList, std::vector<FestUuid> &idblock,
                             std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PInfo(oppf.info, strblock, cache),
        elements()
{
    std::vector<PElement_0_0_0> elements{};
    for (const auto &element : oppf.element) {
        elements.emplace_back(element, strblock, cache);
    }
    this->elements = elementList.StoreList(elements);
}

bool POppfKodeverk_0_0_0::operator==(const POppfKodeverk_0_0_0 &other) const {
    return POppf::operator==(other) &&
           PInfo::operator==(other) &&
           elements == other.elements;
}

POppfKodeverk_0_3_0::POppfKodeverk_0_3_0(const OppfKodeverk &oppf, ElementList_0_3_0 &elementList, TermList &termList, std::vector<FestUuid> &idblock,
                                         std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PInfo(oppf.info, strblock, cache),
        elements()
{
    std::vector<PElement_0_3_0> elements{};
    for (const auto &element : oppf.element) {
        elements.emplace_back(element, termList, strblock, cache);
    }
    this->elements = elementList.StoreList(elements);
}

bool POppfKodeverk_0_3_0::operator==(const POppfKodeverk_0_3_0 &other) const {
    return POppf::operator==(other) &&
           PInfo::operator==(other) &&
           elements == other.elements;
}

POppfKodeverk::POppfKodeverk(const POppfKodeverk_0_0_0 &oppf) : std::variant<POppfKodeverk_0_0_0,POppfKodeverk_0_3_0>(oppf)
{
}

POppfKodeverk::POppfKodeverk(const POppfKodeverk_0_3_0 &oppf) : std::variant<POppfKodeverk_0_0_0,POppfKodeverk_0_3_0>(oppf)
{
}
