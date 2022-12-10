//
// Created by sigsegv on 12/10/22.
//

#include "XmlVarighet.h"

void XmlVarighet::SetVarighet(const std::string &varighet) {
    this->varighet = varighet;
}

std::string XmlVarighet::GetVarighet() const {
    return varighet;
}

bool XmlVarighetHandler::Merge(std::shared_ptr<XmlVarighet> parent, const std::string &content) {
    parent->SetVarighet(content);
    return true;
}