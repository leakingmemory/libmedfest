//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_OPPFVILKAR_H
#define LEGEMFEST_OPPFVILKAR_H

#include "Status.h"
#include "Vilkar.h"

class OppfVilkar {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Vilkar vilkar;
public:
    OppfVilkar() : id(), tidspunkt(), status(), vilkar() {}
    OppfVilkar(const std::string &id, const std::string &tidspunkt, const Status &status, const Vilkar &vilkar) :
            id(id), tidspunkt(tidspunkt), status(status), vilkar(vilkar) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidpunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Vilkar GetVilkar() const;
};


#endif //LEGEMFEST_OPPFVILKAR_H
