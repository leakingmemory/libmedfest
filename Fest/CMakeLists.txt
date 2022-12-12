set(CMAKE_CXX_STANDARD 20)

add_library(fest OBJECT Fest.cpp Fest.h FestIdObject.cpp FestIdObject.h
        KatLegemiddelMerkevare.cpp KatLegemiddelMerkevare.h TidspunktObject.cpp TidspunktObject.h
        StatusObject.cpp StatusObject.h XmlLegemiddelMerkevare.cpp XmlLegemiddelMerkevare.h
        XmlLegemiddel.cpp XmlLegemiddel.h XmlValueWithDistinguishedName.h XmlValueWithCodeSet.h XmlContentElement.h
        XmlPreparattypeObject.cpp XmlPreparattypeObject.h XmlAdministreringLegemiddel.cpp XmlAdministreringLegemiddel.h
        XmlSortertVirkestoffMedStyrke.cpp XmlSortertVirkestoffMedStyrke.h XmlSortering.cpp XmlSortering.h
        XmlRefVirkestoffMedStyrke.cpp XmlRefVirkestoffMedStyrke.h XmlProduktInfo.cpp XmlProduktInfo.h
        XmlReseptgyldighet.cpp XmlReseptgyldighet.h XmlVarighet.cpp XmlVarighet.h
        XmlPreparatomtaleavsnitt.cpp XmlPreparatomtaleavsnitt.h XmlRefVirkestoff.cpp XmlRefVirkestoff.h
        XmlSortertVirkestoffUtenStyrke.cpp XmlSortertVirkestoffUtenStyrke.h XmlKjonn.cpp XmlKjonn.h
        XmlLegemiddelCore.cpp XmlLegemiddelCore.h KatLegemiddelpakning.cpp KatLegemiddelpakning.h
        XmlLegemiddelpakning.cpp XmlLegemiddelpakning.h XmlPakningsinfo.cpp XmlPakningsinfo.h
        XmlRefLegemiddelMerkevare.cpp XmlRefLegemiddelMerkevare.h XmlMarkedsforingsinfo.cpp XmlMarkedsforingsinfo.h
        XmlPrisVare.cpp XmlPrisVare.h XmlPakningskomponent.cpp XmlPakningskomponent.h)
