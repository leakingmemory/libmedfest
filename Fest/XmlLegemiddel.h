//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDEL_H
#define LEGEMFEST_XMLLEGEMIDDEL_H


#include "XmlLegemiddelCore.h"
#include "../Struct/Decoded/AdministreringLegemiddel.h"

class XmlLegemiddel : public XmlLegemiddelCore, public XmlSortertVirkestoffMedStyrke {
private:
    AdministreringLegemiddel administreringLegemiddel{};
public:
    virtual ~XmlLegemiddel() = default;
    [[nodiscard]] AdministreringLegemiddel GetAdministreringLegemiddel() const;
    void SetAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel);
};

#endif //LEGEMFEST_XMLLEGEMIDDEL_H
