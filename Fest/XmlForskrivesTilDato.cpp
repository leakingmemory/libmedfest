//
// Created by sigsegv on 12/25/22.
//

#include "XmlForskrivesTilDato.h"

void XmlForskrivesTilDato::SetForskrivesTilDato(const std::string &forskrivesTilDato) {
    this->forskrivesTilDato = forskrivesTilDato;
}

std::string XmlForskrivesTilDato::GetForskrivesTilDato() const {
    return forskrivesTilDato;
}

bool XmlForskrivesTilDatoHandler::Merge(std::shared_ptr<XmlForskrivesTilDato> parent, const std::string &content) {
    parent->SetForskrivesTilDato(content);
    return true;
}
