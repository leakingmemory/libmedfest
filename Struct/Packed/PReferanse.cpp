//
// Created by sigsegv on 2/11/23.
//

#include <Struct/Packed/PReferanse.h>
#include <Struct/Decoded/Referanse.h>

PReferanse::PReferanse(const Referanse &referanse, std::string &strblock, std::map<std::string, uint32_t> &cache) :
        kilde(referanse.kilde, strblock, cache),
        lenke(referanse.lenke, strblock, cache)
{
}

bool PReferanse::operator==(const PReferanse &other) const {
    return kilde == other.kilde && lenke == other.lenke;
}