//
// Created by sigsegv on 5/14/24.
//

#include "XmlUtleveresTilDato.h"

void XmlUtleveresTilDato::SetUtleveresTilDato(const std::string &utleveresTilDato) {
    this->utleveresTilDato = utleveresTilDato;
}

std::string XmlUtleveresTilDato::GetUtleveresTilDato() const {
    return utleveresTilDato;
}

bool XmlUtleveresTilDatoHandler::Merge(std::shared_ptr<XmlUtleveresTilDato> parent, const std::string &content) {
    parent->SetUtleveresTilDato(content);
    return true;
}
