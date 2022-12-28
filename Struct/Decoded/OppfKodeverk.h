//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_OPPFKODEVERK_H
#define LEGEMFEST_OPPFKODEVERK_H

#include "Status.h"
#include "Info.h"
#include "Element.h"
#include <vector>

class OppfKodeverk {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Info info;
    std::vector<Element> element;
public:
    OppfKodeverk() : id(), tidspunkt(), status(), info(), element() {}
    OppfKodeverk(const std::string &id, const std::string &tidspunkt, const Status &status, const Info &info,
                 const std::vector<Element> &element) :
            id(id), tidspunkt(tidspunkt), status(status), info(info), element(element) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Info GetInfo() const;
    [[nodiscard]] std::vector<Element> GetElement() const;
};


#endif //LEGEMFEST_OPPFKODEVERK_H
