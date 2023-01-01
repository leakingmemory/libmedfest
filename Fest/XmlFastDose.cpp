//
// Created by sigsegv on 1/1/23.
//

#include "XmlFastDose.h"
#include "XmlDoseFastTidspunkt.h"
#include <iostream>

std::string XmlFastDose::GetName() const {
    return "FastDose";
}

void XmlFastDose::SetDagerPa(int dagerPa) {
    this->dagerPa = dagerPa;
}

void XmlFastDose::SetDagerAv(int dagerAv) {
    this->dagerAv = dagerAv;
}

bool XmlFastDose::Merge() {
    return parent->SetFastDose({dagerPa, dagerAv});
}

std::shared_ptr<XMLObject> XmlFastDoseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlDoseFastTidspunkt> typedParent = std::dynamic_pointer_cast<XmlDoseFastTidspunkt>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected FastDose\n";
        return {};
    }
    return std::make_shared<XmlFastDose>(typedParent);
}

bool XmlFastDoseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *f = dynamic_cast<XmlFastDose *>(&(*obj));
    if (f == nullptr) {
        std::cerr << "Error: Not ending FastDose\n";
        return false;
    }
    return f->Merge();
}

bool XmlDagerPaHandler::Merge(std::shared_ptr<XmlFastDose> parent, const std::string &content) {
    char *err;
    long lvalue = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: DagerPa: Invalid value: " << content << "\n";
        return false;
    }
    int value = (int) lvalue;
    if (((long) value) != lvalue) {
        std::cerr << "Error: DagerPa: Invalid value: " << content << " (overflow)\n";
        return false;
    }
    parent->SetDagerPa(value);
    return true;
}

bool XmlDagerAvHandler::Merge(std::shared_ptr<XmlFastDose> parent, const std::string &content) {
    char *err;
    long lvalue = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: DagerAv: Invalid value: " << content << "\n";
        return false;
    }
    int value = (int) lvalue;
    if (((long) value) != lvalue) {
        std::cerr << "Error: DagerAv: Invalid value: " << content << " (overflow)\n";
        return false;
    }
    parent->SetDagerAv(value);
    return true;
}
