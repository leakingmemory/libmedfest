//
// Created by sigsegv on 12/28/22.
//

#include "OppfKodeverk.h"

std::string OppfKodeverk::GetId() const {
    return id;
}

std::string OppfKodeverk::GetTidspunkt() const {
    return tidspunkt;
}

Status OppfKodeverk::GetStatus() const {
    return status;
}

Info OppfKodeverk::GetInfo() const {
    return info;
}

std::vector<Element> OppfKodeverk::GetElement() const {
    return element;
}
