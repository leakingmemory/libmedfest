//
// Created by sigsegv on 12/24/22.
//

#include <Struct/Decoded/Refusjonshjemmel.h>

ValueWithCodeSet Refusjonshjemmel::GetRefusjonshjemmel() const {
    return refusjonshjemmel;
}

bool Refusjonshjemmel::GetKreverVarekobling() const {
    return kreverVarekobling;
}

bool Refusjonshjemmel::GetKreverVedtak() const {
    return kreverVedtak;
}

std::vector<Refusjonsgruppe> Refusjonshjemmel::GetRefusjonsgruppeList() const {
    return refusjonsgruppe;
}

Refusjonsgruppe Refusjonshjemmel::GetRefusjonsgruppe() const {
    if (!refusjonsgruppe.empty()) {
        return refusjonsgruppe.back();
    }
    return {};
}
