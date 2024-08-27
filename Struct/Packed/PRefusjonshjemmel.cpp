//
// Created by sigsegv on 2/6/23.
//

#include <Struct/Packed/PRefusjonshjemmel.h>
#include <Struct/Decoded/Refusjonshjemmel.h>

PRefusjonshjemmel::PRefusjonshjemmel(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_0_0 &refusjonskodeList_0_0_0, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                     RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                                     std::vector<FestUuid> &idblock, std::string &strblock,
                                     std::map<std::string, uint32_t> &cache) :
        PRefusjonsgruppe(refusjonshjemmel.refusjonsgruppe, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache),
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{}

PRefusjonshjemmel::PRefusjonshjemmel(const Refusjonshjemmel &refusjonshjemmel, RefusjonskodeList_0_1_0 &refusjonskodeList_0_1_0, RefusjonskodeList_1_2_0 &refusjonskodeList_1_2_0,
                                     RefRefusjonsvilkarList_0_0_0 &refRefusjonsvilkarList_0_0_0, RefRefusjonsvilkarList_1_2_0 &refRefusjonsvilkarList_1_2_0, StringList &stringList,
                                     std::vector<FestUuid> &idblock, std::string &strblock,
                                     std::map<std::string, uint32_t> &cache) :
        PRefusjonsgruppe(refusjonshjemmel.refusjonsgruppe, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, idblock, strblock, cache),
        refusjonshjemmel(refusjonshjemmel.refusjonshjemmel, strblock, cache),
        kreverVarekobling(refusjonshjemmel.kreverVarekobling),
        kreverVedtak(refusjonshjemmel.kreverVedtak)
{}

bool PRefusjonshjemmel::operator==(const PRefusjonshjemmel &other) const {
    return PRefusjonsgruppe::operator==(other) &&
           refusjonshjemmel == other.refusjonshjemmel &&
           kreverVarekobling == other.kreverVarekobling &&
           kreverVedtak == other.kreverVedtak;
}
