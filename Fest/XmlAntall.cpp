//
// Created by sigsegv on 12/15/22.
//

#include "XmlAntall.h"

void XmlAntall::SetAntall(int antall) {
    this->antall = antall;
}

int XmlAntall::GetAntall() const {
    return antall;
}

bool XmlAntallHandler::Merge(std::shared_ptr<XmlAntall> parent, const std::string &content) {
    char *err;
    double lval = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: Antall: Invalid value (int): " << content << "\n";
        return false;
    }
    int val = (int) lval;
    if (((long) val) != lval) {
        std::cerr << "Error: Antall: Invalid value (int): " << content << " (overflow)\n";
        return false;
    }
    parent->SetAntall(val);
    return true;
}