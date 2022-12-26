set(CMAKE_CXX_STANDARD 20)

add_library(decoded OBJECT Status.cpp Status.h OppfLegemiddelMerkevare.cpp OppfLegemiddelMerkevare.h
        LegemiddelMerkevare.cpp LegemiddelMerkevare.h Atc.h Legemiddel.cpp Legemiddel.h Reseptgruppe.h
        ValueWithDistinguishedName.cpp ValueWithDistinguishedName.h ValueWithCodeSet.cpp ValueWithCodeSet.h
        LegemiddelformKort.h Preparattype.h AdministreringLegemiddel.cpp AdministreringLegemiddel.h
        Administrasjonsvei.h Preparatomtaleavsnitt.cpp Preparatomtaleavsnitt.h Reseptgyldighet.cpp Reseptgyldighet.h
        LegemiddelCore.cpp LegemiddelCore.h Legemiddelpakning.cpp Legemiddelpakning.h
        OppfLegemiddelpakning.cpp OppfLegemiddelpakning.h Pakningsinfo.cpp Pakningsinfo.h ValueUnit.cpp ValueUnit.h
        Markedsforingsinfo.cpp Markedsforingsinfo.h PrisVare.cpp PrisVare.h Pakningskomponent.cpp Pakningskomponent.h
        Refusjon.cpp Refusjon.h PakningByttegruppe.cpp PakningByttegruppe.h OppfVirkestoff.cpp OppfVirkestoff.h
        Virkestoff.cpp Virkestoff.h Styrke.cpp Styrke.h Styrkenevner.cpp Styrkenevner.h
        Styrkeoperator.cpp Styrkeoperator.h VirkestoffMedStyrke.cpp VirkestoffMedStyrke.h
        OppfVirkestoffMedStyrke.cpp OppfVirkestoffMedStyrke.h OppfLegemiddelVirkestoff.cpp OppfLegemiddelVirkestoff.h
        LegemiddelVirkestoff.cpp LegemiddelVirkestoff.h OppfHandelsvare.cpp OppfHandelsvare.h
        Handelsvare.cpp Handelsvare.h  ProduktInfoVare.cpp ProduktInfoVare.h Leverandor.cpp Leverandor.h
        OppfRefusjon.cpp OppfRefusjon.h Refusjonshjemmel.cpp Refusjonshjemmel.h Refusjonsgruppe.cpp Refusjonsgruppe.h
        RefRefusjonsvilkar.cpp RefRefusjonsvilkar.h OppfVilkar.cpp OppfVilkar.h Vilkar.cpp Vilkar.h)
