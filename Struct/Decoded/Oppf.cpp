//
// Created by sigsegv on 1/9/23.
//

#include <Struct/Decoded/Oppf.h>

std::string Oppf::GetId() const {
    return id;
}

std::string Oppf::GetTidspunkt() const {
    return tidspunkt;
}

Status Oppf::GetStatus() const {
    return status;
}
