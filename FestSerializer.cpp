//
// Created by sigsegv on 1/9/23.
//

#include "FestSerializer.h"
#include "Struct/Packed/PackException.h"
#include <iostream>
#include <fstream>

FestData::FestData(const std::string &dato) : dato(dato) {}

FestSerializer::FestSerializer(const std::shared_ptr<std::ostream> &stream)
: output(stream), percentDone(0) {
}

FestSerializer::FestSerializer(const std::string &filename)
: FestSerializer(std::make_shared<std::ofstream>(filename, std::ios::binary | std::ios::out | std::ios::trunc)) {
}

bool FestSerializer::is_open() const {
    if (!output) {
        return false;
    }
    auto fs = std::dynamic_pointer_cast<std::ofstream>(output);
    if (fs) {
        return fs->is_open();
    }
    return true;
}

bool FestSerializer::Serialize(const Fest &fest) {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        return false;
    }
    bool result = fest.Accept(*this);
    ProgressFinished(result);
    for (const auto &festPair : this->festMap) {
        const auto &festInst = *(festPair.second);
        fests_V_0_0_0.emplace_back(festInst, uint16List_V_0_0_0, stringblock, stringblockCache);
        fests.emplace_back(festInst, uint16List, stringblock, stringblockCache);
    }
    return result;
}

bool FestSerializer::Write(uint64_t magic) {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        throw PackException("File not writeable or open");
    }
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
    if (virkestoff.size() >= (1 << 16)) {
        throw PackException("Max virkestoff list size");
    }
    if (elementList.size() >= (1 << 16)) {
        throw PackException("Max element list size");
    }
    if (kodeverk.size() >= (1 << 16)) {
        throw PackException("Max kodeverk list size");
    }
    if (refRefusjonsvilkarList.size() >= (1 << 16)) {
        throw PackException("Max ref refusjonsvilkar list");
    }
    if (refusjonskodeList_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max refusjonskode 0.0.0 list");
    }
    if (refusjonskodeList.size() >= (1 << 16)) {
        throw PackException("Max refusjonskode list");
    }
    if (refusjon.size() >= (1 << 16)) {
        throw PackException("Max oppf refusjon size\n");
    }
    if (vilkar.size() >= (1 << 16)) {
        throw PackException("Max oppf vilkar size\n");
    }
    if (varselSlv.size() >= (1 << 16)) {
        throw PackException("Max oppf varsel slv size\n");
    }
    if (byttegruppe.size() >= (1 << 16)) {
        throw PackException("Max oppf byttegruppe size\n");
    }
    if (referanseList.size() >= (1 << 16)) {
        throw PackException("Max referanse list storage size\n");
    }
    if (substansgruppeList.size() >= (1 << 16)) {
        throw PackException("Max substansgruppe list storage size\n");
    }
    if (substansList.size() >= (1 << 16)) {
        throw PackException("Max substans list storage size\n");
    }
    if (interaksjon.size() >= (1 << 16)) {
        throw PackException("Max num interaksjon\n");
    }
    if (interaksjonIkkeVurdert.size() >= (1 << 16)) {
        throw PackException("Max num interaksjon ikke vurdert\n");
    }
    if (doseFastTidspunktList.size() >= (1 << 16)) {
        throw PackException("Max dose fast tidspunkt list storage size\n");
    }
    if (doseringList.size() >= (1 << 16)) {
        throw PackException("Max dosering list storage size\n");
    }
    if (legemiddelforbrukList.size() >= (1 << 16)) {
        throw PackException("Max legemiddelforbruk list storage size\n");
    }
    if (strDosering.size() >= (1 << 16)) {
        throw PackException("Max str dosering size\n");
    }
    if (uint16List_V_0_0_0.size() >= (1 << 22)) {
        throw PackException("Max uint16 legacy list storage size\n");
    }
    if (uint16List.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max uint16 new list storage size\n");
    }
    if (fests_V_0_0_0.size() >= (1 << 10)) {
        throw PackException("Max fests storage size (V0.0.0)");
    }
    if (fests.size() >= std::numeric_limits<uint16_t>::max()) {
        throw PackException("Max fests storage size (V0.2.0)");
    }
    FestFirstHeader firstHeader{
        .magic = magic,
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
        .numRefusjonList = (uint16_t) refusjonList.size(),
        .numLegemiddelVirkestoff = (uint16_t) legemiddelVirkestoff.size(),
        .numStringList = (uint16_t) stringList.size(),
        .numMedForbrMatr = (uint16_t) medForbrMatr.size(),
        .numNaringsmiddel = (uint16_t) naringsmiddel.size(),
        .numBrystprotese = (uint16_t) brystprotese.size(),
        .numLegemiddeldose = (uint16_t) legemiddeldose.size(),
        .numVirkestoffMedStyrke = (uint16_t) virkestoffMedStyrke.size(),
        .numVirkestoff = (uint16_t) virkestoff.size(),
        .numElement = (uint16_t) elementList.size(),
        .numKodeverk = (uint16_t) kodeverk.size(),
        .numRefRefusjonsvilkar = (uint16_t) refRefusjonsvilkarList.size(),
        .numRefusjonskode_0_0_0 = (uint16_t) refusjonskodeList_0_0_0.size(),
        .numRefusjon = (uint16_t) refusjon.size(),
        .numVilkar = (uint16_t) vilkar.size(),
        .numVarselSlv = (uint16_t) varselSlv.size(),
        .numByttegruppe = (uint16_t) byttegruppe.size(),
        .numReferanseList = (uint16_t) referanseList.size(),
        .numSubstansgruppeList = (uint16_t) substansgruppeList.size(),
        .numSubstansList = (uint16_t) substansList.size(),
        .numInteraksjon = (uint16_t) interaksjon.size(),
        .numInteraksjonIkkeVurdert = (uint16_t) interaksjonIkkeVurdert.size(),
        .numDoseFastTidspunktList = (uint16_t) doseFastTidspunktList.size(),
        .numDoseringList = (uint16_t) doseringList.size(),
        .numLegemiddelforbrukList = (uint16_t) legemiddelforbrukList.size(),
        .numStrDosering = (uint16_t) strDosering.size(),
        .numUint16List = (uint32_t) uint16List_V_0_0_0.size(),
        .numFests = (uint16_t) fests.size()
    };
    size_t offset = sizeof(firstHeader);
    output->write((char *) (void *) &firstHeader, offset);
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelMerkevare.data();
        auto size = legemiddelMerkevare.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelpakning.data();
        auto size = legemiddelpakning.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddelVirkestoff.data();
        auto size = legemiddelVirkestoff.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = medForbrMatr.data();
        auto size = medForbrMatr.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = naringsmiddel.data();
        auto size = naringsmiddel.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = brystprotese.data();
        auto size = brystprotese.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = legemiddeldose.data();
        auto size = legemiddeldose.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = virkestoffMedStyrke.data();
        auto size = virkestoffMedStyrke.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = virkestoff.data();
        auto size = virkestoff.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = kodeverk.data();
        auto size = kodeverk.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = refusjon.data();
        auto size = refusjon.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = vilkar.data();
        auto size = vilkar.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = varselSlv.data();
        auto size = varselSlv.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = byttegruppe.data();
        auto size = byttegruppe.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = interaksjon.data();
        auto size = interaksjon.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = interaksjonIkkeVurdert.data();
        auto size = interaksjonIkkeVurdert.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = strDosering.data();
        auto size = strDosering.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = festidblock.data();
        auto size = festidblock.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = festUuidList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = valueWithCodesetList.GetStorageBlock();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = reseptgyldighetList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningskomponentList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningskomponentInfoList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = pakningsinfoList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = prisVareList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = refusjonList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = elementList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = refRefusjonsvilkarList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = refusjonskodeList_0_0_0.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = referanseList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = substansgruppeList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = substansList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = doseFastTidspunktList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = doseringList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = legemiddelforbrukList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = uint16List_V_0_0_0.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto *ptr = fests_V_0_0_0.data();
        auto size = fests_V_0_0_0.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    {
        auto list = stringList.GetStorageList();
        auto *ptr = list.data();
        auto size = list.size() * sizeof(*ptr);
        output->write((char *) (void *) ptr, size);
        offset += size;
    }
    {
        auto size = stringblock.size();
        output->write(stringblock.c_str(), size);
        offset += size;
    }
    auto dbVersion = GetDbVersion(firstHeader.magic);
    if (dbVersion.major > 0 || dbVersion.minor > 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        if (offset > std::numeric_limits<uint32_t>::max()) {
            throw PackException("Size limits overshoot (v0.1.0 - offset of second header)");
        }
        FestTrailer trailer{.reserved = 0, .secondHeaderOffset = (uint32_t) offset, .magic = firstHeader.magic};
        if (stringblock.size() > std::numeric_limits<uint32_t>::max()) {
            throw PackException("Stringblock size overshoot (v0.1.0)");
        }
        if (refusjonskodeList.size() > std::numeric_limits<uint16_t>::max()) {
            throw PackException("Refusjonskode list size overshoot (v0.1.0)");
        }
        FestSecondHeader secondHeader{
            .magic = firstHeader.magic,
            .stringblockSize = (uint32_t) stringblock.size(),
            .secondHeaderSize = sizeof(FestSecondHeader),
            .numRefusjonskode = (uint16_t) refusjonskodeList.size(),
            .numUint16NewList = (uint32_t) (dbVersion.minor > 1 ? uint16List.size() : 0),
            .numFests = (uint16_t) (dbVersion.minor > 1 ? fests.size() : 0),
            .reservedZ = 0
        };
        output->write((char *) (void *) &secondHeader, sizeof(secondHeader));
        offset += sizeof(secondHeader);
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto list = refusjonskodeList.GetStorageList();
            auto *ptr = list.data();
            auto size = list.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        if (dbVersion.minor > 1) {
            {
                auto list = uint16List.GetStorageList();
                auto *ptr = list.data();
                auto size = list.size() * sizeof(*ptr);
                output->write((char *) (void *) ptr, size);
                offset += size;
            }
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    output->write(&(alignmentBlock[0]), off);
                    offset += off;
                }
            }
            {
                auto *ptr = fests.data();
                auto size = fests.size() * sizeof(*ptr);
                output->write((char *) (void *) ptr, size);
                offset += size;
            }
            {
                auto off = offset % alignment;
                if (off != 0) {
                    off = alignment - off;
                    output->write(&(alignmentBlock[0]), off);
                    offset += off;
                }
            }
        }
        output->write((char *) (void *) &trailer, sizeof(trailer));
    }
    auto fs = std::dynamic_pointer_cast<std::ofstream>(output);
    if (fs) {
        fs->close();
    }
    return true;
}

bool FestSerializer::Write() {
    return Write(GetMagicNumbber());
}

bool FestSerializer::WriteVersion(uint8_t major, uint8_t minor, uint8_t patch) {
    return Write(GetMagicNumbber(major, minor, patch));
}

void FestSerializer::Add(const std::string &dato, const std::function<void(FestData &)> &func) {
    {
        auto iterator = festMap.find(dato);
        if (iterator != festMap.end()) {
            func(*(iterator->second));
            return;
        }
    }
    std::shared_ptr<FestData> festData = std::make_shared<FestData>(dato);
    func(*festData);
    festMap.insert_or_assign(dato, festData);
}

void FestSerializer::Progress(int done, int total) {
    int pcnt = (100 * done) / total;
    if (pcnt != percentDone) {
        percentDone = pcnt;
        std::cout << "\rGenerating output: " << percentDone << "% done." << std::flush;
    }
}

void FestSerializer::ProgressFinished(bool success) {
    if (success) {
        std::cout << "\rGenerating output: 100% done.\n";
    } else {
        std::cout << "\n";
    }
}

bool FestSerializer::Visit(const std::string &fest, const OppfLegemiddelMerkevare &merkevare) {
    auto index = Add(this->legemiddelMerkevare, {merkevare, stringblock, stringblockCache, festidblock, festUuidList, valueWithCodesetList, reseptgyldighetList});
    Add(fest, [index] (FestData &f) { f.legemiddelMerkevare.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfLegemiddelpakning &pakning) {
    auto index = Add(this->legemiddelpakning, {pakning, pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.legemiddelpakning.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfLegemiddelVirkestoff &virkestoff) {
    auto index = Add(this->legemiddelVirkestoff, {virkestoff, stringblock, stringblockCache, festidblock, stringList, festUuidList, valueWithCodesetList, refusjonList});
    Add(fest, [index] (FestData &f) { f.legemiddelVirkestoff.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfMedForbrMatr &medForbrMatr) {
    auto index = Add(this->medForbrMatr, {medForbrMatr, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.medForbrMatr.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfNaringsmiddel &naringsmiddel) {
    auto index = Add(this->naringsmiddel, {naringsmiddel, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.naringsmiddel.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfBrystprotese &brystprotese) {
    auto index = Add(this->brystprotese, {brystprotese, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.brystprotese.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfLegemiddeldose &legemiddeldose) {
    auto index = Add(this->legemiddeldose, {legemiddeldose, pakningskomponentInfoList, festUuidList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.legemiddeldose.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfVirkestoffMedStyrke &virkestoffMedStyrke) {
    auto index = Add(this->virkestoffMedStyrke, {virkestoffMedStyrke, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.virkestoffMedStyrke.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfVirkestoff &virkestoff) {
    auto index = Add(this->virkestoff, {virkestoff, festUuidList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.virkestoff.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfKodeverk &kodeverk) {
    auto index = Add(this->kodeverk, {kodeverk, elementList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.kodeverk.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfRefusjon &refusjon) {
    auto index = Add(this->refusjon, {refusjon, refusjonskodeList_0_0_0, refusjonskodeList, refRefusjonsvilkarList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.refusjon.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfVilkar &vilkar) {
    auto index = Add(this->vilkar, {vilkar, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.vilkar.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfVarselSlv &varselSlv) {
    auto index = Add(this->varselSlv, {varselSlv, valueWithCodesetList, festUuidList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.varselSlv.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfByttegruppe &byttegruppe) {
    auto index = Add(this->byttegruppe, {byttegruppe, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.byttegruppe.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfInteraksjon &interaksjon) {
    auto index = Add(this->interaksjon, {interaksjon, referanseList, substansgruppeList, substansList, valueWithCodesetList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.interaksjon.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfInteraksjonIkkeVurdert &interaksjonIkkeVurdert) {
    auto index = Add(this->interaksjonIkkeVurdert, {interaksjonIkkeVurdert, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.interaksjonIkkeVurdert.emplace_back(index); });
    return true;
}

bool FestSerializer::Visit(const std::string &fest, const OppfStrDosering &strDosering) {
    auto index = Add(this->strDosering, {strDosering, legemiddelforbrukList, doseringList, doseFastTidspunktList, festidblock,
                                   stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.strDosering.emplace_back(index); });
    return true;
}
