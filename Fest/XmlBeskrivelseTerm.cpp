//
// Created by sigsegv on 12/30/22.
//

#include "XmlBeskrivelseTerm.h"

void XmlBeskrivelseTerm::SetBeskrivelseTerm(const std::string &beskrivelseTerm) {
    this->beskrivelseTerm = beskrivelseTerm;
}

std::string XmlBeskrivelseTerm::GetBeskrivelseTerm() const {
    return beskrivelseTerm;
}

bool XmlBeskrivelseTermHandler::Merge(std::shared_ptr<XmlBeskrivelseTerm> parent, const std::string &content) {
    parent->SetBeskrivelseTerm(content);
    return true;
}
