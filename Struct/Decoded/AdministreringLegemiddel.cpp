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

std::vector<ValueWithCodeSet> AdministreringLegemiddel::GetKortdose() const {
    return kortdose;
}

Deling AdministreringLegemiddel::GetDeling() const {
    return deling;
}

KanApnes AdministreringLegemiddel::GetKanApnes() const {
    return kanApnes;
}

Bolus AdministreringLegemiddel::GetBolus() const {
    return bolus;
}

InjeksjonshastighetBolus AdministreringLegemiddel::GetInjeksjonshastighetBolus() const {
    return injeksjonshastighetBolus;
}

MaybeBoolean AdministreringLegemiddel::GetBlandingsveske() {
    return blandingsveske;
}