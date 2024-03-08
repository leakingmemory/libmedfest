//
// Created by sigsegv on 1/10/23.
//

#include <Struct/Packed/PPreparatomtaleavsnitt.h>
#include <Struct/Decoded/Preparatomtaleavsnitt.h>

PPreparatomtaleavsnitt::PPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt,
                                               std::string &strblock, std::map<std::string,uint32_t> &cache) :
        avsnittoverskrift(preparatomtaleavsnitt.GetAvsnittoverskrift(), strblock, cache),
        lenke(preparatomtaleavsnitt.GetLenke(), strblock, cache){
}

bool PPreparatomtaleavsnitt::operator==(const PPreparatomtaleavsnitt &other) const {
    return avsnittoverskrift == other.avsnittoverskrift &&
           lenke == other.lenke;
}