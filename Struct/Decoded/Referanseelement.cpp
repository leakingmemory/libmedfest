//
// Created by sigsegv on 12/27/22.
//

#include <Struct/Decoded/Referanseelement.h>

Klasse Referanseelement::GetKlasse() const {
    return klasse;
}

std::vector<std::string> Referanseelement::GetRefs() const {
    return refs;
}