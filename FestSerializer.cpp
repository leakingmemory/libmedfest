//
// Created by sigsegv on 1/9/23.
//

#include "FestSerializer.h"
#include "Struct/Packed/PackException.h"
#include <iostream>

FestSerializer::FestSerializer(std::shared_ptr<Fest> fest, const std::string &filename)
: fest(fest), output(filename, std::ios::binary | std::ios::out | std::ios::trunc), percentDone(0) {
}

bool FestSerializer::Serialize() {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        return false;
    }
    bool result = fest->Accept(*this);
    if (result) {
        std::cout << "\rGenerating output: 100% done.\n";
    } else {
        std::cout << "\n";
    }
    return result;
}

bool FestSerializer::Write() {
    char alignmentBlock[alignment] = {};
    if (festidblock.size() >= (1 << 24)) {
        throw PackException("Max size fest-id-block");
    }
    if (reseptgyldighetList.size() >= (1 << 8)) {
        throw PackException("Max size reseptgyldighet-list");
    }
    if (legemiddelMerkevare.size() >= (1 << 16)) {
        throw PackException("Max size merkevare-list");
    }
    if (valueWithCodesetList.size() >= (1 << 16)) {
        throw PackException("Max vc-list");
    }
    if (pakningskomponentList.size() >= (1 << 16)) {
        throw PackException("Max pakningskomponent-list");
    }
    if (pakningskomponentInfoList.size() >= (1 << 16)) {
        throw PackException("Max pakningskomponent-info-list");
    }
    if (pakningsinfoList.size() >= (1 << 16)) {
        throw PackException("Max pakningsinfo-list");
    }
    if (prisVareList.size() >= (1 << 16)) {
        throw PackException("Max pris-vare-list");
    }
    if (festUuidList.size() >= (1 << 16)) {
        throw PackException("Max size uuid-list-list");
    }
    if (legemiddelpakning.size() >= (1 << 16)) {
        throw PackException("Max size legemiddelpakning");
    }
    if (refusjonList.size() >= (1 << 16)) {
        throw PackException("Max size refusjon-list");
    }
    if (legemiddelVirkestoff.size() >= (1 << 16)) {
        throw PackException("Max size legemiddel-virkestoff");
    }
    if (stringList.size() >= (1 << 16)) {
        throw PackException("Max size string-list");
    }
    if (medForbrMatr.size() >= (1 << 16)) {
        throw PackException("Max med-forbr-matr list size");
    }
    if (naringsmiddel.size() >= (1 << 16)) {
        throw PackException("Max naringsmiddel list size");
    }
    if (brystprotese.size() >= (1 << 16)) {
        throw PackException("Max brystprotese list size");
    }
    if (legemiddeldose.size() >= (1 << 16)) {
        throw PackException("Max legemiddeldose list size");
    }
    if (virkestoffMedStyrke.size() >= (1 << 16)) {
        throw PackException("Max virkestoff med styrke list size");
    }
    FestFirstHeader firstHeader{
        .numUuids = (uint32_t) festidblock.size(),
        .numReseptgyldighet = (uint8_t) reseptgyldighetList.size(),
        .numLegemiddelMerkevare = (uint16_t) legemiddelMerkevare.size(),
        .numValueCodeset = (uint16_t) valueWithCodesetList.size(),
        .numPakningskomponent = (uint16_t) pakningskomponentList.size(),
        .numPakningskomponentInfo = (uint16_t) pakningskomponentInfoList.size(),
        .numPakningsinfo = (uint16_t) pakningsinfoList.size(),
        .numPrisVare = (uint16_t) prisVareList.size(),
        .numUuidLists = (uint16_t) festUuidList.size(),
        .numPakning = (uint16_t) legemiddelpakning.size(),
        .numRefusjon = (uint16_t) refusjonList.size(),
        .numLegemiddelVirkestoff = (uint16_t) legemiddelVirkestoff.size(),
        .numStringList = (uint16_t) stringList.size(),
        .numMedForbrMatr = (uint16_t) medForbrMatr.size(),
        .numNaringsmiddel = (uint16_t) naringsmiddel.size(),
        .numBrystprotese = (uint16_t) brystprotese.size(),
        .numLegemiddeldose = (uint16_t) legemiddeldose.size(),
        .numVirkestoffMedStyrke = (uint16_t) virkestoffMedStyrke.size()
    };
    size_t offset = sizeof(firstHeader);
    output.write((char *) (void *) &firstHeader, offset);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelMerkevare.data();
        auto size = legemiddelMerkevare.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelpakning.data();
        auto size = legemiddelpakning.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelVirkestoff.data();
        auto size = legemiddelVirkestoff.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = medForbrMatr.data();
        auto size = medForbrMatr.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = naringsmiddel.data();
        auto size = naringsmiddel.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = brystprotese.data();
        auto size = brystprotese.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddeldose.data();
        auto size = legemiddeldose.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = virkestoffMedStyrke.data();
        auto size = virkestoffMedStyrke.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = festidblock.data();
        auto size = festidblock.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = festUuidList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = valueWithCodesetList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = reseptgyldighetList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningskomponentList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningskomponentInfoList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningsinfoList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = prisVareList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = refusjonList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output.write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = stringList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output.write((char *) (void *) ptr, size);
        offset += size;
    }
    output.write(stringblock.c_str(), stringblock.size());
    output.close();
    return true;
}

void FestSerializer::Progress(int done, int total) {
    int pcnt = (100 * done) / total;
    if (pcnt != percentDone) {
        percentDone = pcnt;
        std::cout << "\rGenerating output: " << percentDone << "% done." << std::flush;
    }
}

bool FestSerializer::Visit(const OppfLegemiddelMerkevare &merkevare) {
    this->legemiddelMerkevare.emplace_back(merkevare, stringblock, festidblock, festUuidList, valueWithCodesetList, reseptgyldighetList);
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelpakning &pakning) {
    this->legemiddelpakning.emplace_back(pakning, pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddelVirkestoff &virkestoff) {
    this->legemiddelVirkestoff.emplace_back(virkestoff, stringblock, festidblock, stringList, festUuidList, valueWithCodesetList, refusjonList);
    return true;
}

bool FestSerializer::Visit(const OppfMedForbrMatr &medForbrMatr) {
    this->medForbrMatr.emplace_back(medForbrMatr, prisVareList, stringList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfNaringsmiddel &naringsmiddel) {
    this->naringsmiddel.emplace_back(naringsmiddel, prisVareList, stringList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfBrystprotese &brystprotese) {
    this->brystprotese.emplace_back(brystprotese, prisVareList, stringList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfLegemiddeldose &legemiddeldose) {
    this->legemiddeldose.emplace_back(legemiddeldose, pakningskomponentInfoList, festUuidList, festidblock, stringblock);
    return true;
}

bool FestSerializer::Visit(const OppfVirkestoffMedStyrke &virkestoffMedStyrke) {
    this->virkestoffMedStyrke.emplace_back(virkestoffMedStyrke, festidblock, stringblock);
    return true;
}