//
// Created by sigsegv on 12/27/22.
//

#include "XmlFraDato.h"

void XmlFraDato::SetFraDato(const std::string &fraDato) {
    this->fraDato = fraDato;
}

std::string XmlFraDato::GetFraDato() const {
    return fraDato;
}

bool XmlFraDatoHandler::Merge(std::shared_ptr<XmlFraDato> parent, const std::string &content) {
    parent->SetFraDato(content);
    return true;
}