//
// Created by sigsegv on 1/4/23.
//

#include "../../../Struct/Packed/PFestId.h"
#include <iostream>

int main() {
    std::vector<FestUuid> uuidblock{};
    auto s0 = uuidblock.size();
    PFestId n1{"ID_212709D3-4175-4F7E-BC65-C3D8ED04196B", uuidblock};
    if (n1.GetFestId(uuidblock).ToString() != "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B") {
        std::cerr << "Incorrect n1: " << n1.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    auto s1 = uuidblock.size();
    PFestId n2{"ID_149D939B-EB27-4806-BEAA-A33B008C815E", uuidblock};
    if (n2.GetFestId(uuidblock).ToString() != "ID_149D939B-EB27-4806-BEAA-A33B008C815E") {
        std::cerr << "Incorrect n2: " << n2.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    auto s2 = uuidblock.size();
    PFestId n3{"ID_149D939B-EB27-4806-BEAA-A33B008C815E", uuidblock};
    if (n3.GetFestId(uuidblock).ToString() != "ID_149D939B-EB27-4806-BEAA-A33B008C815E") {
        std::cerr << "Incorrect n3: " << n3.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    auto s3 = uuidblock.size();
    PFestId n4{"ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31", uuidblock};
    if (n4.GetFestId(uuidblock).ToString() != "ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31") {
        std::cerr << "Incorrect n4: " << n4.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    auto s4 = uuidblock.size();
    if (n1.GetFestId(uuidblock).ToString() != "ID_212709D3-4175-4F7E-BC65-C3D8ED04196B") {
        std::cerr << "Incorrect n1: " << n1.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    if (n2.GetFestId(uuidblock).ToString() != "ID_149D939B-EB27-4806-BEAA-A33B008C815E") {
        std::cerr << "Incorrect n2: " << n2.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    if (n3.GetFestId(uuidblock).ToString() != "ID_149D939B-EB27-4806-BEAA-A33B008C815E") {
        std::cerr << "Incorrect n3: " << n3.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    if (n4.GetFestId(uuidblock).ToString() != "ID_E82F4A7D-BDF0-440A-9EE2-C80F4D3B6C31") {
        std::cerr << "Incorrect n4: " << n4.GetFestId(uuidblock).ToString() << "\n";
        return 127;
    }
    if (s0 != 0) {
        std::cerr << "Incorrect size 0: " << s0 << "\n";
        return 127;
    }
    if (s1 != 1) {
        std::cerr << "Incorrect size 1: " << s1 << "\n";
        return 127;
    }
    if (s2 != 2) {
        std::cerr << "Incorrect size 2: " << s2 << "\n";
        return 127;
    }
    if (s3 != 2) {
        std::cerr << "Incorrect size 3: " << s3 << "\n";
        return 127;
    }
    if (s4 != 3) {
        std::cerr << "Incorrect size 4: " << s4 << "\n";
        return 127;
    }
    return 0;
}