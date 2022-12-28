//
// Created by sigsegv on 12/28/22.
//

#include "XmlInfo.h"
#include "KatKodeverk.h"
#include <iostream>

std::string XmlInfo::GetName() const {
    return "Info";
}

void XmlInfo::SetBetegnelse(const std::string &betegnelse) {
    this->betegnelse = betegnelse;
}

void XmlInfo::SetKortnavn(const std::string &kortnavn) {
    this->kortnavn = kortnavn;
}

void XmlInfo::SetAnsvarligUtgiver(const std::string &ansvarligUtgiver) {
    this->ansvarligUtgiver = ansvarligUtgiver;
}

bool XmlInfo::Merge() {
    parent->SetInfo({GetId(), betegnelse, kortnavn, ansvarligUtgiver});
    return true;
}

std::shared_ptr<XMLObject> XmlInfoHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                        const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlOppfKodeverk> typedParent = std::dynamic_pointer_cast<XmlOppfKodeverk>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Info\n";
        return {};
    }
    return std::make_shared<XmlInfo>(typedParent);
}

bool XmlInfoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *i = dynamic_cast<XmlInfo *>(&(*obj));
    if (i == nullptr) {
        std::cerr << "Error: Not ending Info\n";
        return false;
    }
    return i->Merge();
}

bool XmlBetegnelseHandler::Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) {
    parent->SetBetegnelse(content);
    return true;
}

bool XmlKortnavnHandler::Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) {
    parent->SetKortnavn(content);
    return true;
}

bool XmlAnsvarligUtgiverHandler::Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) {
    parent->SetAnsvarligUtgiver(content);
    return true;
}
