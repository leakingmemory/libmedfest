//
// Created by sigsegv on 6/16/24.
//

#include <Struct/Packed/POppfKodeverk.h>
#include <Struct/Packed/ElementList.h>
#include <Struct/Decoded/OppfKodeverk.h>
#include <FestDeserializer.h>

POppfKodeverk_0_3_0::POppfKodeverk_0_3_0(const POppfKodeverk_0_0_0 &src, const FestDeserializer &deserializer, ElementList_0_3_0 &elementList, TermList &termList, std::string &strblock, std::map<std::string,uint32_t> &cache) :
        POppf(static_cast<const POppf &>(src)),
        PInfo(static_cast<const PInfo &>(src)),
        elements()
{
    std::vector<PElement_0_3_0> encodedElements{};
    {
        auto kodeverk = deserializer.Unpack(src);
        auto decodedElements = kodeverk.GetElement();
        for (const auto &element: decodedElements) {
            encodedElements.emplace_back(element, termList, strblock, cache);
        }
    }
    elements = elementList.StoreList(encodedElements);
}
