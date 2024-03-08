//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_VIRKESTOFF_H
#define LEGEMFEST_VIRKESTOFF_H

#include <string>
#include <vector>

class Virkestoff {
private:
    std::string id;
    std::string navn;
    std::string navnEngelsk;
    std::vector<std::string> refVirkestoff;
public:
    Virkestoff() : id(), navn(), navnEngelsk() {}
    Virkestoff(const std::string &id, const std::string &navn, const std::string &navnEngelsk,
               const std::vector<std::string> &refVirkestoff) :
            id(id), navn(navn), navnEngelsk(), refVirkestoff(refVirkestoff) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetNavn() const;
    [[nodiscard]] std::string GetNavnEngelsk() const;
    [[nodiscard]] std::vector<std::string> GetRefVirkestoff() const;
};


#endif //LEGEMFEST_VIRKESTOFF_H
