//
// Created by sigsegv on 2/6/23.
//

#include "PRefusjonshjemmel.h"
#include "../Decoded/Refusjonshjemmel.h"

PRefusjonshjemmel::PRefusjonshjemmel(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList &refusjonskodeList,
                                     RefRefusjonsvilkarList &refRefusjonsvilkarList, StringList &stringList,
                                     std::vector<FestUuid> &idblock, std::string &strblock,
                                     std::map<std::string, uint32_t> &cache) :
        PRefusjonsgruppe(refusjonshjemmel.refusjonsgruppe, refusjonskodeList, refRefusjonsvilkarList, stringList, idblock, strblock, cache),
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{}
