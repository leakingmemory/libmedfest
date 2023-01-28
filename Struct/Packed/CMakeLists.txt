set(CMAKE_CXX_STANDARD 20)

add_library(packed OBJECT PackException.cpp PackException.h PFestId.cpp PFestId.h PString.cpp PString.h
        FestUuid.cpp FestUuid.h FestUuidList.cpp FestUuidList.h GenericListStorage.h POppf.cpp POppf.h
        PValueWithDistinguishedName.cpp PValueWithDistinguishedName.h PLegemiddelMerkevare.cpp PLegemiddelMerkevare.h
        PValueWithCodeset.cpp PValueWithCodeset.h PPreparatomtaleavsnitt.cpp PPreparatomtaleavsnitt.h
        PReseptgyldighet.cpp PReseptgyldighet.h ReseptgyldighetList.cpp ReseptgyldighetList.h PLenke.cpp PLenke.h
        PLegemiddel.cpp PLegemiddel.h PAdministreringLegemiddel.cpp PAdministreringLegemiddel.h
        ValueWithCodesetList.cpp ValueWithCodesetList.h PLegemiddelCore.cpp PLegemiddelCore.h
        ValueWithDistinguishedNameList.cpp ValueWithDistinguishedNameList.h
        POppfLegemiddelMerkevare.cpp POppfLegemiddelMerkevare.h POppfLegemiddelpakning.cpp POppfLegemiddelpakning.h
        PLegemiddelpakning.cpp PLegemiddelpakning.h PPakningsinfo.cpp PPakningsinfo.h PValueUnit.cpp PValueUnit.h
        PPakningskomponentInfo.cpp PPakningskomponentInfo.h PakningsinfoList.cpp PakningsinfoList.h
        PPrisVare.cpp PPrisVare.h PrisVareList.cpp PrisVareList.h PMarkedsforingsinfo.cpp PMarkedsforingsinfo.h
        PRefusjon.cpp PRefusjon.h PPakningByttegruppe.cpp PPakningByttegruppe.h
        PPakningskomponent.cpp PPakningskomponent.h PPakningsinfo.cpp PPakningsinfo.h
        PakningskomponentList.cpp PakningskomponentList.h PLegemiddelVirkestoff.cpp PLegemiddelVirkestoff.h
        POppfLegemiddelVirkestoff.cpp POppfLegemiddelVirkestoff.h RefusjonList.cpp RefusjonList.h)

include_directories(packed ${Boost_INCLUDE_DIRS} )