//
// Created by sigsegv on 6/7/24.
//

#include "FestSerializer.h"
#include "FestDeserializer.h"
#include "FestVectors.h"
#include <sstream>
#include <iostream>
#include <functional>

static const char *festVersion1 = "2024-03-19T01:09:37";
static const char *festVersion2 = "2024-04-08T12:24:39";
static const char *festVersion3 = "2024-04-24T00:50:56";
static const char *festVersion4 = "2024-05-07T08:20:50";
static const char *festVersion5 = "2024-05-27T12:19:41";

static OppfLegemiddelMerkevare GetMerkevare1() {
    LegemiddelCore legemiddelCore{
        {{{"N02AJ07", "Kodein og acetylsalisylsyre"}, "2.16.578.1.12.4.1.1.7180"}},
        "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg",
        {{"B", "Reseptgruppe B"}},
        {{{"53", "Tablett"}, "2.16.578.1.12.4.1.1.7448"}},
        {"ID_491E7F6C-23A9-45C3-A906-95A1332AD5BD"},
        {{"2", "Søknad vurderes av apotek"}},
        MaybeBoolean::MTRUE,
        {}
    };
    Legemiddel legemiddel{
        legemiddelCore,
        {
                {{{"53", "Oral bruk"}, "2.16.578.1.12.4.1.1.7477"}},
                {{{"13", "tablet"}, "2.16.578.1.12.4.1.1.7480"}},
                {},
                {},
                {},
                {},
                {},
                {},
                {},
                {},
                MaybeBoolean::UNSPECIFIED
        },
        {
                "ID_DB70B415-5246-48A6-8AD5-58F81146EF69",
                "ID_BCD85F75-B19A-4C22-BDBD-A6896A272316",
                "ID_439C09EE-C03B-4531-BD4A-48ECC5AF425D"
        }
    };
    Reseptgyldighet reseptgyldighet{"P1Y", {}};
    std::vector<Reseptgyldighet> reseptgyldighetList{reseptgyldighet};
    LegemiddelMerkevare legemiddelMerkevare{
        legemiddel,
        {{"11", "Krever godkj. Fritak"}},
        "ID_000A27B8-3930-4264-80F9-CDB14C895662",
        "Kodimagnyl Ikke-stoppende dak",
        "Tablett, filmdrasjert",
        "Orifarm Healthcare",
        reseptgyldighetList,
        MaybeBoolean::UNSPECIFIED,
        "",
        {},
        {},
        {},
        {}
    };
    return {{"ID_FDEE3880-C783-4A48-A3D0-1A83603E22B0", "2024-01-06T00:50:03", {"A", "Aktiv oppføring"}}, legemiddelMerkevare};
}

static OppfLegemiddelMerkevare GetMerkevare2() {
    LegemiddelCore legemiddelCore{
            {{{"P01AB03", "Ornidazol"}, "2.16.578.1.12.4.1.1.7180"}},
            "Tiberal tab 500 mg",
            {{"C", "Reseptgruppe C"}},
            {{{"53", "Tablett"}, "2.16.578.1.12.4.1.1.7448"}},
            {"ID_491E7F6C-23A9-45C3-A906-95A1332AD5BD"},
            {{"2", "Søknad vurderes av apotek"}},
            MaybeBoolean::UNSPECIFIED,
            {}
    };
    Legemiddel legemiddel{
            legemiddelCore,
            {
                    {{{"53", "Oral bruk"}, "2.16.578.1.12.4.1.1.7477"}},
                    {{{"13", "tablet"}, "2.16.578.1.12.4.1.1.7480"}},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    {},
                    MaybeBoolean::UNSPECIFIED
            },
            {
                    "ID_E05096B7-CAF8-4AA1-84CF-BA60544E9C4A"
            }
    };
    Reseptgyldighet reseptgyldighet{"P1Y", {}};
    std::vector<Reseptgyldighet> reseptgyldighetList{reseptgyldighet};
    LegemiddelMerkevare legemiddelMerkevare{
            legemiddel,
            {{"11", "Krever godkj. Fritak"}},
            "ID_000BFBF7-8101-466D-A2F9-EDC055808F1A",
            "Tiberal",
            "Tablett",
            "Laboratoires SERB",
            reseptgyldighetList,
            MaybeBoolean::UNSPECIFIED,
            "",
            {},
            {},
            {},
            {}
    };
    return {{"ID_5D5B4373-0611-4F44-BA26-4D2DB36ECBB0", "2021-07-02T00:53:48", {"A", "Aktiv oppføring"}}, legemiddelMerkevare};
}

static Fest GetFest1() {
    Fest fest{};
    fest.SetHentetDato(festVersion1);
    fest.Add(GetMerkevare1());
    return fest;
}

static Fest GetFest2() {
    Fest fest{};
    fest.SetHentetDato(festVersion2);
    fest.Add(GetMerkevare2());
    return fest;
}

static std::string WriteFest(const std::function<void (FestSerializer &)> &func) {
    std::shared_ptr<std::stringstream> sstr = std::make_shared<std::stringstream>();
    FestSerializer festSerializer{sstr};
    func(festSerializer);
    if (!festSerializer.Write()) {
        std::cerr << "Write FEST failed\n";
        throw std::exception();
    }
    return sstr->str();
}

static std::string WriteFestVersion(const std::function<void (FestSerializer &)> &func, uint8_t major, uint8_t minor, uint8_t patch) {
    std::shared_ptr<std::stringstream> sstr = std::make_shared<std::stringstream>();
    FestSerializer festSerializer{sstr};
    func(festSerializer);
    if (!festSerializer.WriteVersion(major, minor, patch)) {
        std::cerr << "Write FEST failed\n";
        throw std::exception();
    }
    return sstr->str();
}

std::vector<FestVectors> GetFestVectors(const FestDeserializer &festDeserializer) {
    std::vector<FestVectors> festVectors{};
    festDeserializer.ForEachFests([&festDeserializer, &festVectors] (const PFest &pFest) {
        auto fest = festDeserializer.Unpack(pFest);
        festVectors.emplace_back(fest);
    });
    return festVectors;
}

void AssertVersion(const FestDeserializer &deserializer, int major, int minor , int patch) {
    if (deserializer.GetVersionMajor() != major) {
        std::cerr << "Expected major version " << major << ", but found " << deserializer.GetVersionMajor() << "\n";
        exit(1);
    }
    if (deserializer.GetVersionMinor() != minor) {
        std::cerr << "Expected minor version " << minor << ", but found " << deserializer.GetVersionMinor() << "\n";
        exit(1);
    }
    if (deserializer.GetVersionPatch() != patch) {
        std::cerr << "Expected patch version " << patch << ", but found " << deserializer.GetVersionPatch() << "\n";
        exit(1);
    }
}

template <class T> void AssertSize(const std::vector<T> &vec, size_t size) {
    if (vec.size() != size) {
        std::cerr << "Size mismatch, expected " << size << ", found " << vec.size() << "\n";
        exit(1);
    }
}

void AssertTrue(bool result) {
    if (!result) {
        std::cerr << "Expected true, got false\n";
        exit(1);
    }
}

void AssertEquals(const std::string &value, const std::string &expected) {
    if (value != expected) {
        std::cerr << "Expected "<< expected << ", but got " << value << "\n";
        exit(1);
    }
}

int main() {
    std::string emptyDb = WriteFest([] (auto &) {});
    std::cout << "Empty DB size " << emptyDb.size() << "\n";
    std::string emptyDb_0_2_0 = WriteFestVersion([] (auto &) {}, 0, 2, 0);
    std::cout << "Empty DB v0.2.0 size " << emptyDb_0_2_0.size() << "\n";
    std::string emptyDb_0_1_0 = WriteFestVersion([] (auto &) {}, 0, 1, 0);
    std::cout << "Empty DB v0.1.0 size " << emptyDb_0_1_0.size() << "\n";
    std::string emptyDb_0_0_0 = WriteFestVersion([] (auto &) {}, 0, 0, 0);
    std::cout << "Empty DB v0.0.0 size " << emptyDb_0_0_0.size() << "\n";

    auto festInput1 = GetFest1();

    std::string fest1Db = WriteFest([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    });
    std::cout << "DB 1 size " << fest1Db.size() << "\n";
    std::string fest1Db_0_2_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 0, 2, 0);
    std::cout << "DB 1 v0.2.0 size " << fest1Db_0_2_0.size() << "\n";
    std::string fest1Db_0_1_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 0, 1, 0);
    std::cout << "DB 1 v0.1.0 size " << fest1Db_0_1_0.size() << "\n";
    std::string fest1Db_0_0_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 0, 0, 0);
    std::cout << "DB 1 v0.0.0 size " << fest1Db_0_0_0.size() << "\n";

    {
        FestDeserializer festDeserializer{emptyDb.data(), emptyDb.size()};
        {
            AssertVersion(festDeserializer, 0, 2, 0);
            auto festVectors = GetFestVectors(festDeserializer);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_0_2_0{emptyDb_0_2_0.data(), emptyDb_0_2_0.size()};
        {
            AssertVersion(festDeserializer_0_2_0, 0, 2, 0);
            auto festVectors = GetFestVectors(festDeserializer_0_2_0);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_0_1_0{emptyDb_0_1_0.data(), emptyDb_0_1_0.size()};
        {
            AssertVersion(festDeserializer_0_1_0, 0, 1, 0);
            auto festVectors = GetFestVectors(festDeserializer_0_1_0);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_0_0_0{emptyDb_0_0_0.data(), emptyDb_0_0_0.size()};
        {
            AssertVersion(festDeserializer_0_0_0, 0, 0, 0);
            auto festVectors = GetFestVectors(festDeserializer_0_0_0);
            AssertSize(festVectors, 0);
        }
    }

    {
        FestDeserializer festDeserializerDb1{fest1Db.data(), fest1Db.size()};
        {
            AssertVersion(festDeserializerDb1, 0, 2, 0);
            auto festVectors = GetFestVectors(festDeserializerDb1);
            AssertSize(festVectors, 1);
            auto fest1 = festVectors[0];
            AssertEquals(fest1.GetDato(), festVersion1);
        }
    }
    {
        FestDeserializer festDeserializerDb1_0_2_0{fest1Db_0_2_0.data(), fest1Db_0_2_0.size()};
        {
            AssertVersion(festDeserializerDb1_0_2_0, 0, 2, 0);
            auto festVectors = GetFestVectors(festDeserializerDb1_0_2_0);
            AssertSize(festVectors, 1);
            auto fest1 = festVectors[0];
            AssertEquals(fest1.GetDato(), festVersion1);
        }
    }
    {
        FestDeserializer festDeserializerDb1_0_1_0{fest1Db_0_1_0.data(), fest1Db_0_1_0.size()};
        {
            AssertVersion(festDeserializerDb1_0_1_0, 0, 1, 0);
            auto festVectors = GetFestVectors(festDeserializerDb1_0_1_0);
            AssertSize(festVectors, 1);
            auto fest1 = festVectors[0];
            AssertEquals(fest1.GetDato(), festVersion1);
        }
    }
    {
        FestDeserializer festDeserializerDb1_0_0_0{fest1Db_0_0_0.data(), fest1Db_0_0_0.size()};
        {
            AssertVersion(festDeserializerDb1_0_0_0, 0, 0, 0);
            auto festVectors = GetFestVectors(festDeserializerDb1_0_0_0);
            AssertSize(festVectors, 1);
            auto fest1 = festVectors[0];
            AssertEquals(fest1.GetDato(), festVersion1);
        }
    }
}