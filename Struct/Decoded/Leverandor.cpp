//
// Created by sigsegv on 12/20/22.
//

#include <Struct/Decoded/Leverandor.h>

std::string Leverandor::GetNavn() const {
    return navn;
}

std::string Leverandor::GetAdresse() const {
    return adresse;
}

std::string Leverandor::GetTelefon() const {
    return telefon;
}