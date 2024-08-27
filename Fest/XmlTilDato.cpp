//
// Created by sigsegv on 8/20/24.
//

#include "XmlTilDato.h"

void XmlTilDato::SetTilDato(const std::string &tilDato) {
    this->tilDato = tilDato;
}

std::string XmlTilDato::GetTilDato() const {
    return tilDato;
}

bool XmlTilDatoHandler::Merge(std::shared_ptr<XmlTilDato> parent, const std::string &content) {
    parent->SetTilDato(content);
    return true;
}