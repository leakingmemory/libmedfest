//
// Created by sigsegv on 12/9/22.
//

#include "AdministreringLegemiddel.h"

Administrasjonsvei AdministreringLegemiddel::GetAdministrasjonsvei() const {
    return administrasjonsvei;
}

EnhetDosering AdministreringLegemiddel::GetEnhetDosering() const {
    return enhetDosering;
}

std::vector<BruksomradeEtikett> AdministreringLegemiddel::GetBruksomradeEtikett() const {
    return bruksomradeEtikett;
}

KanKnuses AdministreringLegemiddel::GetKanKnuses() const {
    return kanKnuses;
}

std::vector<ForhandsregelInntak> AdministreringLegemiddel::GetForhandsregelInntak() const {
    return forhandsregelInntak;
}

std::vector<Kortdose> AdministreringLegemiddel::GetKortdose() const {
    return kortdose;
}

Deling AdministreringLegemiddel::GetDeling() const {
    return deling;
}
