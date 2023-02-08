set(CMAKE_CXX_STANDARD 20)

add_library(decoded OBJECT Status.h OppfLegemiddelMerkevare.cpp OppfLegemiddelMerkevare.h
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
        RefRefusjonsvilkar.cpp RefRefusjonsvilkar.h OppfVilkar.cpp OppfVilkar.h Vilkar.cpp Vilkar.h
        OppfVarselSlv.cpp OppfVarselSlv.h VarselSlv.cpp VarselSlv.h Lenke.cpp Lenke.h
        Referanseelement.cpp Referanseelement.h OppfKodeverk.cpp OppfKodeverk.h Element.cpp Element.h Term.cpp Term.h
        OppfByttegruppe.cpp OppfByttegruppe.h Byttegruppe.cpp Byttegruppe.h OppfLegemiddeldose.cpp OppfLegemiddeldose.h
        Legemiddeldose.cpp Legemiddeldose.h PakningskomponentInfo.cpp PakningskomponentInfo.h
        OppfInteraksjonBase.cpp OppfInteraksjonBase.h Interaksjon.cpp Interaksjon.h
        OppfInteraksjon.cpp OppfInteraksjon.h Referanse.cpp Referanse.h Substansgruppe.cpp Substansgruppe.h
        Substans.cpp Substans.h InteraksjonIkkeVurdert.cpp InteraksjonIkkeVurdert.h
        OppfStrDosering.cpp OppfStrDosering.h Kortdose.cpp Kortdose.h Legemiddelforbruk.cpp Legemiddelforbruk.h
        DoseFastTidspunkt.cpp DoseFastTidspunkt.h Dosering.cpp Dosering.h FastDose.cpp FastDose.h Oppf.cpp Oppf.h
        Info.cpp Info.h Refusjonskode.cpp Refusjonskode.h)
