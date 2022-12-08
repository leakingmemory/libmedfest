//
// Created by jeo on 12/8/22.
//

#include "FestObjectStream.h"
#include <iostream>

void FestObjectStream::read() {
    int num = source->read(&(buf[0]), sizeof(buf));
    if (num < 0) {
        std::cerr << "Read error, xml stream\n";
    }
    std::cout << "Read " << num << " bytes\n";
}