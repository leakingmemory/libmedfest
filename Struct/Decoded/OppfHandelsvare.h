//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_OPPFHANDELSVARE_H
#define LEGEMFEST_OPPFHANDELSVARE_H

#include "Status.h"

class OppfHandelsvare {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
public:
    OppfHandelsvare() : id(), tidspunkt(), status() {}
    OppfHandelsvare(const std::string &id, const std::string &tidspunkt, const Status &status) :
            id(id), tidspunkt(tidspunkt), status(status) {}
    [[nodiscard]] std::string GetId();
    [[nodiscard]] std::string GetTidspunkt();
    [[nodiscard]] Status GetStatus();
};


#endif //LEGEMFEST_OPPFHANDELSVARE_H
