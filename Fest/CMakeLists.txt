set(CMAKE_CXX_STANDARD 20)

add_library(fest OBJECT Fest.cpp Fest.h FestIdObject.cpp FestIdObject.h
        KatLegemiddelMerkevare.cpp KatLegemiddelMerkevare.h TidspunktObject.cpp TidspunktObject.h
        StatusObject.cpp StatusObject.h XmlLegemiddelMerkevare.cpp XmlLegemiddelMerkevare.h
        XmlLegemiddel.cpp XmlLegemiddel.h XmlValueWithDistinguishedName.h XmlValueWithCodeSet.h XmlContentElement.h
        XmlPreparattypeObject.cpp XmlPreparattypeObject.h XmlAdministreringLegemiddel.cpp XmlAdministreringLegemiddel.h
        XmlSortertVirkestoffMedStyrke.cpp XmlSortertVirkestoffMedStyrke.h XmlSortering.cpp XmlSortering.h
        XmlRefVirkestoffMedStyrke.cpp XmlRefVirkestoffMedStyrke.h XmlProduktInfo.cpp XmlProduktInfo.h
        XmlReseptgyldighet.cpp XmlReseptgyldighet.h XmlVarighet.cpp XmlVarighet.h)
