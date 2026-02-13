//
// Created by sigsegv on 1/9/23.
//

#include "FestSerializer_0.h"
#include "Struct/Packed/PackException.h"
#include <iostream>
#include <fstream>

FestSerializer_0::FestSerializer_0(const std::shared_ptr<std::ostream> &stream)
: output(stream), percentDone(0), minimumMajorVersion(0) {
}

FestSerializer_0::FestSerializer_0(const std::string &filename)
: FestSerializer_0(std::make_shared<std::ofstream>(filename, std::ios::binary | std::ios::out | std::ios::trunc)) {
}

bool FestSerializer_0::is_open() const {
    if (!output) {
        return false;
    }
    auto fs = std::dynamic_pointer_cast<std::ofstream>(output);
    if (fs) {
        return fs->is_open();
    }
    return true;
}

bool FestSerializer_0::Serialize(const Fest &fest) {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        return false;
    }
    bool result = fest.Accept(*this);
    ProgressFinished(result);
    for (const auto &festPair : this->festMap) {
        const auto &festInst = *(festPair.second);
        fests_V_0_0_0.emplace_back(festInst, uint16List_V_0_0_0, stringblock, stringblockCache);
        fests_V_0_2_0.emplace_back(festInst, uint16List, stringblock, stringblockCache);
        fests_V_0_3_0.emplace_back(festInst, uint32List, uint16List, stringblock, stringblockCache);
        fests_V_0_4_0.emplace_back(festInst, uint32List, uint16List, stringblock, stringblockCache);
        fests_V_1_3_0.emplace_back(festInst, uint32List, uint16List, stringblock, stringblockCache);
    }
    return result;
}

bool FestSerializer_0::Write(uint64_t magic) {
    if (!is_open()) {
        std::cerr << "Error: Output file is not opened, or writeable\n";
        throw PackException("File not writeable or open");
    }
    auto dbVersion = GetDbVersion(magic);
    if (dbVersion.major > 1) {
        throw PackException("Output version above 1.X.X is not supported");
    }
    if (dbVersion.major == 1 && dbVersion.minor > 5) {
        throw PackException("Output version above 1.5.X is not supported");
    }
    if (dbVersion.major == 0 && dbVersion.minor > 4) {
        throw PackException("Output version major 0 with minor > 4 (0.4.X) is not supported");
    }
    if (dbVersion.major < minimumMajorVersion) {
        throw PackException("Output version below minimum with the imported data");
    }
    if (dbVersion.major < GetLowestSupportedMajorVersion()) {
        throw PackException("Major version below supported range");
    }
    if (dbVersion.major > GetHighestSupportedMajorVersion()) {
        throw PackException("Major version above supported range");
    }
    if (dbVersion.minor > GetHighestSupportedMinorVersion(dbVersion.major)) {
        throw PackException("Minor version above supported range for this major version");
    }
    char alignmentBlock[alignment] = {};
    if (festidblock.size() >= (1 << 24)) {
        throw PackException("Max size fest-id-block");
    }
    if (reseptgyldighetList.size() >= (1 << 8)) {
        throw PackException("Max size reseptgyldighet-list");
    }
    if (legemiddelMerkevare_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max size merkevare-list v0.0.0");
    }
    if (legemiddelMerkevare_0_4_0.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max size merkevare-list v0.4.0");
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
    if (festUuidList_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max size uuid-list-list (v0.0.0)");
    }
    if (festUuidList_0_4_0.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max size uuid-list-list (v0.4.0)");
    }
    if (legemiddelpakning_0_0_0.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max size legemiddelpakning");
    }
    if (legemiddelpakning_0_4_0.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max size legemiddelpakning");
    }
    if (refusjonList.size() >= (1 << 16)) {
        throw PackException("Max size refusjon-list");
    }
    if (legemiddelVirkestoff_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max size legemiddel-virkestoff v0.0.0");
    }
    if (legemiddelVirkestoff_0_4_0.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max size legemiddel-virkestoff v0.4.0");
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
    if (legemiddeldose_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max legemiddeldose list size v0.0.0");
    }
    if (legemiddeldose_0_4_0.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max legemiddeldose list size v0.4.0");
    }
    if (virkestoffMedStyrke.size() >= (1 << 16)) {
        throw PackException("Max virkestoff med styrke list size");
    }
    if (virkestoff_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max virkestoff list size v0.0.0");
    }
    if (virkestoff_0_4_0.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max virkestoff list size v0.4.0");
    }
    if (dbVersion.major == 0 && elementList_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max element v0.0.0 list size");
    }
    if (elementList_0_3_0.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max element v0.3.0 list size");
    }
    if (termList.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max term list size");
    }
    if (dbVersion.major == 0 && kodeverk_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max kodeverk v0.0.0 list size");
    }
    if (kodeverk_0_3_0.size() >= (1 << 16)) {
        throw PackException("Max kodeverk v0.3.0 list size");
    }
    if (refRefusjonsvilkarList_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max ref refusjonsvilkar list (v0.0.0)");
    }
    if (refRefusjonsvilkarList_1_2_0.size() >= (1 << 16)) {
        throw PackException("Max ref refusjonsvilkar list (v1.2.0)");
    }
    if (dbVersion.major == 0 && refusjonskodeList_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max refusjonskode 0.0.0 list");
    }
    if (refusjonskodeList_0_1_0.size() >= (1 << 16)) {
        throw PackException("Max refusjonskode 0.1.0 list");
    }
    if (refusjonskodeList_1_2_0.size() >= (1 << 16)) {
        throw PackException("Max refusjonskode 1.2.0 list");
    }
    if (refusjon_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max oppf refusjon 0.0.0 size\n");
    }
    if (refusjon_1_4_0.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max oppf refusjon 1.4.0 size\n");
    }
    if (vilkar.size() >= (1 << 16)) {
        throw PackException("Max oppf vilkar size\n");
    }
    if (varselSlv_0_0_0.size() >= (1 << 16)) {
        throw PackException("Max oppf varsel slv size v0.0.0\n");
    }
    if (varselSlv_0_4_0.size() > std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max oppf varsel slv size v0.4.0\n");
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
    if (dbVersion.major == 0 && uint16List_V_0_0_0.size() >= (1 << 22)) {
        throw PackException("Max uint16 legacy list storage size\n");
    }
    if (uint16List.size() >= std::numeric_limits<uint32_t>::max()) {
        throw PackException("Max uint16 new list storage size\n");
    }
    if (dbVersion.major == 0 && fests_V_0_0_0.size() >= (1 << 10)) {
        throw PackException("Max fests storage size (V0.0.0)");
    }
    if (fests_V_0_2_0.size() >= std::numeric_limits<uint16_t>::max()) {
        throw PackException("Max fests storage size (V0.2.0)");
    }
    if (fests_V_0_3_0.size() >= std::numeric_limits<uint16_t>::max()) {
        throw PackException("Max fests storage size (V0.3.0)");
    }
    FestFirstHeader firstHeader{
        .magic = magic,
        .numUuids = (uint32_t) festidblock.size(),
        .numReseptgyldighet = (uint8_t) reseptgyldighetList.size(),
        .numLegemiddelMerkevare = (uint16_t) (dbVersion.major <= 1 ? legemiddelMerkevare_0_0_0.size() : 0),
        .numValueCodeset = (uint16_t) valueWithCodesetList.size(),
        .numPakningskomponent = (uint16_t) pakningskomponentList.size(),
        .numPakningskomponentInfo = (uint16_t) pakningskomponentInfoList.size(),
        .numPakningsinfo = (uint16_t) pakningsinfoList.size(),
        .numPrisVare = (uint16_t) prisVareList.size(),
        .numUuidLists = (uint16_t) (dbVersion.major <= 1 ? festUuidList_0_0_0.size() : 0),
        .numPakning = (uint16_t) (dbVersion.major == 0 ? (legemiddelpakning_0_0_0.size() <= std::numeric_limits<uint16_t>::max() ? legemiddelpakning_0_0_0.size() : std::numeric_limits<uint16_t>::max()) : 0),
        .numRefusjonList = (uint16_t) refusjonList.size(),
        .numLegemiddelVirkestoff = (uint16_t) (dbVersion.major <= 1 ? legemiddelVirkestoff_0_0_0.size() : 0),
        .numStringList = (uint16_t) stringList.size(),
        .numMedForbrMatr = (uint16_t) medForbrMatr.size(),
        .numNaringsmiddel = (uint16_t) naringsmiddel.size(),
        .numBrystprotese = (uint16_t) brystprotese.size(),
        .numLegemiddeldose = (uint16_t) (dbVersion.major <= 1 ? legemiddeldose_0_0_0.size() : 0),
        .numVirkestoffMedStyrke = (uint16_t) virkestoffMedStyrke.size(),
        .numVirkestoff = (uint16_t) (dbVersion.major <= 1 ? virkestoff_0_0_0.size() : 0),
        .numElement = (uint16_t) (dbVersion.major == 0 ? elementList_0_0_0.size() : 0),
        .numKodeverk = (uint16_t) (dbVersion.major == 0 ? kodeverk_0_0_0.size() : 0),
        .numRefRefusjonsvilkar_0_0_0 = (uint16_t) refRefusjonsvilkarList_0_0_0.size(),
        .numRefusjonskode_0_0_0 = (uint16_t) (dbVersion.major == 0 ? refusjonskodeList_0_0_0.size() : 0),
        .numRefusjon = (uint16_t) refusjon_0_0_0.size(),
        .numVilkar = (uint16_t) vilkar.size(),
        .numVarselSlv = (uint16_t) varselSlv_0_0_0.size(),
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
        .numUint16List = (uint32_t) (dbVersion.major == 0 ? uint16List_V_0_0_0.size() : 0),
        .numFests = (uint16_t) (dbVersion.major == 0 ? fests_V_0_0_0.size() : 0)
    };
    size_t offset = sizeof(firstHeader);
    output->write((char *) (void *) &firstHeader, offset);
    if (dbVersion.major <= 1) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = legemiddelMerkevare_0_0_0.data();
            auto size = legemiddelMerkevare_0_0_0.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
    }
    if (dbVersion.major == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = legemiddelpakning_0_0_0.data();
            auto size = (size_t) legemiddelpakning_0_0_0.size();
            if (size > std::numeric_limits<uint16_t>::max()) {
                size = std::numeric_limits<uint16_t>::max();
            }
            size = size * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
    }
    {
        auto off = offset % alignment;
        if (off != 0) {
            off = alignment - off;
            output->write(&(alignmentBlock[0]), off);
            offset += off;
        }
    }
    if (dbVersion.major <= 1) {
        {
            auto *ptr = legemiddelVirkestoff_0_0_0.data();
            auto size = legemiddelVirkestoff_0_0_0.size() * sizeof(*ptr);
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
    if (dbVersion.major <= 1) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = legemiddeldose_0_0_0.data();
            auto size = legemiddeldose_0_0_0.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
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
    if (dbVersion.major <= 1) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = virkestoff_0_0_0.data();
            auto size = virkestoff_0_0_0.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
    }
    if (dbVersion.major == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = kodeverk_0_0_0.data();
            auto size = kodeverk_0_0_0.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
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
        auto *ptr = refusjon_0_0_0.data();
        auto size = refusjon_0_0_0.size() * sizeof(*ptr);
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
    if (dbVersion.major <= 1) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto *ptr = varselSlv_0_0_0.data();
            auto size = varselSlv_0_0_0.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
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
    if (dbVersion.major <= 1) {
        {
            auto list = festUuidList_0_0_0.GetStorageBlock();
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
    if (dbVersion.major == 0) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto list = elementList_0_0_0.GetStorageList();
            auto *ptr = list.data();
            auto size = list.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
    }
    if (dbVersion.major < 2) {
        {
            auto off = offset % alignment;
            if (off != 0) {
                off = alignment - off;
                output->write(&(alignmentBlock[0]), off);
                offset += off;
            }
        }
        {
            auto list = refRefusjonsvilkarList_0_0_0.GetStorageList();
            auto *ptr = list.data();
            auto size = list.size() * sizeof(*ptr);
            output->write((char *) (void *) ptr, size);
            offset += size;
        }
    }
    if (dbVersion.major == 0) {
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
    if (dbVersion.major == 0) {
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
        if (refusjonskodeList_0_1_0.size() > std::numeric_limits<uint16_t>::max()) {
            throw PackException("Refusjonskode list size overshoot (v0.1.0)");
        }
        if (refRefusjonsvilkarList_1_2_0.size() > std::numeric_limits<uint16_t>::max()) {
            throw PackException("Refusjonskode list size overshoot (v1.2.0)");
        }
        if (dbVersion.major == 0 && dbVersion.minor > 2 && fests_V_0_2_0.size() != fests_V_0_3_0.size()) {
            throw PackException("Size mismatch V 0.2.0 vs. 0.3.0");
        }
        FestSecondHeader secondHeader{
            .magic = firstHeader.magic,
            .stringblockSize = (uint32_t) stringblock.size(),
            .secondHeaderSize = sizeof(FestSecondHeader),
            .numRefusjonskode_0_1_0 = (uint16_t) refusjonskodeList_0_1_0.size(),
            .numUint16NewList = (uint32_t) (dbVersion.major > 0 || dbVersion.minor > 1 ? uint16List.size() : 0),
            .numFests = (uint16_t) (dbVersion.major == 0 ? (dbVersion.minor > 1 ? fests_V_0_2_0.size() : 0) : fests_V_0_3_0.size()),
            .numKodeverk = (uint16_t) (dbVersion.major > 0 || dbVersion.minor > 2 ? kodeverk_0_3_0.size() : 0),
            .numElementList = (uint32_t) (dbVersion.major > 0 || dbVersion.minor > 2 ? elementList_0_3_0.size() : 0),
            .numTermList = (uint32_t) (dbVersion.major > 0 || dbVersion.minor > 2 ? termList.size() : 0),
            .numUint32List = (uint32_t) (dbVersion.major > 0 || dbVersion.minor > 2 ? uint32List.size() : 0),
            .numPakning_0_3_0 = (uint32_t) (dbVersion.major > 0 || dbVersion.minor > 2 ? legemiddelpakning_0_0_0.size() : 0),
            .numPakning_0_4_0 = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? legemiddelpakning_0_4_0.size() : 0),
            .numMerkevare = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? legemiddelMerkevare_0_4_0.size() : 0),
            .numLegemiddelVirkestoff = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? legemiddelVirkestoff_0_4_0.size() : 0),
            .numLegemiddeldose = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? legemiddeldose_0_4_0.size() : 0),
            .numFestUuidList = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? festUuidList_0_4_0.size() : 0),
            .numVirkestoff = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? virkestoff_0_4_0.size() : 0),
            .numVarselSlv = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3) ? varselSlv_0_4_0.size() : 0),
            .numRefRefusjonsvilkar_1_2_0 = (uint16_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 1) ? refRefusjonsvilkarList_1_2_0.size() : 0),
            .numRefusjonskode_1_2_0 = (uint16_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 1) ? refusjonskodeList_1_2_0.size() : 0),
            .numPakning_1_3_0 = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 2) ? legemiddelpakning_1_3_0.size() : 0),
            .numRefusjon_1_4_0 = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 3) ? refusjon_1_4_0.size() : 0),
            .numRefusjonsgruppeList = (uint32_t) (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 3) ? refusjonsgruppeList.size() : 0)
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
            auto list = refusjonskodeList_0_1_0.GetStorageList();
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
        if (dbVersion.major > 0 || dbVersion.minor > 1) {
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
            if (dbVersion.major == 0) {
                {
                    auto *ptr = fests_V_0_2_0.data();
                    auto size = fests_V_0_2_0.size() * sizeof(*ptr);
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
        }
        if (dbVersion.major > 0 || dbVersion.minor > 2) {
            {
                auto list = elementList_0_3_0.GetStorageList();
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
                auto list = termList.GetStorageList();
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
                auto &list = kodeverk_0_3_0;
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
            if (dbVersion.major <= 1) {
                {
                    auto &list = legemiddelpakning_0_0_0;
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
            }
            {
                auto *ptr = fests_V_0_3_0.data();
                auto size = fests_V_0_3_0.size() * sizeof(*ptr);
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
                auto list = uint32List.GetStorageList();
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
        }
        if (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 0) || (dbVersion.major == 0 && dbVersion.minor > 3)) {
            {
                auto list = festUuidList_0_4_0.GetStorageBlock();
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
                auto &list = legemiddelMerkevare_0_4_0;
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
                auto &list = legemiddelVirkestoff_0_4_0;
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
                auto &list = legemiddelpakning_0_4_0;
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
                auto &list = legemiddeldose_0_4_0;
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
                auto *ptr = virkestoff_0_4_0.data();
                auto size = virkestoff_0_4_0.size() * sizeof(*ptr);
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
                auto *ptr = varselSlv_0_4_0.data();
                auto size = varselSlv_0_4_0.size() * sizeof(*ptr);
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
                auto *ptr = fests_V_0_4_0.data();
                auto size = fests_V_0_4_0.size() * sizeof(*ptr);
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
        if (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 1)) {
            {
                auto list = refRefusjonsvilkarList_1_2_0.GetStorageList();
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
                auto list = refusjonskodeList_1_2_0.GetStorageList();
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
        }
        if (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 2)) {
            {
                auto *ptr = fests_V_1_3_0.data();
                auto size = fests_V_1_3_0.size() * sizeof(*ptr);
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
                auto &list = legemiddelpakning_1_3_0;
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
        }
        if (dbVersion.major > 1 || (dbVersion.major == 1 && dbVersion.minor > 3)) {
            {
                auto *ptr = refusjon_1_4_0.data();
                auto size = refusjon_1_4_0.size() * sizeof(*ptr);
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
                auto list = refusjonsgruppeList.GetStorageList();
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
        }
        output->write((char *) (void *) &trailer, sizeof(trailer));
    }
    auto fs = std::dynamic_pointer_cast<std::ofstream>(output);
    if (fs) {
        fs->close();
    }
    return true;
}

bool FestSerializer_0::Write() {
    return Write(GetMagicNumbber());
}

bool FestSerializer_0::WriteVersion(uint8_t major, uint8_t minor, uint8_t patch) {
    return Write(GetMagicNumbber(major, minor, patch));
}

int FestSerializer_0::GetLowestSupportedMajorVersion() {
    return 0;
}

int FestSerializer_0::GetHighestSupportedMajorVersion() {
    return 1;
}

int FestSerializer_0::GetHighestSupportedMinorVersion(int major) {
    if (major == 1) {
        return 4;
    } else if (major == 0) {
        return 4;
    } else {
        return 0;
    }
}

void FestSerializer_0::Add(const std::string &dato, const std::function<void(FestData &)> &func) {
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

void FestSerializer_0::Progress(int done, int total) {
    int pcnt = (100 * done) / total;
    if (pcnt != percentDone) {
        percentDone = pcnt;
        std::cout << "\rGenerating output: " << percentDone << "% done." << std::flush;
    }
}

void FestSerializer_0::ProgressFinished(bool success) {
    if (success) {
        std::cout << "\rGenerating output: 100% done.\n";
    } else {
        std::cout << "\n";
    }
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfLegemiddelMerkevare &merkevare) {
    auto index_0_0_0 = Add(this->legemiddelMerkevare_0_0_0, {merkevare, stringblock, stringblockCache, festidblock, festUuidList_0_0_0, valueWithCodesetList, reseptgyldighetList});
    auto index_0_4_0 = Add(this->legemiddelMerkevare_0_4_0, {merkevare, stringblock, stringblockCache, festidblock, festUuidList_0_4_0, valueWithCodesetList, reseptgyldighetList});
    Add(fest, [index_0_0_0] (FestData &f) { f.legemiddelMerkevare_0_0_0.emplace_back(index_0_0_0); });
    Add(fest, [index_0_4_0] (FestData &f) { f.legemiddelMerkevare_0_4_0.emplace_back(index_0_4_0); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfLegemiddelpakning &pakning) {
    auto index_0_0_0 = Add(this->legemiddelpakning_0_0_0, {pakning, pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList_0_0_0, festidblock, stringblock, stringblockCache});
    auto index_0_4_0 = Add32(this->legemiddelpakning_0_4_0, {pakning, pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList_0_4_0, festidblock, stringblock, stringblockCache});
    auto index_1_3_0 = Add32(this->legemiddelpakning_1_3_0, {pakning, pakningskomponentList, pakningsinfoList, prisVareList, stringList, festUuidList_0_4_0, festidblock, stringblock, stringblockCache, refusjonList});
    Add(fest, [index_0_0_0] (FestData &f) { f.legemiddelpakning_0_0_0.emplace_back(index_0_0_0); });
    Add(fest, [index_0_4_0] (FestData &f) { f.legemiddelpakning_0_4_0.emplace_back(index_0_4_0); });
    Add(fest, [index_1_3_0] (FestData &f) { f.legemiddelpakning_1_3_0.emplace_back(index_1_3_0); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfLegemiddelVirkestoff &virkestoff) {
    auto index_0_0_0 = Add(this->legemiddelVirkestoff_0_0_0, {virkestoff, stringblock, stringblockCache, festidblock, stringList, festUuidList_0_0_0, valueWithCodesetList, refusjonList});
    auto index_0_4_0 = Add(this->legemiddelVirkestoff_0_4_0, {virkestoff, stringblock, stringblockCache, festidblock, stringList, festUuidList_0_4_0, valueWithCodesetList, refusjonList});
    Add(fest, [index_0_0_0] (FestData &f) { f.legemiddelVirkestoff_0_0_0.emplace_back(index_0_0_0); });
    Add(fest, [index_0_4_0] (FestData &f) { f.legemiddelVirkestoff_0_4_0.emplace_back(index_0_4_0); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfMedForbrMatr &medForbrMatr) {
    auto index = Add(this->medForbrMatr, {medForbrMatr, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.medForbrMatr.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfNaringsmiddel &naringsmiddel) {
    auto index = Add(this->naringsmiddel, {naringsmiddel, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.naringsmiddel.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfBrystprotese &brystprotese) {
    auto index = Add(this->brystprotese, {brystprotese, prisVareList, stringList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.brystprotese.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfLegemiddeldose &legemiddeldose) {
    auto index_0_0_0 = Add(this->legemiddeldose_0_0_0, {legemiddeldose, pakningskomponentInfoList, festUuidList_0_0_0, festidblock, stringblock, stringblockCache});
    auto index_0_4_0 = Add(this->legemiddeldose_0_4_0, {legemiddeldose, pakningskomponentInfoList, festUuidList_0_4_0, festidblock, stringblock, stringblockCache});
    Add(fest, [index_0_0_0] (FestData &f) { f.legemiddeldose_0_0_0.emplace_back(index_0_0_0); });
    Add(fest, [index_0_4_0] (FestData &f) { f.legemiddeldose_0_4_0.emplace_back(index_0_4_0); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfVirkestoffMedStyrke &virkestoffMedStyrke) {
    auto index = Add(this->virkestoffMedStyrke, {virkestoffMedStyrke, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.virkestoffMedStyrke.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfVirkestoff &virkestoff) {
    auto index = Add(this->virkestoff_0_0_0, {virkestoff, festUuidList_0_0_0, festidblock, stringblock, stringblockCache});
    auto index_0_4_0 = Add(this->virkestoff_0_4_0, {virkestoff, festUuidList_0_4_0, festidblock, stringblock, stringblockCache});
    // TODO
    if (index_0_4_0 != index) {
        throw PackException("Index v0.4.0 is off (OppfVirkestoff)");
    }
    Add(fest, [index] (FestData &f) { f.virkestoff.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfKodeverk &kodeverk) {
    auto index = Add(this->kodeverk_0_0_0, {kodeverk, elementList_0_0_0, festidblock, stringblock, stringblockCache});
    auto index_0_3_0 = Add(this->kodeverk_0_3_0, {kodeverk, elementList_0_3_0, termList, festidblock, stringblock, stringblockCache});
    Add(fest, [index, index_0_3_0] (FestData &f) {
        f.kodeverk_0_0_0.emplace_back(index);
        f.kodeverk_0_3_0.emplace_back(index_0_3_0);
    });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfRefusjon &refusjon) {
    uint32_t index2;
    if (minimumMajorVersion > 0) {
        index2 = Add(this->refusjon_1_4_0, {refusjon, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, refusjonsgruppeList, stringList, festidblock, stringblock, stringblockCache});
    } else {
        index2 = Add(this->refusjon_1_4_0, {refusjon, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, refusjonsgruppeList, stringList, festidblock, stringblock, stringblockCache});
    }
    uint16_t index = (uint16_t) index2;
    if (minimumMajorVersion > 0) {
        index = Add(this->refusjon_0_0_0, {refusjon, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, festidblock, stringblock, stringblockCache}, index);
    } else {
        index = Add(this->refusjon_0_0_0, {refusjon, refusjonskodeList_0_0_0, refusjonskodeList_0_1_0, refusjonskodeList_1_2_0, refRefusjonsvilkarList_0_0_0, refRefusjonsvilkarList_1_2_0, stringList, festidblock, stringblock, stringblockCache}, index);
    }
    if (index2 != index) {
        throw PackException("Index v1.4.0 is off (OppfRefusjon)");
    }
    Add(fest, [index] (FestData &f) { f.refusjon.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfVilkar &vilkar) {
    auto index = Add(this->vilkar, {vilkar, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.vilkar.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfVarselSlv &varselSlv) {
    auto index = Add(this->varselSlv_0_0_0, {varselSlv, valueWithCodesetList, festUuidList_0_0_0, festidblock, stringblock, stringblockCache});
    auto index_0_4_0 = Add(this->varselSlv_0_4_0, {varselSlv, valueWithCodesetList, festUuidList_0_4_0, festidblock, stringblock, stringblockCache});
    // TODO
    if (index != index_0_4_0) {
        throw PackException("VarselSlv v0.4.0 index mismatch");
    }
    Add(fest, [index] (FestData &f) { f.varselSlv.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfByttegruppe &byttegruppe) {
    auto index = Add(this->byttegruppe, {byttegruppe, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.byttegruppe.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfInteraksjon &interaksjon) {
    auto index = Add(this->interaksjon, {interaksjon, referanseList, substansgruppeList, substansList, valueWithCodesetList, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.interaksjon.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfInteraksjonIkkeVurdert &interaksjonIkkeVurdert) {
    auto index = Add(this->interaksjonIkkeVurdert, {interaksjonIkkeVurdert, festidblock, stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.interaksjonIkkeVurdert.emplace_back(index); });
    return true;
}

bool FestSerializer_0::Visit(const std::string &fest, const OppfStrDosering &strDosering) {
    auto index = Add(this->strDosering, {strDosering, legemiddelforbrukList, doseringList, doseFastTidspunktList, festidblock,
                                   stringblock, stringblockCache});
    Add(fest, [index] (FestData &f) { f.strDosering.emplace_back(index); });
    return true;
}
