//
// Created by sigsegv on 6/16/24.
//

#include <Struct/Packed/PFest.h>
#include <Struct/Packed/Uint32List.h>
#include <FestDeserializer.h>

PFest_V_0_3_0::PFest_V_0_3_0(const PFest_V_0_0_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32List) : PFest_V_0_2_0_or_later(legacy) {
    std::vector<uint32_t> indices{};
    {
        auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List_V_0_0_0,
                                                 festDeserializer.numUint16List_V_0_0_0, legacy.legemiddelpakning);
        for (auto index: indices16) {
            indices.emplace_back(index);
        }
    }
    legemiddelpakning = uint32List.StoreList(indices);
}

PFest_V_0_3_0::PFest_V_0_3_0(const PFest_V_0_2_0 &legacy, const FestDeserializer &festDeserializer, Uint32List &uint32List) : PFest_V_0_2_0_or_later(legacy) {
    std::vector<uint32_t> indices{};
    {
        auto indices16 = festDeserializer.Unpack(festDeserializer.uint16List,
                                                 festDeserializer.numUint16List, legacy.legemiddelpakning);
        for (auto index: indices16) {
            indices.emplace_back(index);
        }
    }
    legemiddelpakning = uint32List.StoreList(indices);
}
