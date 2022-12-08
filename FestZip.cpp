//
// Created by jeo on 12/8/22.
//

#include "FestZip.h"
#include "libzip_zip.h"
#include <iostream>

FestZip::FestZip(const std::string &zipname) {
    z = std::make_shared<libzip_zip>(zipname);
}

void FestZip::Decode() {
    auto num = z->NumEntries();
    std::cout << "Contents zip:\n";
    for (typeof(num) i = 0; i < num; i++) {
        std::cout << z->Filename(i) << "\n";
    }
}
