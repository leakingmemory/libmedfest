//
// Created by sigsegv on 12/24/22.
//

#ifndef LEGEMFEST_REFUSJONSHJEMMEL_H
#define LEGEMFEST_REFUSJONSHJEMMEL_H

#include "ValueWithCodeSet.h"
#include "Refusjonsgruppe.h"

class PRefusjonshjemmel_0_0_0;
class PRefusjonshjemmel_1_4_0;

class Refusjonshjemmel {
    friend PRefusjonshjemmel_0_0_0;
    friend PRefusjonshjemmel_1_4_0;
private:
    ValueWithCodeSet refusjonshjemmel;
    bool kreverVarekobling;
    bool kreverVedtak;
    std::vector<Refusjonsgruppe> refusjonsgruppe;
public:
    Refusjonshjemmel() : refusjonshjemmel(), kreverVarekobling(), kreverVedtak(), refusjonsgruppe() {}
    Refusjonshjemmel(const ValueWithCodeSet &refusjonshjemmel, bool kreverVarekobling, bool kreverVedtak,
                     const std::vector<Refusjonsgruppe> &refusjonsgruppe) :
            refusjonshjemmel(refusjonshjemmel), kreverVarekobling(kreverVarekobling), kreverVedtak(kreverVedtak),
            refusjonsgruppe(refusjonsgruppe) {}
    [[nodiscard]] ValueWithCodeSet GetRefusjonshjemmel() const;
    [[nodiscard]] bool GetKreverVarekobling() const;
    [[nodiscard]] bool GetKreverVedtak() const;
    [[nodiscard]] std::vector<Refusjonsgruppe> GetRefusjonsgruppeList() const;
    [[nodiscard]] [[deprecated]] Refusjonsgruppe GetRefusjonsgruppe() const;
};


#endif //LEGEMFEST_REFUSJONSHJEMMEL_H
