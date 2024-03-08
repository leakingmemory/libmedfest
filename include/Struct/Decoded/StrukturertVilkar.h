//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_STRUKTURERTVILKAR_H
#define LEGEMFEST_STRUKTURERTVILKAR_H

#include "ValueWithCodeSet.h"

class StrukturertVilkar {
private:
    ValueWithCodeSet type;
    ValueWithCodeSet verdiKodet;
    std::string verdiTekst;
public:
    StrukturertVilkar() : type(), verdiKodet(), verdiTekst() {}
    StrukturertVilkar(const ValueWithCodeSet &type, const ValueWithCodeSet &verdiKodet, const std::string &verdiTekst) :
            type(type), verdiKodet(verdiKodet), verdiTekst(verdiTekst) {}
    [[nodiscard]] ValueWithCodeSet GetType() const;
    [[nodiscard]] ValueWithCodeSet GetVerdiKodet() const;
    [[nodiscard]] std::string GetVerdiTekst() const;
};


#endif //LEGEMFEST_STRUKTURERTVILKAR_H
