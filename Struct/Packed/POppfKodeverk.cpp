//
// Created by sigsegv on 2/5/23.
//

#include "POppfKodeverk.h"
#include "ElementList.h"
#include "PElement.h"
#include "../Decoded/OppfKodeverk.h"

POppfKodeverk::POppfKodeverk(const OppfKodeverk &oppf, ElementList &elementList, std::vector<FestUuid> &idblock,
                             std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PInfo(oppf.info, strblock, cache),
        elements()
{
    std::vector<PElement> elements{};
    for (const auto &element : oppf.element) {
        elements.emplace_back(element, strblock, cache);
    }
    this->elements = elementList.StoreList(elements);
}