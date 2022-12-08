//
// Created by jeo on 12/8/22.
//

#include "FestObjectStream.h"
#include "XMLParser.h"
#include "Fest/Fest.h"
#include <iostream>

void FestObjectStream::read() {
    XMLParser parser{};
    parser.AddHandler("FEST", std::make_shared<FestHandler>());
    parser.AddHandler("HentetDato", std::make_shared<HentetDatoHandler>());
    do {
        int num = source->read(&(buf[0]), sizeof(buf));
        if (num < 0) {
            std::cerr << "Read error, xml stream\n";
            return;
        }
        if (num == 0) {
            break;
        }
        std::cout << "Read " << num << " bytes\n";
        if (!parser.ParseBuffer(&(buf[0]), num, false)) {
            std::cerr << "XML Parse error\n";
            return;
        }
    } while (true);
    parser.ParseBuffer(nullptr, 0, true);
}