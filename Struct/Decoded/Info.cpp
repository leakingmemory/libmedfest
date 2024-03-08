//
// Created by sigsegv on 12/28/22.
//

#include <Struct/Decoded/Info.h>

std::string Info::GetId() const {
    return id;
}

std::string Info::GetBetegnelse() const {
    return betegnelse;
}

std::string Info::GetKortnavn() const {
    return kortnavn;
}

std::string Info::GetAnsvarligUtgiver() const {
    return ansvarligUtgiver;
}