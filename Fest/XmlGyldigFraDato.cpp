//
// Created by sigsegv on 12/14/22.
//

#include "XmlGyldigFraDato.h"

void XmlGyldigFraDato::SetGyldigFraDato(const std::string &gyldigFraDato) {
    this->gyldigFraDato = gyldigFraDato;
}

std::string XmlGyldigFraDato::GetGyldigFraDato() const {
    return gyldigFraDato;
}

bool XmlGyldigFraDatoHandler::Merge(std::shared_ptr<XmlGyldigFraDato> parent, const std::string &content) {
    parent->SetGyldigFraDato(content);
    return true;
}
