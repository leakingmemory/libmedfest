//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_REFREFUSJONSVILKAR_H
#define LEGEMFEST_REFREFUSJONSVILKAR_H

#include <string>

class RefRefusjonsvilkar {
private:
    std::string id;
    std::string fraDato;
    std::string tilDato;
public:
    RefRefusjonsvilkar() : id(), fraDato(), tilDato() {}
    RefRefusjonsvilkar(const std::string &id, const std::string &fraDato, const std::string &tilDato) : id(id), fraDato(fraDato), tilDato(tilDato) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetFraDato() const;
    [[nodiscard]] std::string GetTilDato() const;
};


#endif //LEGEMFEST_REFREFUSJONSVILKAR_H
