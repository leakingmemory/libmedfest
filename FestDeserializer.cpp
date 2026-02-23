//
// Created by sigsegv on 2/20/26.
//

#include "DbVersion.h"
#include "FestHeaders.h"
#include "FestVectors.h"
#include "Struct/Decoded/OppfByttegruppe.h"
#include "Struct/Decoded/OppfHandelsvare.h"
#include "Struct/Decoded/OppfInteraksjon.h"
#include "Struct/Decoded/OppfInteraksjonIkkeVurdert.h"
#include "Struct/Decoded/OppfKodeverk.h"
#include "Struct/Decoded/OppfLegemiddeldose.h"
#include "Struct/Decoded/OppfLegemiddelMerkevare.h"
#include "Struct/Decoded/OppfLegemiddelpakning.h"
#include "Struct/Decoded/OppfLegemiddelVirkestoff.h"
#include "Struct/Decoded/OppfRefusjon.h"
#include "Struct/Decoded/OppfStrDosering.h"
#include "Struct/Decoded/OppfVarselSlv.h"
#include "Struct/Decoded/OppfVilkar.h"
#include "Struct/Decoded/OppfVirkestoff.h"
#include "Struct/Decoded/OppfVirkestoffMedStyrke.h"
#include "Struct/Packed/PackException.h"
#ifdef WIN32
#define FEST_SERIALIZER_USE_STD_CXX_FILEIO
#endif

#include <FestDeserializer.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
#include <fstream>
#else
#include <unistd.h>
#include <sys/mman.h>
#endif
#include <iostream>
#include <type_traits>

FestDeserializerMapping::FestDeserializerMapping(const std::string &filename) {
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
    std::ifstream inputFile(filename, std::ios_base::binary);
    inputFile.seekg(0, std::ios_base::end);
    mapsize = inputFile.tellg();
    inputFile.seekg(0, std::ios_base::beg);
    mapping = malloc(mapsize);
    if (mapping == nullptr) {
        std::cerr << "Error: Unable to allocate memory for reading file\n";
        inputFile.close();
        throw PackException("Allocate memory");
    }
    inputFile.read(reinterpret_cast<char*>(mapping), mapsize);
    inputFile.close();
#else
    auto fd = open(filename.c_str(), O_RDONLY);
    if (fd < 0) {
        std::cerr << "Error: Open file: " << filename << ": " << strerror(errno) << "\n";
        throw PackException("Open file");
    }
    auto size = lseek(fd, 0, SEEK_END);
    if (lseek(fd, 0, SEEK_SET) != 0) {
        std::cerr << "Error: Seek start: " << strerror(errno) << "\n";
        if (close(fd) != 0) {
            std::cerr << "Error: Close file: " << strerror(errno) << "\n";
        }
        throw PackException("Seek file");
    }
    mapsize = size;
    mapping = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapping == MAP_FAILED) {
        std::cerr << "Error: Map failed: " << strerror(errno) << "\n";
        mapping = nullptr;
        throw PackException("Map failed");
    }
    if (close(fd) != 0) {
        std::cerr << "Error: Close file: " << strerror(errno) << "\n";
    }
#endif
}
FestDeserializerMapping::FestDeserializerMapping(const void *data, size_t size) {
    mapsize = size;
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
    mapping = malloc(mapsize);
    if (mapping == nullptr) {
        std::cerr << "Error: Unable to allocate memory for input data\n";
        throw PackException("Allocate memory");
    }
    memcpy(mapping, data, size);
#else
    mapping = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapping == MAP_FAILED) {
        std::cerr << "Error: Map failed: " << strerror(errno) << "\n";
        mapping = nullptr;
        throw PackException("Map failed");
    }
    memcpy(mapping, data, size);
    mprotect(mapping, size, PROT_READ);
#endif
}

FestDeserializerMapping::~FestDeserializerMapping() {
    if (mapping != nullptr) {
#ifdef FEST_SERIALIZER_USE_STD_CXX_FILEIO
        free(mapping);
#else
        munmap(mapping, mapsize);
#endif
    }
}

FestDeserializer::FestDeserializer(const std::string &filename) : mapping(std::make_shared<FestDeserializerMapping>(filename)) {
    Init();
}

FestDeserializer::FestDeserializer(const void *data, size_t size) : mapping(std::make_shared<FestDeserializerMapping>(data, size)) {
    Init();
}

void FestDeserializer::Init() {
    auto *header = (FestFirstHeader *) mapping->mapping;
    if (mapping->mapsize < sizeof(*header)) {
        throw PackException("Truncated file");
    }
    auto version = GetDbVersion(header->magic);
    if (!version.valid) {
        std::cerr << "Error: File is not a FEST db file\n";
        throw PackException("Not a FEST file");
    }
    if (version.major > 0) {
        deserializer = std::make_shared<FestDeserializer_1>(mapping);
    } else {
        deserializer = std::make_shared<FestDeserializer_0>(mapping);
    }
}

FestDeserializer::~FestDeserializer() = default;

int FestDeserializer::GetVersionMajor() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVersionMajor();
    }, deserializer);
}
int FestDeserializer::GetVersionMinor() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVersionMinor();
    }, deserializer);
}
int FestDeserializer::GetVersionPatch() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVersionPatch();
    }, deserializer);
}
std::vector<POppfLegemiddelMerkevare_0_0_0> FestDeserializer::GetLegemiddelMerkevare_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelMerkevare_0_0_0();
    }, deserializer);
}
std::vector<POppfLegemiddelMerkevare_0_4_0> FestDeserializer::GetLegemiddelMerkevare_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelMerkevare_0_4_0();
    }, deserializer);
}
std::vector<POppfLegemiddelMerkevare> FestDeserializer::GetLegemiddelMerkevare() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelMerkevare();
    }, deserializer);
}
std::vector<POppfLegemiddelpakning_0_0_0> FestDeserializer::GetLegemiddelPakning_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelPakning_0_0_0();
    }, deserializer);
}
std::vector<POppfLegemiddelpakning_0_4_0> FestDeserializer::GetLegemiddelPakning_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelPakning_0_4_0();
    }, deserializer);
}
std::vector<POppfLegemiddelpakning_1_3_0> FestDeserializer::GetLegemiddelPakning_1_3_0() const {
    struct {
        std::vector<POppfLegemiddelpakning_1_3_0> operator () (const std::shared_ptr<FestDeserializer_0> &) {
            return {};
        }
        std::vector<POppfLegemiddelpakning_1_3_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return deserializer->GetLegemiddelPakning_1_3_0();
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<POppfLegemiddelpakning> FestDeserializer::GetLegemiddelPakning() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelPakning();
    }, deserializer);
}
std::vector<POppfLegemiddelVirkestoff_0_0_0> FestDeserializer::GetLegemiddelVirkestoff_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelVirkestoff_0_0_0();
    }, deserializer);
}
std::vector<POppfLegemiddelVirkestoff_0_4_0> FestDeserializer::GetLegemiddelVirkestoff_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelVirkestoff_0_4_0();
    }, deserializer);
}
std::vector<POppfLegemiddelVirkestoff> FestDeserializer::GetLegemiddelVirkestoff() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelVirkestoff();
    }, deserializer);
}
std::vector<POppfMedForbrMatr> FestDeserializer::GetMedForbrMatr() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetMedForbrMatr();
    }, deserializer);
}
std::vector<POppfNaringsmiddel> FestDeserializer::GetNaringsmiddel() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetNaringsmiddel();
    }, deserializer);
}
std::vector<POppfBrystprotese> FestDeserializer::GetBrystprotese() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetBrystprotese();
    }, deserializer);
}
std::vector<POppfLegemiddeldose_0_0_0> FestDeserializer::GetLegemiddeldose_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddeldose_0_0_0();
    }, deserializer);
}
std::vector<POppfLegemiddeldose_0_4_0> FestDeserializer::GetLegemiddeldose_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddeldose_0_4_0();
    }, deserializer);
}
std::vector<POppfLegemiddeldose> FestDeserializer::GetLegemiddeldose() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddeldose();
    }, deserializer);
}
std::vector<POppfVirkestoffMedStyrke> FestDeserializer::GetVirkestoffMedStyrke() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVirkestoffMedStyrke();
    }, deserializer);
}
std::vector<POppfVirkestoff_0_0_0> FestDeserializer::GetVirkestoff_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVirkestoff_0_0_0();
    }, deserializer);
}
std::vector<POppfVirkestoff_0_4_0> FestDeserializer::GetVirkestoff_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVirkestoff_0_4_0();
    }, deserializer);
}
std::vector<POppfVirkestoff> FestDeserializer::GetVirkestoff() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVirkestoff();
    }, deserializer);
}
std::vector<POppfRefusjon_0_0_0> FestDeserializer::GetOppfRefusjon_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetOppfRefusjon_0_0_0();
    }, deserializer);
}
std::vector<POppfRefusjon_1_4_0> FestDeserializer::GetOppfRefusjon_1_4_0() const {
    struct {
        std::vector<POppfRefusjon_1_4_0> operator () (const std::shared_ptr<FestDeserializer_0> &) {
            return {};
        }
        std::vector<POppfRefusjon_1_4_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return deserializer->GetOppfRefusjon_1_4_0();
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<POppfRefusjon> FestDeserializer::GetOppfRefusjon() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetOppfRefusjon();
    }, deserializer);
}
std::vector<POppfVilkar> FestDeserializer::GetOppfVilkar() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetOppfVilkar();
    }, deserializer);
}
std::vector<POppfVarselSlv_0_4_0> FestDeserializer::GetVarselSlv_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVarselSlv_0_4_0();
    }, deserializer);
}
std::vector<POppfVarselSlv_0_0_0> FestDeserializer::GetVarselSlv_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVarselSlv_0_0_0();
    }, deserializer);
}
std::vector<POppfVarselSlv> FestDeserializer::GetVarselSlv() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetVarselSlv();
    }, deserializer);
}
std::vector<POppfKodeverk_0_0_0> FestDeserializer::GetOppfKodeverk_0_0_0() const {
    struct {
        std::vector<POppfKodeverk_0_0_0> operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            return deserializer->GetOppfKodeverk_0_0_0();
        }
        std::vector<POppfKodeverk_0_0_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return {};
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<POppfKodeverk_0_3_0> FestDeserializer::GetOppfKodeverk_0_3_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetOppfKodeverk_0_3_0();
    }, deserializer);
}
std::vector<POppfByttegruppe_0_0_0> FestDeserializer::GetByttegruppe_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetByttegruppe_0_0_0();
    }, deserializer);
}
std::vector<POppfByttegruppe_1_5_0> FestDeserializer::GetByttegruppe_1_5_0() const {
    struct {
        std::vector<POppfByttegruppe_1_5_0> operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            return {};
        }
        std::vector<POppfByttegruppe_1_5_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return deserializer->GetByttegruppe_1_5_0();
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<POppfInteraksjon> FestDeserializer::GetInteraksjon() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetInteraksjon();
    }, deserializer);
}
std::vector<POppfInteraksjonIkkeVurdert> FestDeserializer::GetInteraksjonIkkeVurdert() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetInteraksjonIkkeVurdert();
    }, deserializer);
}
std::vector<POppfStrDosering> FestDeserializer::GetStrDosering() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetStrDosering();
    }, deserializer);
}
std::vector<PString> FestDeserializer::GetStrings() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetStrings();
    }, deserializer);
}
std::vector<PPrisVare> FestDeserializer::GetPrisVare() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetPrisVare();
    }, deserializer);
}
std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfo() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetPakningsinfo();
    }, deserializer);
}
std::vector<PPakningskomponent> FestDeserializer::GetPakningskomponent() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetPakningskomponent();
    }, deserializer);
}
std::vector<PPakningskomponentInfo> FestDeserializer::GetPakningskomponentInfo() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetPakningskomponentInfo();
    }, deserializer);
}
std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighet() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetReseptgyldighet();
    }, deserializer);
}
std::vector<PValueWithCodeset> FestDeserializer::GetValueWithCodeset() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetValueWithCodeset();
    }, deserializer);
}
std::vector<FestUuid> FestDeserializer::GetFestIds() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetFestIds();
    }, deserializer);
}
std::vector<PFestId> FestDeserializer::GetFestIdLists_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetFestIdLists_0_0_0();
    }, deserializer);
}
std::vector<PFestId> FestDeserializer::GetFestIdLists_0_4_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetFestIdLists_0_4_0();
    }, deserializer);
}
std::vector<PFestId> FestDeserializer::GetFestIdLists() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetFestIdLists();
    }, deserializer);
}
std::vector<PRefusjon> FestDeserializer::GetRefusjon() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetRefusjon();
    }, deserializer);
}
std::vector<PElement_0_0_0> FestDeserializer::GetElement_0_0_0() const {
    struct {
        std::vector<PElement_0_0_0> operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            return deserializer->GetElement_0_0_0();
        }
        std::vector<PElement_0_0_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return {};
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<PElement_0_3_0> FestDeserializer::GetElement_0_3_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetElement_0_3_0();
    }, deserializer);
}
std::vector<PElement> FestDeserializer::GetElement() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetElement();
    }, deserializer);
}
std::vector<PRefRefusjonsvilkar_0_0_0> FestDeserializer::GetRefRefusjonsvilkar_0_0_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetRefRefusjonsvilkar_0_0_0();
    }, deserializer);
}
std::vector<PRefRefusjonsvilkar_1_2_0> FestDeserializer::GetRefRefusjonsvilkar_1_2_0() const {
    struct {
        std::vector<PRefRefusjonsvilkar_1_2_0> operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            return {};
        }
        std::vector<PRefRefusjonsvilkar_1_2_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return deserializer->GetRefRefusjonsvilkar_1_2_0();
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<PRefRefusjonsvilkar> FestDeserializer::GetRefRefusjonsvilkar() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetRefRefusjonsvilkar();
    }, deserializer);
}
std::vector<PRefusjonskode_0_0_0> FestDeserializer::GetRefusjonskode_0_0_0() const {
    struct {
        std::vector<PRefusjonskode_0_0_0> operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
            return deserializer->GetRefusjonskode_0_0_0();
        }
        std::vector<PRefusjonskode_0_0_0> operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            return {};
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<PRefusjonskode_0_1_0> FestDeserializer::GetRefusjonskode_0_1_0() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetRefusjonskode_0_1_0();
    }, deserializer);
}
std::vector<PRefusjonskode_1_2_0> FestDeserializer::GetRefusjonskode_1_2_0() const {
    struct {
        std::vector<PRefusjonskode_1_2_0> operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            return {};
        }
        std::vector<PRefusjonskode_1_2_0> operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            return deserializer->GetRefusjonskode_1_2_0();
        }
    } visitor;
    return std::visit(visitor, deserializer);
}
std::vector<PRefusjonskode> FestDeserializer::GetRefusjonskode() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetRefusjonskode();
    }, deserializer);
}
std::vector<PReferanse> FestDeserializer::GetReferanse() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetReferanse();
    }, deserializer);
}
std::vector<PSubstansgruppe> FestDeserializer::GetSubstansgruppe() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetSubstansgruppe();
    }, deserializer);
}
std::vector<PSubstans> FestDeserializer::GetSubstans() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetSubstans();
    }, deserializer);
}
std::vector<PDoseFastTidspunkt> FestDeserializer::GetDoseFastTidspunkt() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetDoseFastTidspunkt();
    }, deserializer);
}
std::vector<PDosering> FestDeserializer::GetDosering() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetDosering();
    }, deserializer);
}
std::vector<PLegemiddelforbruk> FestDeserializer::GetLegemiddelforbruk() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetLegemiddelforbruk();
    }, deserializer);
}
std::vector<PString> FestDeserializer::GetStringList() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetStringList();
    }, deserializer);
}
void FestDeserializer::ForEachMerkevare_0_0_0(const std::function<void (const POppfLegemiddelMerkevare_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachMerkevare_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachMerkevare_0_4_0(const std::function<void (const POppfLegemiddelMerkevare_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachMerkevare_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachMerkevare(const std::function<void (const POppfLegemiddelMerkevare &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachMerkevare(func);
    }, deserializer);
}
void FestDeserializer::ForEachPakning_0_0_0(const std::function<void (const POppfLegemiddelpakning_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachPakning_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachPakning_0_4_0(const std::function<void (const POppfLegemiddelpakning_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachPakning_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachPakning_1_3_0(const std::function<void (const POppfLegemiddelpakning_1_3_0 &)> &func) const {
    struct {
        const std::function<void (const POppfLegemiddelpakning_1_3_0 &)> &func;
        void operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
        }
        void operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            deserializer->ForEachPakning_1_3_0(func);
        }
    } visitor{.func = func};
    std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachPakning(const std::function<void (const POppfLegemiddelpakning &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachPakning(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddelVirkestoff_0_0_0(const std::function<void (const POppfLegemiddelVirkestoff_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddelVirkestoff_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddelVirkestoff_0_4_0(const std::function<void (const POppfLegemiddelVirkestoff_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddelVirkestoff_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddelVirkestoff(const std::function<void (const POppfLegemiddelVirkestoff &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddelVirkestoff(func);
    }, deserializer);
}
void FestDeserializer::ForEachMedForbrMatr(const std::function<void (const POppfMedForbrMatr &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachMedForbrMatr(func);
    }, deserializer);
}
void FestDeserializer::ForEachNaringsmiddel(const std::function<void (const POppfNaringsmiddel &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachNaringsmiddel(func);
    }, deserializer);
}
void FestDeserializer::ForEachBrystprotese(const std::function<void (const POppfBrystprotese &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachBrystprotese(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddeldose_0_0_0(const std::function<void (const POppfLegemiddeldose_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddeldose_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddeldose_0_4_0(const std::function<void (const POppfLegemiddeldose_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddeldose_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachLegemiddeldose(const std::function<void (const POppfLegemiddeldose &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachLegemiddeldose(func);
    }, deserializer);
}
void FestDeserializer::ForEachVirkestoffMedStyrke(const std::function<void (const POppfVirkestoffMedStyrke &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVirkestoffMedStyrke(func);
    }, deserializer);
}
void FestDeserializer::ForEachVirkestoff_0_0_0(const std::function<void (const POppfVirkestoff_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVirkestoff_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachVirkestoff_0_4_0(const std::function<void (const POppfVirkestoff_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVirkestoff_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachVirkestoff(const std::function<void (const POppfVirkestoff &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVirkestoff(func);
    }, deserializer);
}
void FestDeserializer::ForEachKodeverk_0_0_0(const std::function<void (const POppfKodeverk_0_0_0 &)> &func) const {
    struct {
        const std::function<void (const POppfKodeverk_0_0_0 &)> &func;
        void operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
            deserializer->ForEachKodeverk_0_0_0(func);
        }
        void operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
        }
    } visitor{.func = func};
    std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachKodeverk_0_3_0(const std::function<void (const POppfKodeverk_0_3_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachKodeverk_0_3_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachKodeverk(const std::function<void (const POppfKodeverk &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachKodeverk(func);
    }, deserializer);
}
void FestDeserializer::ForEachRefusjon_0_0_0(const std::function<void (const POppfRefusjon_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachRefusjon_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachRefusjon_1_4_0(const std::function<void (const POppfRefusjon_1_4_0 &)> &func) const {
    struct {
        const std::function<void (const POppfRefusjon_1_4_0 &)> &func;
        void operator () (const std::shared_ptr<FestDeserializer_0> &deserializer) {
        }
        void operator () (const std::shared_ptr<FestDeserializer_1> &deserializer) {
            deserializer->ForEachRefusjon_1_4_0(func);
        }
    } visitor{.func = func};
    std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachRefusjon(const std::function<void (const POppfRefusjon &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachRefusjon(func);
    }, deserializer);
}
void FestDeserializer::ForEachVilkar(const std::function<void (const POppfVilkar &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVilkar(func);
    }, deserializer);
}
void FestDeserializer::ForEachVarselSlv_0_0_0(const std::function<void (const POppfVarselSlv_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVarselSlv_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachVarselSlv_0_4_0(const std::function<void (const POppfVarselSlv_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVarselSlv_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachVarselSlv(const std::function<void (const POppfVarselSlv &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachVarselSlv(func);
    }, deserializer);
}
void FestDeserializer::ForEachByttegruppe_0_0_0(const std::function<void (const POppfByttegruppe_0_0_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachByttegruppe_0_0_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachByttegruppe_1_5_0(const std::function<void (const POppfByttegruppe_1_5_0 &)> &func) const {
    struct {
        const std::function<void (const POppfByttegruppe_1_5_0 &)> &func;
        void operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
        }
        void operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            deserializer->ForEachByttegruppe_1_5_0(func);
        }
    } visitor{.func = func};
    std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachByttegruppe(const std::function<void (const POppfByttegruppe &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachByttegruppe(func);
    }, deserializer);
}
void FestDeserializer::ForEachInteraksjon(const std::function<void (const POppfInteraksjon &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachInteraksjon(func);
    }, deserializer);
}
void FestDeserializer::ForEachInteraksjonIkkeVurdert(const std::function<void (const POppfInteraksjonIkkeVurdert &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachInteraksjonIkkeVurdert(func);
    }, deserializer);
}
void FestDeserializer::ForEachStrDosering(const std::function<void (const POppfStrDosering &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachStrDosering(func);
    }, deserializer);
}
void FestDeserializer::ForEachFests_V_0_0_0(const std::function<void (const PFest_V_0_0_0 &)> &func) const {
    struct {
        const std::function<void (const PFest_V_0_0_0 &)> &func;
        void operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
            deserializer->ForEachFests_V_0_0_0(func);
        }
        void operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
        }
    } visitor{.func = func};
    return std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachFests_V_0_2_0(const std::function<void (const PFest_V_0_2_0 &)> &func) const {
    struct {
        const std::function<void (const PFest_V_0_2_0 &)> &func;
        void operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
            deserializer->ForEachFests_V_0_2_0(func);
        }
        void operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
        }
    } visitor{.func = func};
    return std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachFests_V_0_3_0(const std::function<void (const PFest_V_0_3_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachFests_V_0_3_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachFests_V_0_4_0(const std::function<void (const PFest_V_0_4_0 &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachFests_V_0_4_0(func);
    }, deserializer);
}
void FestDeserializer::ForEachFests_V_1_3_0(const std::function<void (const PFest_V_1_3_0 &)> &func) const {
    struct {
        const std::function<void (const PFest_V_1_3_0 &)> &func;
        void operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
        }
        void operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            deserializer->ForEachFests_V_1_3_0(func);
        }
    } visitor{.func = func};
    std::visit(visitor, deserializer);
}
void FestDeserializer::ForEachFests(const std::function<void (const PFest &)> &func) const {
    return std::visit([&func] (const auto &deserializer) {
        return deserializer->ForEachFests(func);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest_V_0_0_0 &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest_V_0_2_0 &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest_V_0_3_0 &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest_V_0_4_0 &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest_V_1_3_0 &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
FestVectors FestDeserializer::Unpack(const PFest &pfest) const {
    return std::visit([&pfest] (const auto &deserializer) {
        return deserializer->Unpack(pfest);
    }, deserializer);
}
std::string FestDeserializer::Unpack(const PString &str) const {
    return std::visit([&str] (const auto &deserializer) {
        return deserializer->Unpack(str);
    }, deserializer);
}
Reseptgyldighet FestDeserializer::Unpack(const PReseptgyldighet &reseptgyldighet) const {
    return std::visit([&reseptgyldighet] (const auto &deserializer) {
        return deserializer->Unpack(reseptgyldighet);
    }, deserializer);
}
ValueWithDistinguishedName FestDeserializer::Unpack(const PValueWithDistinguishedName &valueWithDistinguishedName) const {
    return std::visit([&valueWithDistinguishedName] (const auto &deserializer) {
        return deserializer->Unpack(valueWithDistinguishedName);
    }, deserializer);
}
ValueWithCodeSet FestDeserializer::Unpack(const PValueWithCodeset &valueWithCodeset) const {
    return std::visit([&valueWithCodeset] (const auto &deserializer) {
        return deserializer->Unpack(valueWithCodeset);
    }, deserializer);
}
ValueUnit FestDeserializer::Unpack(const PValueUnit &valueUnit) const {
    return std::visit([&valueUnit] (const auto &deserializer) {
        return deserializer->Unpack(valueUnit);
    }, deserializer);
}
FestUuid FestDeserializer::Unpack(PFestId festId) const {
    return std::visit([festId] (const auto &deserializer) {
        return deserializer->Unpack(festId);
    }, deserializer);
}
OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelMerkevare FestDeserializer::Unpack(const POppfLegemiddelMerkevare &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning_1_3_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelpakning FestDeserializer::Unpack(const POppfLegemiddelpakning &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddelVirkestoff FestDeserializer::Unpack(const POppfLegemiddelVirkestoff &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfMedForbrMatr FestDeserializer::Unpack(const POppfMedForbrMatr &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfNaringsmiddel FestDeserializer::Unpack(const POppfNaringsmiddel &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfBrystprotese FestDeserializer::Unpack(const POppfBrystprotese &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfLegemiddeldose FestDeserializer::Unpack(const POppfLegemiddeldose &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVirkestoffMedStyrke FestDeserializer::Unpack(const POppfVirkestoffMedStyrke &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVirkestoff FestDeserializer::Unpack(const POppfVirkestoff &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk_0_0_0 &poppf) const {
    struct {
        const POppfKodeverk_0_0_0 &poppf;
        OppfKodeverk operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
            return deserializer->Unpack(poppf);
        }
        OppfKodeverk operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            throw PackException("Cannot dserialzie v0.0.0 with v1 deserializer");
        }
    } visitor{.poppf = poppf};
    return std::visit(visitor, deserializer);
}
OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk_0_3_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfKodeverk FestDeserializer::Unpack(const POppfKodeverk &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon_1_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfRefusjon FestDeserializer::Unpack(const POppfRefusjon &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVilkar FestDeserializer::Unpack(const POppfVilkar &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv_0_4_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfVarselSlv FestDeserializer::Unpack(const POppfVarselSlv &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe_0_0_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe_1_5_0 &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfByttegruppe FestDeserializer::Unpack(const POppfByttegruppe &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfInteraksjon FestDeserializer::Unpack(const POppfInteraksjon &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfInteraksjonIkkeVurdert FestDeserializer::Unpack(const POppfInteraksjonIkkeVurdert &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
OppfStrDosering FestDeserializer::Unpack(const POppfStrDosering &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
Oppf FestDeserializer::Unpack(const POppf &poppf) const {
    return std::visit([&poppf] (const auto &deserializer) {
        return deserializer->Unpack(poppf);
    }, deserializer);
}
LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare_0_0_0 &pmerkevare) const {
    return std::visit([&pmerkevare] (const auto &deserializer) {
        return deserializer->Unpack(pmerkevare);
    }, deserializer);
}
LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare_0_4_0 &pmerkevare) const {
    return std::visit([&pmerkevare] (const auto &deserializer) {
        return deserializer->Unpack(pmerkevare);
    }, deserializer);
}
LegemiddelMerkevare FestDeserializer::Unpack(const PLegemiddelMerkevare &pmerkevare) const {
    return std::visit([&pmerkevare] (const auto &deserializer) {
        return deserializer->Unpack(pmerkevare);
    }, deserializer);
}
Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_0_0_0 &ppakning) const {
    return std::visit([&ppakning] (const auto &deserializer) {
        return deserializer->Unpack(ppakning);
    }, deserializer);
}
Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_0_4_0 &ppakning) const {
    return std::visit([&ppakning] (const auto &deserializer) {
        return deserializer->Unpack(ppakning);
    }, deserializer);
}
Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning_1_3_0 &ppakning) const {
    return std::visit([&ppakning] (const auto &deserializer) {
        return deserializer->Unpack(ppakning);
    }, deserializer);
}
Legemiddelpakning FestDeserializer::Unpack(const PLegemiddelpakning &ppakning) const {
    return std::visit([&ppakning] (const auto &deserializer) {
        return deserializer->Unpack(ppakning);
    }, deserializer);
}
LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff_0_0_0 &pvirkestoff) const {
    return std::visit([&pvirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pvirkestoff);
    }, deserializer);
}
LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff_0_4_0 &pvirkestoff) const {
    return std::visit([&pvirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pvirkestoff);
    }, deserializer);
}
LegemiddelVirkestoff FestDeserializer::Unpack(const PLegemiddelVirkestoff &pvirkestoff) const {
    return std::visit([&pvirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pvirkestoff);
    }, deserializer);
}
Handelsvare FestDeserializer::Unpack(const PHandelsvare &pHandelsvare) const {
    return std::visit([&pHandelsvare] (const auto &deserializer) {
        return deserializer->Unpack(pHandelsvare);
    }, deserializer);
}
Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose_0_0_0 &pLegemiddeldose) const {
    return std::visit([&pLegemiddeldose] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddeldose);
    }, deserializer);
}
Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose_0_4_0 &pLegemiddeldose) const {
    return std::visit([&pLegemiddeldose] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddeldose);
    }, deserializer);
}
Legemiddeldose FestDeserializer::Unpack(const PLegemiddeldose &pLegemiddeldose) const {
    return std::visit([&pLegemiddeldose] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddeldose);
    }, deserializer);
}
VirkestoffMedStyrke FestDeserializer::Unpack(const PVirkestoffMedStyrke &pVirkestoffMedStyrke) const {
    return std::visit([&pVirkestoffMedStyrke] (const auto &deserializer) {
        return deserializer->Unpack(pVirkestoffMedStyrke);
    }, deserializer);
}
Virkestoff FestDeserializer::Unpack(const PVirkestoff_0_0_0 &pVirkestoff) const {
    return std::visit([&pVirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pVirkestoff);
    }, deserializer);
}
Virkestoff FestDeserializer::Unpack(const PVirkestoff_0_4_0 &pVirkestoff) const {
    return std::visit([&pVirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pVirkestoff);
    }, deserializer);
}
Virkestoff FestDeserializer::Unpack(const PVirkestoff &pVirkestoff) const {
    return std::visit([&pVirkestoff] (const auto &deserializer) {
        return deserializer->Unpack(pVirkestoff);
    }, deserializer);
}
Info FestDeserializer::Unpack(const PInfo &pInfo) const {
    return std::visit([&pInfo] (const auto &deserializer) {
        return deserializer->Unpack(pInfo);
    }, deserializer);
}
Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel_0_0_0 &pRefusjonshjemmel) const {
    return std::visit([&pRefusjonshjemmel] (const auto &deserializer) {
        return deserializer->Unpack(pRefusjonshjemmel);
    }, deserializer);
}
Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel_1_4_0 &pRefusjonshjemmel) const {
    return std::visit([&pRefusjonshjemmel] (const auto &deserializer) {
        return deserializer->Unpack(pRefusjonshjemmel);
    }, deserializer);
}
Refusjonshjemmel FestDeserializer::Unpack(const PRefusjonshjemmel &pRefusjonshjemmel) const {
    return std::visit([&pRefusjonshjemmel] (const auto &deserializer) {
        return deserializer->Unpack(pRefusjonshjemmel);
    }, deserializer);
}
Vilkar FestDeserializer::Unpack(const PVilkar &pVilkar) const {
    return std::visit([&pVilkar] (const auto &deserializer) {
        return deserializer->Unpack(pVilkar);
    }, deserializer);
}
VarselSlv FestDeserializer::Unpack(const PVarselSlv_0_0_0 &pVarselSlv) const {
    return std::visit([&pVarselSlv] (const auto &deserializer) {
        return deserializer->Unpack(pVarselSlv);
    }, deserializer);
}
VarselSlv FestDeserializer::Unpack(const PVarselSlv_0_4_0 &pVarselSlv) const {
    return std::visit([&pVarselSlv] (const auto &deserializer) {
        return deserializer->Unpack(pVarselSlv);
    }, deserializer);
}
VarselSlv FestDeserializer::Unpack(const PVarselSlv &pVarselSlv) const {
    return std::visit([&pVarselSlv] (const auto &deserializer) {
        return deserializer->Unpack(pVarselSlv);
    }, deserializer);
}
Byttegruppe FestDeserializer::Unpack(const PByttegruppe_0_0_0 &pByttegruppe) const {
    return std::visit([&pByttegruppe] (const auto &deserializer) {
        return deserializer->Unpack(pByttegruppe);
    }, deserializer);
}
Byttegruppe FestDeserializer::Unpack(const PByttegruppe_1_5_0 &pByttegruppe) const {
    return std::visit([&pByttegruppe] (const auto &deserializer) {
        return deserializer->Unpack(pByttegruppe);
    }, deserializer);
}
Byttegruppe FestDeserializer::Unpack(const PByttegruppe &pByttegruppe) const {
    return std::visit([&pByttegruppe] (const auto &deserializer) {
        return deserializer->Unpack(pByttegruppe);
    }, deserializer);
}
Interaksjon FestDeserializer::Unpack(const PInteraksjon &pInteraksjon) const {
    return std::visit([&pInteraksjon] (const auto &deserializer) {
        return deserializer->Unpack(pInteraksjon);
    }, deserializer);
}
InteraksjonIkkeVurdert FestDeserializer::Unpack(const PInteraksjonIkkeVurdert &pInteraksjonIkkeVurdert) const {
    return std::visit([&pInteraksjonIkkeVurdert] (const auto &deserializer) {
        return deserializer->Unpack(pInteraksjonIkkeVurdert);
    }, deserializer);
}
Kortdose FestDeserializer::Unpack(const PKortdose &pKortdose) const {
    return std::visit([&pKortdose] (const auto &deserializer) {
        return deserializer->Unpack(pKortdose);
    }, deserializer);
}
Legemiddel FestDeserializer::Unpack(const PLegemiddel_0_0_0 &pLegemiddel) const {
    return std::visit([&pLegemiddel] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddel);
    }, deserializer);
}
Legemiddel FestDeserializer::Unpack(const PLegemiddel_0_4_0 &pLegemiddel) const {
    return std::visit([&pLegemiddel] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddel);
    }, deserializer);
}
Legemiddel FestDeserializer::Unpack(const PLegemiddel &pLegemiddel) const {
    return std::visit([&pLegemiddel] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddel);
    }, deserializer);
}
LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore_0_0_0 &pLegemiddelCore) const {
    return std::visit([&pLegemiddelCore] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddelCore);
    }, deserializer);
}
LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore_0_4_0 &pLegemiddelCore) const {
    return std::visit([&pLegemiddelCore] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddelCore);
    }, deserializer);
}
LegemiddelCore FestDeserializer::Unpack(const PLegemiddelCore &pLegemiddelCore) const {
    return std::visit([&pLegemiddelCore] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddelCore);
    }, deserializer);
}
AdministreringLegemiddel FestDeserializer::Unpack(const PAdministreringLegemiddel &pAdministreringLegemiddel) const {
    return std::visit([&pAdministreringLegemiddel] (const auto &deserializer) {
        return deserializer->Unpack(pAdministreringLegemiddel);
    }, deserializer);
}
Preparatomtaleavsnitt FestDeserializer::Unpack(const PPreparatomtaleavsnitt &pPreparatomtaleavsnitt) const {
    return std::visit([&pPreparatomtaleavsnitt] (const auto &deserializer) {
        return deserializer->Unpack(pPreparatomtaleavsnitt);
    }, deserializer);
}
Lenke FestDeserializer::Unpack(const PLenke &lenke) const {
    return std::visit([&lenke] (const auto &deserializer) {
        return deserializer->Unpack(lenke);
    }, deserializer);
}
Pakningskomponent FestDeserializer::Unpack(const PPakningskomponent &pPakningskomponent) const {
    return std::visit([&pPakningskomponent] (const auto &deserializer) {
        return deserializer->Unpack(pPakningskomponent);
    }, deserializer);
}
PakningskomponentInfo FestDeserializer::Unpack(const PPakningskomponentInfo &pPakningskomponentInfo) const {
    return std::visit([&pPakningskomponentInfo] (const auto &deserializer) {
        return deserializer->Unpack(pPakningskomponentInfo);
    }, deserializer);
}
Pakningsinfo FestDeserializer::Unpack(const PPakningsinfo &pakningsinfo) const {
    return std::visit([&pakningsinfo] (const auto &deserializer) {
        return deserializer->Unpack(pakningsinfo);
    }, deserializer);
}
PrisVare FestDeserializer::Unpack(const PPrisVare &prisVare) const {
    return std::visit([&prisVare] (const auto &deserializer) {
        return deserializer->Unpack(prisVare);
    }, deserializer);
}
Markedsforingsinfo FestDeserializer::Unpack(const PMarkedsforingsinfo &pmarkedsforingsinfo) const {
    return std::visit([&pmarkedsforingsinfo] (const auto &deserializer) {
        return deserializer->Unpack(pmarkedsforingsinfo);
    }, deserializer);
}
Refusjon FestDeserializer::Unpack(const PRefusjon &pRefusjon) const {
    return std::visit([&pRefusjon] (const auto &deserializer) {
        return deserializer->Unpack(pRefusjon);
    }, deserializer);
}
PakningByttegruppe FestDeserializer::Unpack(const PPakningByttegruppe &pPakningByttegruppe) const {
    return std::visit([&pPakningByttegruppe] (const auto &deserializer) {
        return deserializer->Unpack(pPakningByttegruppe);
    }, deserializer);
}
ProduktInfoVare FestDeserializer::Unpack(const PProduktInfoVare &pProduktInfoVare) const {
    return std::visit([&pProduktInfoVare] (const auto &deserializer) {
        return deserializer->Unpack(pProduktInfoVare);
    }, deserializer);
}
Leverandor FestDeserializer::Unpack(const PLeverandor &pLeverandor) const {
    return std::visit([&pLeverandor] (const auto &deserializer) {
        return deserializer->Unpack(pLeverandor);
    }, deserializer);
}
Element FestDeserializer::Unpack(const PElement_0_0_0 &pElement) const {
    return std::visit([&pElement] (const auto &deserializer) {
        return deserializer->Unpack(pElement);
    }, deserializer);
}
Element FestDeserializer::Unpack(const PElement_0_3_0 &pElement) const {
    return std::visit([&pElement] (const auto &deserializer) {
        return deserializer->Unpack(pElement);
    }, deserializer);
}
Element FestDeserializer::Unpack(const PElement &pElement) const {
    return std::visit([&pElement] (const auto &deserializer) {
        return deserializer->Unpack(pElement);
    }, deserializer);
}
Term FestDeserializer::Unpack(const PTerm &pTerm) const {
    return std::visit([&pTerm] (const auto &deserializer) {
        return deserializer->Unpack(pTerm);
    }, deserializer);
}
RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar_0_0_0 &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar_1_2_0 &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
RefRefusjonsvilkar FestDeserializer::Unpack(const PRefRefusjonsvilkar &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_0_0_0 &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_0_1_0 &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
Refusjonskode FestDeserializer::Unpack(const PRefusjonskode_1_2_0 &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
Refusjonskode FestDeserializer::Unpack(const PRefusjonskode &pref) const {
    return std::visit([&pref] (const auto &deserializer) {
        return deserializer->Unpack(pref);
    }, deserializer);
}
Refusjonsgruppe FestDeserializer::Unpack(const PRefusjonsgruppe &pRefusjonsgruppe) const {
    return std::visit([&pRefusjonsgruppe] (const auto &deserializer) {
        return deserializer->Unpack(pRefusjonsgruppe);
    }, deserializer);
}
StrukturertVilkar FestDeserializer::Unpack(const PStrukturertVilkar &pStrukturertVilkar) const {
    return std::visit([&pStrukturertVilkar] (const auto &deserializer) {
        return deserializer->Unpack(pStrukturertVilkar);
    }, deserializer);
}
Referanseelement FestDeserializer::Unpack(const PReferanseelement_0_0_0 &pReferanseelement) const {
    return std::visit([pReferanseelement] (const auto &deserializer) {
        return deserializer->Unpack(pReferanseelement);
    }, deserializer);
}
Referanseelement FestDeserializer::Unpack(const PReferanseelement_0_4_0 &pReferanseelement) const {
    return std::visit([&pReferanseelement] (const auto &deserializer) {
        return deserializer->Unpack(pReferanseelement);
    }, deserializer);
}
Referanseelement FestDeserializer::Unpack(const PReferanseelement &pReferanseelement) const {
    return std::visit([&pReferanseelement] (const auto &deserializer) {
        return deserializer->Unpack(pReferanseelement);
    }, deserializer);
}
Referanse FestDeserializer::Unpack(const PReferanse &pReferanse) const {
    return std::visit([&pReferanse] (const auto &deserializer) {
        return deserializer->Unpack(pReferanse);
    }, deserializer);
}
Substansgruppe FestDeserializer::Unpack(const PSubstansgruppe &pSubstansgruppe) const {
    return std::visit([&pSubstansgruppe] (const auto &deserializer) {
        return deserializer->Unpack(pSubstansgruppe);
    }, deserializer);
}
Substans FestDeserializer::Unpack(const PSubstans &pSubstans) const {
    return std::visit([&pSubstans] (const auto &deserializer) {
        return deserializer->Unpack(pSubstans);
    }, deserializer);
}
DoseFastTidspunkt FestDeserializer::Unpack(const PDoseFastTidspunkt &pDoseFastTidspunkt) const {
    return std::visit([&pDoseFastTidspunkt] (const auto &deserializer) {
        return deserializer->Unpack(pDoseFastTidspunkt);
    }, deserializer);
}
Dosering FestDeserializer::Unpack(const PDosering &pDosering) const {
    return std::visit([&pDosering] (const auto &deserializer) {
        return deserializer->Unpack(pDosering);
    }, deserializer);
}
Legemiddelforbruk FestDeserializer::Unpack(const PLegemiddelforbruk &pLegemiddelforbruk) const {
    return std::visit([&pLegemiddelforbruk] (const auto &deserializer) {
        return deserializer->Unpack(pLegemiddelforbruk);
    }, deserializer);
}
std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_0_0_0 &pPakning) const {
    return std::visit([&pPakning] (const auto &deserializer) {
        return deserializer->GetPakningsinfoList(pPakning);
    }, deserializer);
}
std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_0_4_0 &pPakning) const {
    return std::visit([&pPakning] (const auto &deserializer) {
        return deserializer->GetPakningsinfoList(pPakning);
    }, deserializer);
}
std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning_1_3_0 &pPakning) const {
    return std::visit([&pPakning] (const auto &deserializer) {
        return deserializer->GetPakningsinfoList(pPakning);
    }, deserializer);
}
std::vector<PPakningsinfo> FestDeserializer::GetPakningsinfoList(const PLegemiddelpakning &pPakning) const {
    return std::visit([&pPakning] (const auto &deserializer) {
        return deserializer->GetPakningsinfoList(pPakning);
    }, deserializer);
}
std::vector<PElement_0_0_0> FestDeserializer::GetElementList(const POppfKodeverk_0_0_0 &pKodeverk) const {
    struct {
        const POppfKodeverk_0_0_0 &pKodeverk;
        std::vector<PElement_0_0_0> operator() (const std::shared_ptr<FestDeserializer_0> &deserializer) const {
            return deserializer->GetElementList(pKodeverk);
        }
        std::vector<PElement_0_0_0> operator() (const std::shared_ptr<FestDeserializer_1> &deserializer) const {
            return {};
        }
    } visitor{.pKodeverk = pKodeverk};
    return std::visit(visitor, deserializer);
}
std::vector<PElement_0_3_0> FestDeserializer::GetElementList(const POppfKodeverk_0_3_0 &pKodeverk) const {
    return std::visit([&pKodeverk] (const auto &deserializer) {
        return deserializer->GetElementList(pKodeverk);
    }, deserializer);
}
std::vector<PElement> FestDeserializer::GetElementList(const POppfKodeverk &pKodeverk) const {
    return std::visit([&pKodeverk] (const auto &deserializer) {
        return deserializer->GetElementList(pKodeverk);
    }, deserializer);
}
std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare_0_0_0 &pMerkevare) const {
    return std::visit([&pMerkevare] (const auto &deserializer) {
        return deserializer->GetReseptgyldighetList(pMerkevare);
    }, deserializer);
}
std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare_0_4_0 &pMerkevare) const {
    return std::visit([&pMerkevare] (const auto &deserializer) {
        return deserializer->GetReseptgyldighetList(pMerkevare);
    }, deserializer);
}
std::vector<PReseptgyldighet> FestDeserializer::GetReseptgyldighetList(const PLegemiddelMerkevare &pLegemiddelMerkevare) const {
    return std::visit([&pLegemiddelMerkevare] (const auto &deserializer) {
        return deserializer->GetReseptgyldighetList(pLegemiddelMerkevare);
    }, deserializer);
}
std::vector<FestUuid> FestDeserializer::GetRefMerkevare(const PLegemiddelVirkestoff &pvirkestoff) const {
    return std::visit([&pvirkestoff] (const auto &deserializer) {
        return deserializer->GetRefMerkevare(pvirkestoff);
    }, deserializer);
}
std::vector<PFestId> FestDeserializer::GetSortertVirkestoffMedStyrke(const PLegemiddel &pLegemiddel) const {
    return std::visit([&pLegemiddel] (const auto &deserializer) {
        return deserializer->GetSortertVirkestoffMedStyrke(pLegemiddel);
    }, deserializer);
}
std::vector<PFestId> FestDeserializer::GetSortertVirkestoffUtenStyrke(const PLegemiddelMerkevare &pLegemiddelMerkevare) const {
    return std::visit([&pLegemiddelMerkevare] (const auto &deserializer) {
        return deserializer->GetSortertVirkestoffUtenStyrke(pLegemiddelMerkevare);
    }, deserializer);
}
std::vector<FestUuid> FestDeserializer::GetFestUuids(const GenericListItems32 &festUuids) const {
    return std::visit([&festUuids] (const auto &deserializer) {
        return deserializer->GetFestUuids(festUuids);
    }, deserializer);
}
std::vector<FestUuid> FestDeserializer::GetFestUuids(const GenericListItems64 &festUuids) const {
    return std::visit([&festUuids] (const auto &deserializer) {
        return deserializer->GetFestUuids(festUuids);
    }, deserializer);
}
std::vector<FestUuid> FestDeserializer::GetFestUuids(const std::variant<GenericListItems32,GenericListItems64> &festUuids) const {
    return std::visit([&festUuids] (const auto &deserializer) {
        return deserializer->GetFestUuids(festUuids);
    }, deserializer);
}
std::vector<FestDbQuota> FestDeserializer::GetQuotas() const {
    return std::visit([] (const auto &deserializer) {
        return deserializer->GetQuotas();
    }, deserializer);
}
void FestDeserializer::Preload(FestSerializer &serializer) const {
    return std::visit([&serializer] (const auto &deserializer) {
        return deserializer->Preload(serializer);
    }, deserializer);
}
void FestDeserializer::Preload(FestSerializer_0 &serializer) const {
    return std::visit([&serializer] (const auto &deserializer) {
        return deserializer->Preload(serializer);
    }, deserializer);
}
