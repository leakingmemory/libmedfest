set(CMAKE_CXX_STANDARD 20)

add_library(decoded OBJECT OppfLegemiddelMerkevare.cpp LegemiddelMerkevare.cpp Legemiddel.cpp
        ValueWithDistinguishedName.cpp ValueWithCodeSet.cpp AdministreringLegemiddel.cpp Preparatomtaleavsnitt.cpp
        Reseptgyldighet.cpp LegemiddelCore.cpp Legemiddelpakning.cpp OppfLegemiddelpakning.cpp Pakningsinfo.cpp
        ValueUnit.cpp Markedsforingsinfo.cpp PrisVare.cpp Pakningskomponent.cpp Refusjon.cpp PakningByttegruppe.cpp
        OppfVirkestoff.cpp Virkestoff.cpp Styrke.cpp Styrkenevner.cpp Styrkeoperator.cpp VirkestoffMedStyrke.cpp
        OppfVirkestoffMedStyrke.cpp OppfLegemiddelVirkestoff.cpp LegemiddelVirkestoff.cpp OppfHandelsvare.cpp
        Handelsvare.cpp ProduktInfoVare.cpp Leverandor.cpp OppfRefusjon.cpp Refusjonshjemmel.cpp Refusjonsgruppe.cpp
        RefRefusjonsvilkar.cpp OppfVilkar.cpp Vilkar.cpp OppfVarselSlv.cpp VarselSlv.cpp Lenke.cpp Referanseelement.cpp
        OppfKodeverk.cpp Element.cpp Term.cpp OppfByttegruppe.cpp Byttegruppe.cpp OppfLegemiddeldose.cpp
        Legemiddeldose.cpp PakningskomponentInfo.cpp OppfInteraksjonBase.cpp Interaksjon.cpp OppfInteraksjon.cpp
        Referanse.cpp Substansgruppe.cpp Substans.cpp InteraksjonIkkeVurdert.cpp OppfStrDosering.cpp Kortdose.cpp
        Legemiddelforbruk.cpp DoseFastTidspunkt.cpp Dosering.cpp FastDose.cpp Oppf.cpp Info.cpp Refusjonskode.cpp
        StrukturertVilkar.cpp OppfInteraksjonIkkeVurdert.cpp)

target_include_directories(decoded PRIVATE ../../include)
