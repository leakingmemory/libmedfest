//
// Created by sigsegv on 12/11/22.
//

#include "Preparatomtaleavsnitt.h"

ValueWithDistinguishedName Preparatomtaleavsnitt::GetAvsnittoverskrift() const {
    return avsnittoverskrift;
}

std::string Preparatomtaleavsnitt::GetLink() const {
    return link;
}