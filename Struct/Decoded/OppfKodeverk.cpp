//
// Created by sigsegv on 12/28/22.
//

#include <Struct/Decoded/OppfKodeverk.h>

Info OppfKodeverk::GetInfo() const {
    return info;
}

std::vector<Element> OppfKodeverk::GetElement() const {
    return element;
}
