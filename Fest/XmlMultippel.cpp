//
// Created by sigsegv on 12/16/22.
//

#include "XmlMultippel.h"
#include <cstdlib>

void XmlMultippel::SetMultippel(int multippel) {
    this->multippel = multippel;
}

int XmlMultippel::GetMultippel() const {
    return multippel;
}

bool XmlMultippelHandler::Merge(std::shared_ptr<XmlMultippel> parent, const std::string &content) {
    char *err;
    long lvalue = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Multippel: Invalid value: " << content << "\n";
        return false;
    }
    int value = (int) lvalue;
    if (((long) value) != lvalue) {
        std::cerr << "Error: Multippel: Invalid value: " << content << " (overflow)\n";
        return false;
    }
    parent->SetMultippel(value);
    return true;
}