//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddel.h"

AdministreringLegemiddel XmlLegemiddel::GetAdministreringLegemiddel() const {
    return administreringLegemiddel;
}

void XmlLegemiddel::SetAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel) {
    this->administreringLegemiddel = administreringLegemiddel;
}
