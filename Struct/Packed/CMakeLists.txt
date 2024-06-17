set(CMAKE_CXX_STANDARD 20)

add_library(packed OBJECT PackException.cpp PFestId.cpp PString.cpp FestUuid.cpp FestUuidList.cpp POppf.cpp
        PValueWithDistinguishedName.cpp PLegemiddelMerkevare.cpp PValueWithCodeset.cpp PPreparatomtaleavsnitt.cpp
        PReseptgyldighet.cpp ReseptgyldighetList.cpp PLenke.cpp PLegemiddel.cpp PAdministreringLegemiddel.cpp
        ValueWithCodesetList.cpp PLegemiddelCore.cpp ValueWithDistinguishedNameList.cpp POppfLegemiddelMerkevare.cpp
        POppfLegemiddelpakning.cpp PLegemiddelpakning.cpp PPakningsinfo.cpp PValueUnit.cpp PPakningskomponentInfo.cpp
        PakningsinfoList.cpp PPrisVare.cpp PrisVareList.cpp PMarkedsforingsinfo.cpp PRefusjon.cpp
        PPakningByttegruppe.cpp PPakningskomponent.cpp PPakningsinfo.cpp PakningskomponentList.cpp
        PLegemiddelVirkestoff.cpp POppfLegemiddelVirkestoff.cpp RefusjonList.cpp PHandelsvare.cpp PProduktInfoVare.cpp
        PLeverandor.cpp POppfHandelsvare.cpp StringList.cpp PLegemiddeldose.cpp PakningskomponentInfoList.cpp
        POppfLegemiddeldose.cpp PVirkestoffMedStyrke.cpp POppfVirkestoffMedStyrke.cpp PVirkestoff.cpp
        POppfVirkestoff.cpp PInfo.cpp PTerm.cpp POppfKodeverk.cpp POppfKodeverk_convert.cpp PElement.cpp ElementList.cpp
        PRefRefusjonsvilkar.cpp PRefusjonsgruppe.cpp RefRefusjonsvilkarList.cpp PRefusjonshjemmel.cpp POppfRefusjon.cpp
        PRefusjonskode.cpp RefusjonskodeList.cpp PStrukturertVilkar.cpp PVilkar.cpp POppfVilkar.cpp
        PReferanseelement.cpp PVarselSlv.cpp POppfVarselSlv.cpp PByttegruppe.cpp POppfByttegruppe.cpp PInteraksjon.cpp
        PReferanse.cpp ReferanseList.cpp PSubstans.cpp SubstansList.cpp PSubstansgruppe.cpp POppfInteraksjon.cpp
        SubstansgruppeList.cpp PInteraksjonIkkeVurdert.cpp POppfInteraksjonIkkeVurdert.cpp PDoseFastTidspunkt.cpp
        DoseFastTidspunktList.cpp PDosering.cpp DoseringList.cpp PLegemiddelforbruk.cpp LegemiddelforbrukList.cpp
        PKortdose.cpp POppfStrDosering.cpp PFest.cpp PFest_convert.cpp Uint16List.cpp TermList.cpp Uint32List.cpp)

include_directories(packed ${Boost_INCLUDE_DIRS} )
include_directories(packed ../../include)
