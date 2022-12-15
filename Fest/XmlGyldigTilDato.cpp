//
// Created by sigsegv on 12/15/22.
//

#include "XmlGyldigTilDato.h"

void XmlGyldigTilDato::SetGyldigTilDato(const std::string &gyldigTilDato) {
    this->gyldigTilDato = gyldigTilDato;
}

std::string XmlGyldigTilDato::GetGyldigTilDato() const {
    return gyldigTilDato;
}

bool XmlGyldigTilDatoHandler::Merge(std::shared_ptr<XmlGyldigTilDato> parent, const std::string &content) {
    parent->SetGyldigTilDato(content);
    return true;
}
