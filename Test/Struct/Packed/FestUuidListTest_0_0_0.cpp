//
// Created by sigsegv on 1/6/23.
//

#include <Struct/Packed/FestUuidList.h>
#include <iostream>

void PrintMismatch(const std::vector<std::string> &l1, const std::vector<std::string> &l2) {
    std::cerr << "List:\n";
    for (const auto &i : l1) {
        std::cerr << " - " << i << "\n";
    }
    std::cerr << "Vs:\n";
    for (const auto &i : l2) {
        std::cerr << " - " << i << "\n";
    }
}

bool AssertMatch(const std::vector<std::string> &l1, const std::vector<std::string> &l2) {
    auto size = l1.size();
    if (size != l2.size()) {
        PrintMismatch(l1, l2);
        return false;
    }
    for (typeof(size) i = 0; i < size; i++) {
        if (l1[i] != l2[i]) {
            PrintMismatch(l1, l2);
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> list1{
        "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B"
    };
    std::vector<std::string> list2{
        "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B",
        "ID_149D939B-EB27-4806-BEAA-A33B008C815E",
        "ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31"
    };
    std::vector<std::string> list3{
        "ID_149D939B-EB27-4806-BEAA-A33B008C815E",
        "ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31"
    };
    std::vector<std::string> list4{
        "ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31",
        "ID_149D939B-EB27-4806-BEAA-A33B008C815E",
        "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B",
        "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B"
    };
    std::vector<FestUuid> uuidblock{};
    FestUuidList_0_0_0 festUuidList{uuidblock};
    auto l1 = festUuidList.StoreList(list1);
    auto s1 = festUuidList.GetStorageBlock().size();
    if (s1 != 1) {
        std::cerr << "Error: Size 1 mismatch: " << s1 << " != 1\n";
        return 127;
    }
    if (!AssertMatch(list1, festUuidList.RetrieveList(l1))) {
        return 127;
    }
    auto l2 = festUuidList.StoreList(list2);
    auto s2 = festUuidList.GetStorageBlock().size();
    if (s2 != 3) {
        std::cerr << "Error: Size 2 mismatch: " << s2 << " != 3\n";
        return 127;
    }
    if (!AssertMatch(list2, festUuidList.RetrieveList(l2))) {
        return 127;
    }
    auto l3 = festUuidList.StoreList(list3);
    auto s3 = festUuidList.GetStorageBlock().size();
    if (s3 != 3) {
        std::cerr << "Error: Size 3 mismatch: " << s3 << " != 3\n";
        return 127;
    }
    if (!AssertMatch(list3, festUuidList.RetrieveList(l3))) {
        return 127;
    }
    auto l4 = festUuidList.StoreList(list4);
    auto s4 = festUuidList.GetStorageBlock().size();
    if (s4 != 6) {
        std::cerr << "Error: Size 4 mismatch: " << s4 << " != 6\n";
        return 127;
    }
    if (!AssertMatch(list4, festUuidList.RetrieveList(l4))) {
        return 127;
    }

    if (!AssertMatch(list1, festUuidList.RetrieveList(l1))) {
        return 127;
    }
    if (!AssertMatch(list2, festUuidList.RetrieveList(l2))) {
        return 127;
    }
    if (!AssertMatch(list3, festUuidList.RetrieveList(l3))) {
        return 127;
    }
    if (!AssertMatch(list4, festUuidList.RetrieveList(l4))) {
        return 127;
    }
    return 0;
}