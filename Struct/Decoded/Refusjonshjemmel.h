//
// Created by sigsegv on 12/24/22.
//

#ifndef LEGEMFEST_REFUSJONSHJEMMEL_H
#define LEGEMFEST_REFUSJONSHJEMMEL_H

#include "ValueWithCodeSet.h"
#include "Refusjonsgruppe.h"

class Refusjonshjemmel {
private:
    ValueWithCodeSet refusjonshjemmel;
    bool kreverVarekobling;
    bool kreverVedtak;
    Refusjonsgruppe refusjonsgruppe;
public:
    Refusjonshjemmel() : refusjonshjemmel(), kreverVarekobling(), kreverVedtak(), refusjonsgruppe() {}
    Refusjonshjemmel(const ValueWithCodeSet &refusjonshjemmel, bool kreverVarekobling, bool kreverVedtak,
                     const Refusjonsgruppe &refusjonsgruppe) :
            refusjonshjemmel(refusjonshjemmel), kreverVarekobling(kreverVarekobling), kreverVedtak(kreverVedtak),
            refusjonsgruppe(refusjonsgruppe) {}
    [[nodiscard]] ValueWithCodeSet GetRefusjonshjemmel() const;
    [[nodiscard]] bool GetKreverVarekobling() const;
    [[nodiscard]] bool GetKreverVedtak() const;
    [[nodiscard]] Refusjonsgruppe GetRefusjonsgruppe() const;
};


#endif //LEGEMFEST_REFUSJONSHJEMMEL_H
