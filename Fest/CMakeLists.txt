set(CMAKE_CXX_STANDARD 20)

add_library(fest OBJECT Fest.cpp FestIdObject.cpp FestIdObject.h KatLegemiddelMerkevare.cpp KatLegemiddelMerkevare.h
        TidspunktObject.cpp TidspunktObject.h StatusObject.cpp StatusObject.h
        XmlLegemiddelMerkevare.cpp XmlLegemiddelMerkevare.h XmlLegemiddel.cpp XmlLegemiddel.h
        XmlValueWithDistinguishedName.h XmlValueWithCodeSet.h XmlContentElement.h
        XmlPreparattypeObject.cpp XmlPreparattypeObject.h XmlAdministreringLegemiddel.cpp XmlAdministreringLegemiddel.h
        XmlSortertVirkestoffMedStyrke.cpp XmlSortertVirkestoffMedStyrke.h XmlSortering.cpp XmlSortering.h
        XmlRefVirkestoffMedStyrke.cpp XmlRefVirkestoffMedStyrke.h XmlProduktInfo.cpp XmlProduktInfo.h
        XmlReseptgyldighet.cpp XmlReseptgyldighet.h XmlVarighet.cpp XmlVarighet.h
        XmlPreparatomtaleavsnitt.cpp XmlPreparatomtaleavsnitt.h XmlRefVirkestoff.cpp XmlRefVirkestoff.h
        XmlSortertVirkestoffUtenStyrke.cpp XmlSortertVirkestoffUtenStyrke.h XmlKjonn.cpp XmlKjonn.h
        XmlLegemiddelCore.cpp XmlLegemiddelCore.h KatLegemiddelpakning.cpp KatLegemiddelpakning.h
        XmlLegemiddelpakning.cpp XmlLegemiddelpakning.h XmlPakningsinfo.cpp XmlPakningsinfo.h
        XmlRefLegemiddelMerkevare.cpp XmlRefLegemiddelMerkevare.h XmlMarkedsforingsinfo.cpp XmlMarkedsforingsinfo.h
        XmlPrisVare.cpp XmlPrisVare.h XmlPakningskomponent.cpp XmlPakningskomponent.h XmlType.cpp XmlType.h
        XmlPakningstype.cpp XmlPakningstype.h XmlMengde.cpp XmlMengde.h XmlRefusjon.cpp XmlRefusjon.h
        XmlGyldigFraDato.cpp XmlGyldigFraDato.h XmlPakningByttegruppe.cpp XmlPakningByttegruppe.h
        XmlGyldigTilDato.cpp XmlGyldigTilDato.h XmlAntall.cpp XmlAntall.h XmlMultippel.cpp XmlMultippel.h
        KatVirkestoff.cpp KatVirkestoff.h XmlVirkestoff.cpp XmlVirkestoff.h XmlNavn.cpp XmlNavn.h
        XmlNavnEngelsk.cpp XmlNavnEngelsk.h XmlVirkestoffMedStyrke.cpp XmlVirkestoffMedStyrke.h
        KatLegemiddelVirkestoff.cpp KatLegemiddelVirkestoff.h XmlLegemiddelVirkestoff.cpp XmlLegemiddelVirkestoff.h
        XmlRefPakning.cpp XmlRefPakning.h KatHandelsvare.cpp KatHandelsvare.h XmlHandelsvare.cpp XmlHandelsvare.h
        XmlProduktInfoVare.cpp XmlProduktInfoVare.h XmlLeverandor.cpp XmlLeverandor.h KatRefusjon.cpp KatRefusjon.h
        XmlRefusjonshjemmel.cpp XmlRefusjonshjemmel.h XmlRefusjonsgruppe.cpp XmlRefusjonsgruppe.h XmlAtc.cpp XmlAtc.h
        XmlRefusjonskode.cpp XmlRefusjonskode.h XmlRefusjonsvilkar.cpp XmlRefusjonsvilkar.h KatVilkar.cpp KatVilkar.h
        XmlRefVilkar.cpp XmlRefVilkar.h XmlForskrivesTilDato.cpp XmlForskrivesTilDato.h XmlVilkar.cpp XmlVilkar.h
        KatVarselSlv.cpp KatVarselSlv.h XmlVarselSlv.cpp XmlVarselSlv.h XmlFraDato.cpp XmlFraDato.h
        XmlLenke.cpp XmlLenke.h XmlReferanseelement.cpp XmlReferanseelement.h KatKodeverk.cpp KatKodeverk.h
        XmlInfo.cpp XmlInfo.h XmlElement.cpp XmlElement.h KatByttegruppe.cpp KatByttegruppe.h XmlKode.cpp XmlKode.h
        XmlByttegruppe.cpp XmlByttegruppe.h KatLegemiddeldose.cpp KatLegemiddeldose.h
        XmlLegemiddeldose.cpp XmlLegemiddeldose.h KatInteraksjon.cpp KatInteraksjon.h
        XmlInteraksjon.cpp XmlInteraksjon.h XmlVisningsregel.cpp XmlVisningsregel.h XmlReferanse.cpp XmlReferanse.h
        XmlSubstansgruppe.cpp XmlSubstansgruppe.h XmlSubstans.cpp XmlSubstans.h
        XmlInteraksjonIkkeVurdert.cpp XmlInteraksjonIkkeVurdert.h KatStrDosering.cpp KatStrDosering.h
        XmlKortdose.cpp XmlKortdose.h XmlBeskrivelseTerm.cpp XmlBeskrivelseTerm.h
        XmlLegemiddelforbruk.cpp XmlLegemiddelforbruk.h XmlDosering.cpp XmlDosering.h
        XmlDoseFastTidspunkt.cpp XmlDoseFastTidspunkt.h XmlFastDose.cpp XmlFastDose.h)

include_directories(fest ${Boost_INCLUDE_DIRS} )
include_directories(fest ../include)