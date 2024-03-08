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
public:
    RefRefusjonsvilkar() : id(), fraDato() {}
    RefRefusjonsvilkar(const std::string &id, const std::string &fraDato) : id(id), fraDato(fraDato) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetFraDato() const;
};


#endif //LEGEMFEST_REFREFUSJONSVILKAR_H
