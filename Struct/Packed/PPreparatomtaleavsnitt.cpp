//
// Created by sigsegv on 1/10/23.
//

#include "PPreparatomtaleavsnitt.h"
#include "../Decoded/Preparatomtaleavsnitt.h"

PPreparatomtaleavsnitt::PPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt,
                                               std::string &strblock) :
        avsnittoverskrift(preparatomtaleavsnitt.GetAvsnittoverskrift(), strblock),
        lenke(preparatomtaleavsnitt.GetLenke(), strblock){
}