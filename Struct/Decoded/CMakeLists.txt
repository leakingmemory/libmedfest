set(CMAKE_CXX_STANDARD 20)

add_library(decoded OBJECT Status.cpp Status.h OppfLegemiddelMerkevare.cpp OppfLegemiddelMerkevare.h
        LegemiddelMerkevare.cpp LegemiddelMerkevare.h Atc.h Legemiddel.cpp Legemiddel.h Reseptgruppe.h
        ValueWithDistinguishedName.cpp ValueWithDistinguishedName.h ValueWithCodeSet.cpp ValueWithCodeSet.h
        LegemiddelformKort.h Preparattype.h AdministreringLegemiddel.cpp AdministreringLegemiddel.h
        Administrasjonsvei.h Preparatomtaleavsnitt.cpp Preparatomtaleavsnitt.h Reseptgyldighet.cpp Reseptgyldighet.h
        LegemiddelCore.cpp LegemiddelCore.h Legemiddelpakning.cpp Legemiddelpakning.h
        OppfLegemiddelpakning.cpp OppfLegemiddelpakning.h Pakningsinfo.cpp Pakningsinfo.h ValueUnit.cpp ValueUnit.h)
