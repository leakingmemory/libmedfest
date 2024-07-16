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

static OppfLegemiddelpakning GetLegemiddelpakning1() {
    Oppf oppf{"ID_3C5E83CC-44B4-43A3-8FC2-85F6DE4D15C8", "2024-01-06T00:50:03", {"A", "Aktiv oppføring"}};
    LegemiddelCore legemiddelCore{
            {{{"N02AJ07", "Kodein og acetylsalisylsyre"}, "2.16.578.1.12.4.1.1.7180"}},
            "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg",
            {{"B", "Reseptgruppe B"}},
            {{{"53", "Tablett"}, "2.16.578.1.12.4.1.1.7448"}},
            {},
            {{"2", "Søknad vurderes av apotek"}},
            MaybeBoolean::MTRUE,
            {}
    };
    Pakningsinfo pakningsinfo{
            "ID_000A27B8-3930-4264-80F9-CDB14C895662",
            "100",
            {{{"stk", "stykk"}, "2.16.578.1.12.4.1.1.7452"}},
            {{{"169", "Blisterpakning"}, "2.16.578.1.12.4.1.1.7449"}},
            "100",
            {{6, "ED"}},
            {},
            100,
            0,
            0
    };
    Legemiddelpakning legemiddelpakning{
        legemiddelCore,
        {{"11", "Krever godkj. Fritak"}},
        "ID_39A1D548-A66D-4E62-B0BC-FA556660B24E",
        "243591",
        {{"R", "Rom (15-25 grader)"}},
        {pakningsinfo},
        {"2023-06-15", "", "", ""},
        "",
        {},
        {},
        {},
        {},
        false
    };
    return {oppf, legemiddelpakning};
}

static OppfLegemiddelpakning GetLegemiddelpakning2() {
    Oppf oppf{"ID_9A78E5F5-1056-4FB9-AA99-4593AAF61A61", "2021-07-02T00:53:48", {"A", "Aktiv oppføring"}};
    LegemiddelCore legemiddelCore{
            {{{"P01AB03", "Ornidazol"}, "2.16.578.1.12.4.1.1.7180"}},
            "Tiberal tab 500 mg",
            {{"C", "Reseptgruppe C"}},
            {{{"53", "Tablett"}, "2.16.578.1.12.4.1.1.7448"}},
            {},
            {{"2", "Søknad vurderes av apotek"}},
            MaybeBoolean::UNSPECIFIED,
            {}
    };
    Pakningsinfo pakningsinfo{
            "ID_000BFBF7-8101-466D-A2F9-EDC055808F1A",
            "10",
            {{{"stk", "stykk"}, "2.16.578.1.12.4.1.1.7452"}},
            {{{"169", "Blisterpakning"}, "2.16.578.1.12.4.1.1.7449"}},
            "10",
            {{1.5, "g"}},
            {},
            5,
            0,
            0
    };
    Legemiddelpakning legemiddelpakning{
            legemiddelCore,
            {{"11", "Krever godkj. Fritak"}},
            "ID_D308C2C5-7639-4140-A68B-274286296391",
            "364814",
            {{"R", "Rom (15-25 grader)"}},
            {pakningsinfo},
            {"2010-03-01", "", "", ""},
            "",
            {},
            {},
            {},
            {},
            false
    };
    return {oppf, legemiddelpakning};
}

static OppfKodeverk GetAtc1() {
    Oppf oppf{"ID_8D2DBCCC-73E3-40C3-9812-D6957905FFB1", "2024-02-20T00:50:55", ValueWithDistinguishedName("A", "Aktiv oppføring")};
    Info info{"2.16.578.1.12.4.1.1.7180", "ATC - Anatomisk Terapeutisk Kjemisk legemiddelregister", "ATC", "WHO Collaborating Centre for Drug Statistics Methodology (WHOCC)"};
    Element element1{"ID_0011BBC5-0E37-4060-8EB9-B6D044E82958", "J07BN01", {
            {"Covid-19, RNA-based vaccine", "", {{"EN", "ENGELSK"}}},
            {"Covid-19, RNA-basert vaksine", "", {{"NO", "NORSK"}}}
    }};
    Element element2{"ID_0044FC56-66BF-4750-875F-128C66528FF4", "A11HA03", {
            {"Tocopherol (vit E)", "", {{"EN", "ENGELSK"}}},
            {"Tokoferol (Vit E)", "", {{"NO", "NORSK"}}}
    }};
    return {oppf, info, {element1, element2}};
}

static OppfKodeverk GetAtc2() {
    Oppf oppf{"ID_8D2DBCCC-73E3-40C3-9812-D6957905FFB1", "2024-02-20T00:50:55", ValueWithDistinguishedName("A", "Aktiv oppføring")};
    Info info{"2.16.578.1.12.4.1.1.7180", "ATC - Anatomisk Terapeutisk Kjemisk legemiddelregister", "ATC", "WHO Collaborating Centre for Drug Statistics Methodology (WHOCC)"};
    Element element2{"ID_0044FC56-66BF-4750-875F-128C66528FF4", "A11HA03", {
            {"Tocopherol (vit E)", "", {{"EN", "ENGELSK"}}},
            {"Tokoferol (Vit E)", "", {{"NO", "NORSK"}}}
    }};
    Element element3{"ID_00528370-A033-43A1-BAB4-4BD0D20CF4DE", "C01DX16", {
            {"Nicorandil", "", {{"EN", "ENGELSK"}}},
            {"Nikorandil", "", {{"NO", "NORSK"}}}
    }};
    return {oppf, info, {element2, element3}};
}

static Fest GetFest1() {
    Fest fest{};
    fest.SetHentetDato(festVersion1);
    fest.Add(GetMerkevare1());
    fest.Add(GetLegemiddelpakning1());
    fest.Add(GetAtc1());
    return fest;
}

static Fest GetFest2() {
    Fest fest{};
    fest.SetHentetDato(festVersion2);
    fest.Add(GetMerkevare2());
    fest.Add(GetLegemiddelpakning2());
    fest.Add(GetAtc2());
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
    std::string emptyDb_1_1_0 = WriteFestVersion([] (auto &) {}, 1, 1, 0);
    std::cout << "Empty DB v1.1.0 size " << emptyDb_1_1_0.size() << "\n";
    std::string emptyDb_1_0_0 = WriteFestVersion([] (auto &) {}, 1, 0, 0);
    std::cout << "Empty DB v1.0.0 size " << emptyDb_1_0_0.size() << "\n";
    std::string emptyDb_0_4_0 = WriteFestVersion([] (auto &) {}, 0, 4, 0);
    std::cout << "Empty DB v0.4.0 size " << emptyDb_0_4_0.size() << "\n";
    std::string emptyDb_0_3_0 = WriteFestVersion([] (auto &) {}, 0, 3, 0);
    std::cout << "Empty DB v0.3.0 size " << emptyDb_0_3_0.size() << "\n";
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
    std::string fest1Db_1_1_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 1, 1, 0);
    std::cout << "DB 1 v1.1.0 size " << fest1Db_1_1_0.size() << "\n";
    std::string fest1Db_1_0_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 1, 0, 0);
    std::cout << "DB 1 v1.0.0 size " << fest1Db_1_0_0.size() << "\n";
    std::string fest1Db_0_4_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 0, 4, 0);
    std::cout << "DB 1 v0.4.0 size " << fest1Db_0_4_0.size() << "\n";
    std::string fest1Db_0_3_0 = WriteFestVersion([&festInput1] (FestSerializer &serializer) {
        AssertTrue(serializer.Serialize(festInput1));
    }, 0, 3, 0);
    std::cout << "DB 1 v0.3.0 size " << fest1Db_0_3_0.size() << "\n";
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
            AssertVersion(festDeserializer, 0, 4, 0);
            auto festVectors = GetFestVectors(festDeserializer);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_1_1_0{emptyDb_1_1_0.data(), emptyDb_1_1_0.size()};
        {
            AssertVersion(festDeserializer_1_1_0, 1, 1, 0);
            auto festVectors = GetFestVectors(festDeserializer_1_1_0);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_1_0_0{emptyDb_1_0_0.data(), emptyDb_1_0_0.size()};
        {
            AssertVersion(festDeserializer_1_0_0, 1, 0, 0);
            auto festVectors = GetFestVectors(festDeserializer_1_0_0);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_0_4_0{emptyDb_0_4_0.data(), emptyDb_0_4_0.size()};
        {
            AssertVersion(festDeserializer_0_4_0, 0, 4, 0);
            auto festVectors = GetFestVectors(festDeserializer_0_4_0);
            AssertSize(festVectors, 0);
        }
    }
    {
        FestDeserializer festDeserializer_0_3_0{emptyDb_0_3_0.data(), emptyDb_0_3_0.size()};
        {
            AssertVersion(festDeserializer_0_3_0, 0, 3, 0);
            auto festVectors = GetFestVectors(festDeserializer_0_3_0);
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

    FestDeserializer festDeserializerDb1{fest1Db.data(), fest1Db.size()};
    {
        AssertVersion(festDeserializerDb1, 0, 4, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 2);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
        AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_1_1_0{fest1Db_1_1_0.data(), fest1Db_1_1_0.size()};
    {
        AssertVersion(festDeserializerDb1_1_1_0, 1, 1, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_1_1_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_1_1_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_1_1_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_1_1_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_1_1_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_1_1_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_1_1_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 2);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
        AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_1_0_0{fest1Db_1_0_0.data(), fest1Db_1_0_0.size()};
    {
        AssertVersion(festDeserializerDb1_1_0_0, 1, 0, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_1_0_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_1_0_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_1_0_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_1_0_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_1_0_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_1_0_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_1_0_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 2);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
        AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_0_4_0{fest1Db_0_4_0.data(), fest1Db_0_4_0.size()};
    {
        AssertVersion(festDeserializerDb1_0_4_0, 0, 4, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_0_4_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_0_4_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_0_4_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_0_4_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_0_4_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_0_4_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_0_4_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 2);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
        AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_0_3_0{fest1Db_0_3_0.data(), fest1Db_0_3_0.size()};
    {
        AssertVersion(festDeserializerDb1_0_3_0, 0, 3, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_0_3_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_0_3_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_0_3_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_0_3_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_0_3_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_0_3_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_0_3_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 2);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
        AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_0_2_0{fest1Db_0_2_0.data(), fest1Db_0_2_0.size()};
    {
        AssertVersion(festDeserializerDb1_0_2_0, 0, 2, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_0_2_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_0_2_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_0_2_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_0_2_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_0_2_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_0_2_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_0_2_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 1);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_0_1_0{fest1Db_0_1_0.data(), fest1Db_0_1_0.size()};
    {
        AssertVersion(festDeserializerDb1_0_1_0, 0, 1, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_0_1_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_0_1_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_0_1_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_0_1_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_0_1_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_0_1_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_0_1_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 1);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }
    FestDeserializer festDeserializerDb1_0_0_0{fest1Db_0_0_0.data(), fest1Db_0_0_0.size()};
    {
        AssertVersion(festDeserializerDb1_0_0_0, 0, 0, 0);
        auto festVectors = GetFestVectors(festDeserializerDb1_0_0_0);
        AssertSize(festVectors, 1);
        auto fest1 = festVectors[0];
        AssertEquals(fest1.GetDato(), festVersion1);
        auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb1_0_0_0);
        AssertSize(merkevarer1, 1);
        auto pmerkevare1 = merkevarer1[0];
        auto merkevare1 = festDeserializerDb1_0_0_0.Unpack(pmerkevare1);
        AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb1_0_0_0);
        AssertSize(pakninger1, 1);
        auto ppakning1 = pakninger1[0];
        auto pakning1 = festDeserializerDb1_0_0_0.Unpack(ppakning1);
        AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
        auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb1_0_0_0);
        AssertSize(kodeverk1, 1);
        auto atc1 = festDeserializerDb1_0_0_0.Unpack(kodeverk1[0]);
        AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
        auto atc1element = atc1.GetElement();
        AssertSize(atc1element, 2);
        auto atc1element0term = atc1element[0].GetTermList();
        AssertSize(atc1element0term, 1);
        AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
        AssertEquals(atc1element[1].GetKode(), "A11HA03");
    }

    auto festInput2 = GetFest2();

    {
        std::string fest2Db = WriteFest([&festDeserializerDb1, &festInput2](FestSerializer &serializer) {
            festDeserializerDb1.Preload(serializer);
            AssertTrue(serializer.Serialize(festInput2));
        });
        std::cout << "DB 2 size " << fest2Db.size() << "\n";
        std::string fest2Db_1_1_0 = WriteFestVersion(
                [&festDeserializerDb1_1_1_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_1_1_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 2 v1.1.0 size " << fest2Db_1_1_0.size() << "\n";
        std::string fest2Db_1_0_0 = WriteFestVersion(
                [&festDeserializerDb1_1_0_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_1_0_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 0, 0);
        std::cout << "DB 2 v1.0.0 size " << fest2Db_1_0_0.size() << "\n";
        std::string fest2Db_0_4_0 = WriteFestVersion(
                [&festDeserializerDb1_0_4_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_4_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 0, 4, 0);
        std::cout << "DB 2 v0.4.0 size " << fest2Db_0_4_0.size() << "\n";
        std::string fest2Db_0_3_0 = WriteFestVersion(
                [&festDeserializerDb1_0_3_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_3_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 0, 3, 0);
        std::cout << "DB 2 v0.3.0 size " << fest2Db_0_3_0.size() << "\n";
        std::string fest2Db_0_2_0 = WriteFestVersion(
                [&festDeserializerDb1_0_2_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_2_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 0, 2, 0);
        std::cout << "DB 2 v0.2.0 size " << fest2Db_0_2_0.size() << "\n";
        std::string fest2Db_0_1_0 = WriteFestVersion(
                [&festDeserializerDb1_0_1_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_1_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 0, 1, 0);
        std::cout << "DB 2 v0.1.0 size " << fest2Db_0_1_0.size() << "\n";
        std::string fest2Db_0_0_0 = WriteFestVersion(
                [&festDeserializerDb1_0_0_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_0_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 0, 0, 0);
        std::cout << "DB 2 v0.0.0 size " << fest2Db_0_0_0.size() << "\n";

        {
            FestDeserializer festDeserializerDb2{fest2Db.data(), fest2Db.size()};
            {
                AssertVersion(festDeserializerDb2, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb2_1_1_0{fest2Db_1_1_0.data(), fest2Db_1_1_0.size()};
            {
                AssertVersion(festDeserializerDb2_1_1_0, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_1_1_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_1_1_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_1_1_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_1_1_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_1_1_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_1_1_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_1_1_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_1_1_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_1_1_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_1_1_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_1_1_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_1_1_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_1_1_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb2_1_0_0{fest2Db_1_0_0.data(), fest2Db_1_0_0.size()};
            {
                AssertVersion(festDeserializerDb2_1_0_0, 1, 0, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_1_0_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_1_0_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_1_0_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_1_0_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_1_0_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_1_0_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_1_0_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_1_0_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_1_0_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_1_0_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_1_0_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_1_0_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_1_0_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb2_0_4_0{fest2Db_0_4_0.data(), fest2Db_0_4_0.size()};
            {
                AssertVersion(festDeserializerDb2_0_4_0, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_0_4_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_0_4_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_0_4_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_0_4_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_0_4_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_0_4_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_0_4_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_0_4_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_0_4_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_0_4_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_0_4_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_0_4_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_0_4_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
            FestDeserializer festDeserializerDb2_0_3_0{fest2Db_0_3_0.data(), fest2Db_0_3_0.size()};
            {
                AssertVersion(festDeserializerDb2_0_3_0, 0, 3, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_0_3_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_0_3_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_0_3_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_0_3_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_0_3_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_0_3_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_0_3_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_0_3_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_0_3_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_0_3_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_0_3_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_0_3_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_0_3_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
            FestDeserializer festDeserializerDb2_0_2_0{fest2Db_0_2_0.data(), fest2Db_0_2_0.size()};
            {
                AssertVersion(festDeserializerDb2_0_2_0, 0, 2, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_0_2_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_0_2_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_0_2_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_0_2_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_0_2_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_0_2_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_0_2_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_0_2_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_0_2_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_0_2_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_0_2_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_0_2_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_0_2_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 1);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
            FestDeserializer festDeserializerDb2_0_1_0{fest2Db_0_1_0.data(), fest2Db_0_1_0.size()};
            {
                AssertVersion(festDeserializerDb2_0_1_0, 0, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_0_1_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_0_1_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_0_1_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_0_1_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_0_1_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_0_1_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_0_1_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_0_1_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_0_1_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_0_1_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_0_1_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_0_1_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_0_1_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 1);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
            FestDeserializer festDeserializerDb2_0_0_0{fest2Db_0_0_0.data(), fest2Db_0_0_0.size()};
            {
                AssertVersion(festDeserializerDb2_0_0_0, 0, 0, 0);
                auto festVectors = GetFestVectors(festDeserializerDb2_0_0_0);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb2_0_0_0);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb2_0_0_0);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb2_0_0_0.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb2_0_0_0.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb2_0_0_0);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb2_0_0_0);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb2_0_0_0.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb2_0_0_0.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb2_0_0_0);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb2_0_0_0);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb2_0_0_0.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb2_0_0_0.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 1);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
            std::string fest3Db_0_3_0_to_0_4 = WriteFest(
                    [&festDeserializerDb2_0_3_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_3_0.Preload(serializer);
                    });
            std::cout << "DB 3 upgraded from v0.3.0 to v0.4.0 size " << fest3Db_0_3_0_to_0_4.size() << "\n";
            std::string fest3Db_0_2_0_to_0_4 = WriteFest(
                    [&festDeserializerDb2_0_2_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_2_0.Preload(serializer);
                    });
            std::cout << "DB 3 upgraded from v0.2.0 to v0.4.0 size " << fest3Db_0_2_0_to_0_4.size() << "\n";
            std::string fest3Db_0_1_0_to_0_4 = WriteFest(
                    [&festDeserializerDb2_0_1_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_1_0.Preload(serializer);
                    });
            std::cout << "DB 3 upgraded from v0.1.0 to v0.4.0 size " << fest3Db_0_1_0_to_0_4.size() << "\n";
            std::string fest3Db_0_0_0_to_0_4 = WriteFest(
                    [&festDeserializerDb2_0_0_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_0_0.Preload(serializer);
                    });
            std::cout << "DB 3 upgraded from v0.0.0 to v0.4.0 size " << fest3Db_0_0_0_to_0_4.size() << "\n";
            {
                FestDeserializer festDeserializerDb3_0_3_0_to_0_4{fest3Db_0_3_0_to_0_4.data(),
                                                                  fest3Db_0_3_0_to_0_4.size()};
                {
                    AssertVersion(festDeserializerDb3_0_3_0_to_0_4, 0, 4, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_3_0_to_0_4);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_3_0_to_0_4);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_3_0_to_0_4);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_3_0_to_0_4.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_3_0_to_0_4.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_3_0_to_0_4);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_3_0_to_0_4);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_3_0_to_0_4.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_3_0_to_0_4.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_3_0_to_0_4);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_3_0_to_0_4);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_3_0_to_0_4.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_3_0_to_0_4.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 2);
                    AssertSize(atc2element0term, 2);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                    AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                    AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_2_0_to_0_4{fest3Db_0_2_0_to_0_4.data(),
                                                                     fest3Db_0_2_0_to_0_4.size()};
                {
                    AssertVersion(festDeserializerDb3_0_2_0_to_0_4, 0, 4, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_2_0_to_0_4);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_2_0_to_0_4);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_2_0_to_0_4);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_2_0_to_0_4.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_2_0_to_0_4.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_2_0_to_0_4);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_2_0_to_0_4);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_2_0_to_0_4.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_2_0_to_0_4.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_2_0_to_0_4);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_2_0_to_0_4);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_2_0_to_0_4.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_2_0_to_0_4.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_1_0_to_0_4{fest3Db_0_1_0_to_0_4.data(),
                                                                  fest3Db_0_1_0_to_0_4.size()};
                {
                    AssertVersion(festDeserializerDb3_0_1_0_to_0_4, 0, 4, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_1_0_to_0_4);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_1_0_to_0_4);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_1_0_to_0_4);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_1_0_to_0_4.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_1_0_to_0_4.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_1_0_to_0_4);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_1_0_to_0_4);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_1_0_to_0_4.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_1_0_to_0_4.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_1_0_to_0_4);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_1_0_to_0_4);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_1_0_to_0_4.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_1_0_to_0_4.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_0_0_to_0_4{fest3Db_0_0_0_to_0_4.data(),
                                                                  fest3Db_0_0_0_to_0_4.size()};
                {
                    AssertVersion(festDeserializerDb3_0_0_0_to_0_4, 0, 4, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_0_0_to_0_4);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_0_0_to_0_4);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_0_0_to_0_4);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_0_0_to_0_4.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_0_0_to_0_4.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_0_0_to_0_4);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_0_0_to_0_4);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_0_0_to_0_4.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_0_0_to_0_4.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_0_0_to_0_4);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_0_0_to_0_4);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_0_0_to_0_4.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_0_0_to_0_4.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            std::string fest3Db_0_4_0_to_latest = WriteFestVersion(
                    [&festDeserializerDb2_0_4_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_4_0.Preload(serializer);
                    }, 1, 0, 0);
            std::cout << "DB 3 upgraded from v0.4.0 size " << fest3Db_0_4_0_to_latest.size() << "\n";
            std::string fest3Db_0_3_0_to_latest = WriteFestVersion(
                    [&festDeserializerDb2_0_3_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_3_0.Preload(serializer);
                    }, 1, 0, 0);
            std::cout << "DB 3 upgraded from v0.3.0 size " << fest3Db_0_3_0_to_latest.size() << "\n";
            std::string fest3Db_0_2_0_to_latest = WriteFestVersion(
                    [&festDeserializerDb2_0_2_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_2_0.Preload(serializer);
                    }, 1, 0, 0);
            std::cout << "DB 3 upgraded from v0.2.0 size " << fest3Db_0_2_0_to_latest.size() << "\n";
            std::string fest3Db_0_1_0_to_latest = WriteFestVersion(
                    [&festDeserializerDb2_0_1_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_1_0.Preload(serializer);
                    }, 1, 0, 0);
            std::cout << "DB 3 upgraded from v0.1.0 size " << fest3Db_0_1_0_to_latest.size() << "\n";
            std::string fest3Db_0_0_0_to_latest = WriteFestVersion(
                    [&festDeserializerDb2_0_0_0](FestSerializer &serializer) {
                        festDeserializerDb2_0_0_0.Preload(serializer);
                    }, 1, 0, 0);
            std::cout << "DB 3 upgraded from v0.0.0 size " << fest3Db_0_0_0_to_latest.size() << "\n";
            {
                FestDeserializer festDeserializerDb3_0_4_0_to_latest{fest3Db_0_4_0_to_latest.data(),
                                                                     fest3Db_0_4_0_to_latest.size()};
                {
                    AssertVersion(festDeserializerDb3_0_4_0_to_latest, 1, 0, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_4_0_to_latest);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_4_0_to_latest);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_4_0_to_latest);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_4_0_to_latest.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_4_0_to_latest.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_4_0_to_latest);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_4_0_to_latest);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_4_0_to_latest.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_4_0_to_latest.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_4_0_to_latest);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_4_0_to_latest);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_4_0_to_latest.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_4_0_to_latest.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 2);
                    AssertSize(atc2element0term, 2);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                    AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                    AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_3_0_to_latest{fest3Db_0_3_0_to_latest.data(),
                                                                     fest3Db_0_3_0_to_latest.size()};
                {
                    AssertVersion(festDeserializerDb3_0_3_0_to_latest, 1, 0, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_3_0_to_latest);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_3_0_to_latest);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_3_0_to_latest);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_3_0_to_latest.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_3_0_to_latest.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_3_0_to_latest);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_3_0_to_latest);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_3_0_to_latest.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_3_0_to_latest.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_3_0_to_latest);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_3_0_to_latest);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_3_0_to_latest.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_3_0_to_latest.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 2);
                    AssertSize(atc2element0term, 2);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                    AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                    AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_2_0_to_latest{fest3Db_0_2_0_to_latest.data(),
                                                                     fest3Db_0_2_0_to_latest.size()};
                {
                    AssertVersion(festDeserializerDb3_0_2_0_to_latest, 1, 0, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_2_0_to_latest);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_2_0_to_latest);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_2_0_to_latest);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_2_0_to_latest.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_2_0_to_latest.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_2_0_to_latest);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_2_0_to_latest);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_2_0_to_latest.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_2_0_to_latest.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_2_0_to_latest);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_2_0_to_latest);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_2_0_to_latest.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_2_0_to_latest.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_1_0_to_latest{fest3Db_0_1_0_to_latest.data(),
                                                                     fest3Db_0_1_0_to_latest.size()};
                {
                    AssertVersion(festDeserializerDb3_0_1_0_to_latest, 1, 0, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_1_0_to_latest);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_1_0_to_latest);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_1_0_to_latest);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_1_0_to_latest.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_1_0_to_latest.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_1_0_to_latest);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_1_0_to_latest);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_1_0_to_latest.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_1_0_to_latest.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_1_0_to_latest);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_1_0_to_latest);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_1_0_to_latest.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_1_0_to_latest.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
            {
                FestDeserializer festDeserializerDb3_0_0_0_to_latest{fest3Db_0_0_0_to_latest.data(),
                                                                     fest3Db_0_0_0_to_latest.size()};
                {
                    AssertVersion(festDeserializerDb3_0_0_0_to_latest, 1, 0, 0);
                    auto festVectors = GetFestVectors(festDeserializerDb3_0_0_0_to_latest);
                    AssertSize(festVectors, 2);
                    auto fest1 = festVectors[0];
                    auto fest2 = festVectors[1];
                    AssertEquals(fest1.GetDato(), festVersion1);
                    AssertEquals(fest2.GetDato(), festVersion2);
                    auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb3_0_0_0_to_latest);
                    auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb3_0_0_0_to_latest);
                    AssertSize(merkevarer1, 1);
                    AssertSize(merkevarer2, 1);
                    auto pmerkevare1 = merkevarer1[0];
                    auto merkevare1 = festDeserializerDb3_0_0_0_to_latest.Unpack(pmerkevare1);
                    AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                                 "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto pmerkevare2 = merkevarer2[0];
                    auto merkevare2 = festDeserializerDb3_0_0_0_to_latest.Unpack(pmerkevare2);
                    AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb3_0_0_0_to_latest);
                    auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb3_0_0_0_to_latest);
                    AssertSize(pakninger1, 1);
                    AssertSize(pakninger2, 1);
                    auto ppakning1 = pakninger1[0];
                    auto pakning1 = festDeserializerDb3_0_0_0_to_latest.Unpack(ppakning1);
                    AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                    auto ppakning2 = pakninger2[0];
                    auto pakning2 = festDeserializerDb3_0_0_0_to_latest.Unpack(ppakning2);
                    AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                    auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb3_0_0_0_to_latest);
                    auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb3_0_0_0_to_latest);
                    AssertSize(kodeverk1, 1);
                    AssertSize(kodeverk2, 1);
                    auto atc1 = festDeserializerDb3_0_0_0_to_latest.Unpack(kodeverk1[0]);
                    auto atc2 = festDeserializerDb3_0_0_0_to_latest.Unpack(kodeverk2[0]);
                    AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                    AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                    auto atc1element = atc1.GetElement();
                    auto atc2element = atc2.GetElement();
                    AssertSize(atc1element, 2);
                    AssertSize(atc2element, 2);
                    auto atc1element0term = atc1element[0].GetTermList();
                    auto atc2element0term = atc2element[0].GetTermList();
                    AssertSize(atc1element0term, 1);
                    AssertSize(atc2element0term, 1);
                    AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                    AssertEquals(atc2element0term[0].GetTerm(), "Tokoferol (Vit E)");
                    AssertEquals(atc1element[1].GetKode(), "A11HA03");
                    AssertEquals(atc2element[1].GetKode(), "C01DX16");
                }
            }
        }
    }
    {
        std::string fest4Db_0_3_0_to_0_4 = WriteFest(
                [&festDeserializerDb1_0_3_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_3_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                });
        std::cout << "DB 4 upgraded from v0.3.0 to v0.4.0 size " << fest4Db_0_3_0_to_0_4.size() << "\n";
        std::string fest4Db_0_2_0_to_0_4 = WriteFest(
                [&festDeserializerDb1_0_2_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_2_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                });
        std::cout << "DB 4 upgraded from v0.2.0 to v0.4.0 size " << fest4Db_0_2_0_to_0_4.size() << "\n";
        std::string fest4Db_0_1_0_to_0_4 = WriteFest(
                [&festDeserializerDb1_0_1_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_1_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                });
        std::cout << "DB 4 upgraded from v0.1.0 to v0.4.0 size " << fest4Db_0_1_0_to_0_4.size() << "\n";
        std::string fest4Db_0_0_0_to_0_4 = WriteFest(
                [&festDeserializerDb1_0_0_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_0_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                });
        std::cout << "DB 4 upgraded from v0.0.0 to v0.4.0 size " << fest4Db_0_0_0_to_0_4.size() << "\n";
        {
            FestDeserializer festDeserializerDb4_0_3_0_to_0_4{fest4Db_0_3_0_to_0_4.data(),
                                                              fest4Db_0_3_0_to_0_4.size()};
            {
                AssertVersion(festDeserializerDb4_0_3_0_to_0_4, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_3_0_to_0_4);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_3_0_to_0_4);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_3_0_to_0_4);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_3_0_to_0_4.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_3_0_to_0_4.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_3_0_to_0_4);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_3_0_to_0_4);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_3_0_to_0_4.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_3_0_to_0_4.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_3_0_to_0_4);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_3_0_to_0_4);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_3_0_to_0_4.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_3_0_to_0_4.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_2_0_to_0_4{fest4Db_0_2_0_to_0_4.data(),
                                                                 fest4Db_0_2_0_to_0_4.size()};
            {
                AssertVersion(festDeserializerDb4_0_2_0_to_0_4, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_2_0_to_0_4);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_2_0_to_0_4);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_2_0_to_0_4);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_2_0_to_0_4.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_2_0_to_0_4.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_2_0_to_0_4);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_2_0_to_0_4);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_2_0_to_0_4.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_2_0_to_0_4.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_2_0_to_0_4);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_2_0_to_0_4);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_2_0_to_0_4.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_2_0_to_0_4.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_1_0_to_0_4{fest4Db_0_1_0_to_0_4.data(),
                                                              fest4Db_0_1_0_to_0_4.size()};
            {
                AssertVersion(festDeserializerDb4_0_1_0_to_0_4, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_1_0_to_0_4);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_1_0_to_0_4);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_1_0_to_0_4);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_1_0_to_0_4.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_1_0_to_0_4.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_1_0_to_0_4);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_1_0_to_0_4);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_1_0_to_0_4.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_1_0_to_0_4.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_1_0_to_0_4);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_1_0_to_0_4);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_1_0_to_0_4.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_1_0_to_0_4.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_0_0_to_0_4{fest4Db_0_0_0_to_0_4.data(),
                                                              fest4Db_0_0_0_to_0_4.size()};
            {
                AssertVersion(festDeserializerDb4_0_0_0_to_0_4, 0, 4, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_0_0_to_0_4);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_0_0_to_0_4);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_0_0_to_0_4);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_0_0_to_0_4.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_0_0_to_0_4.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_0_0_to_0_4);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_0_0_to_0_4);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_0_0_to_0_4.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_0_0_to_0_4.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_0_0_to_0_4);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_0_0_to_0_4);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_0_0_to_0_4.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_0_0_to_0_4.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        std::string fest4Db_1_0_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_1_0_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_1_0_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v1.0.0 size " << fest4Db_1_0_0_to_latest.size() << "\n";
        std::string fest4Db_0_4_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_0_4_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_4_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v0.4.0 size " << fest4Db_0_4_0_to_latest.size() << "\n";
        std::string fest4Db_0_3_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_0_3_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_3_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v0.3.0 size " << fest4Db_0_3_0_to_latest.size() << "\n";
        std::string fest4Db_0_2_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_0_2_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_2_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v0.2.0 size " << fest4Db_0_2_0_to_latest.size() << "\n";
        std::string fest4Db_0_1_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_0_1_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_1_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v0.1.0 size " << fest4Db_0_1_0_to_latest.size() << "\n";
        std::string fest4Db_0_0_0_to_latest = WriteFestVersion(
                [&festDeserializerDb1_0_0_0, &festInput2](FestSerializer &serializer) {
                    festDeserializerDb1_0_0_0.Preload(serializer);
                    AssertTrue(serializer.Serialize(festInput2));
                }, 1, 1, 0);
        std::cout << "DB 4 upgraded from v0.0.0 size " << fest4Db_0_0_0_to_latest.size() << "\n";
        {
            FestDeserializer festDeserializerDb4_1_0_0_to_latest{fest4Db_1_0_0_to_latest.data(),
                                                                 fest4Db_1_0_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_1_0_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_1_0_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_1_0_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_1_0_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_1_0_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_1_0_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_1_0_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_1_0_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_1_0_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_1_0_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_1_0_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_1_0_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_1_0_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_1_0_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_4_0_to_latest{fest4Db_0_4_0_to_latest.data(),
                                                                 fest4Db_0_4_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_0_4_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_4_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_4_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_4_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_4_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_4_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_4_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_4_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_4_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_4_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_4_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_4_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_4_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_4_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_3_0_to_latest{fest4Db_0_3_0_to_latest.data(),
                                                                 fest4Db_0_3_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_0_3_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_3_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_3_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_3_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_3_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_3_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_3_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_3_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_3_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_3_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_3_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_3_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_3_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_3_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 2);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-based vaccine");
                AssertEquals(atc1element0term[1].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_2_0_to_latest{fest4Db_0_2_0_to_latest.data(),
                                                                 fest4Db_0_2_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_0_2_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_2_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_2_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_2_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_2_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_2_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_2_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_2_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_2_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_2_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_2_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_2_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_2_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_2_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_1_0_to_latest{fest4Db_0_1_0_to_latest.data(),
                                                                 fest4Db_0_1_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_0_1_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_1_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_1_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_1_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_1_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_1_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_1_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_1_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_1_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_1_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_1_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_1_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_1_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_1_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
        {
            FestDeserializer festDeserializerDb4_0_0_0_to_latest{fest4Db_0_0_0_to_latest.data(),
                                                                 fest4Db_0_0_0_to_latest.size()};
            {
                AssertVersion(festDeserializerDb4_0_0_0_to_latest, 1, 1, 0);
                auto festVectors = GetFestVectors(festDeserializerDb4_0_0_0_to_latest);
                AssertSize(festVectors, 2);
                auto fest1 = festVectors[0];
                auto fest2 = festVectors[1];
                AssertEquals(fest1.GetDato(), festVersion1);
                AssertEquals(fest2.GetDato(), festVersion2);
                auto merkevarer1 = fest1.GetLegemiddelMerkevare(festDeserializerDb4_0_0_0_to_latest);
                auto merkevarer2 = fest2.GetLegemiddelMerkevare(festDeserializerDb4_0_0_0_to_latest);
                AssertSize(merkevarer1, 1);
                AssertSize(merkevarer2, 1);
                auto pmerkevare1 = merkevarer1[0];
                auto merkevare1 = festDeserializerDb4_0_0_0_to_latest.Unpack(pmerkevare1);
                AssertEquals(merkevare1.GetLegemiddelMerkevare().GetNavnFormStyrke(),
                             "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto pmerkevare2 = merkevarer2[0];
                auto merkevare2 = festDeserializerDb4_0_0_0_to_latest.Unpack(pmerkevare2);
                AssertEquals(merkevare2.GetLegemiddelMerkevare().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto pakninger1 = fest1.GetLegemiddelPakning(festDeserializerDb4_0_0_0_to_latest);
                auto pakninger2 = fest2.GetLegemiddelPakning(festDeserializerDb4_0_0_0_to_latest);
                AssertSize(pakninger1, 1);
                AssertSize(pakninger2, 1);
                auto ppakning1 = pakninger1[0];
                auto pakning1 = festDeserializerDb4_0_0_0_to_latest.Unpack(ppakning1);
                AssertEquals(pakning1.GetLegemiddelpakning().GetNavnFormStyrke(), "Kodimagnyl Ikke-stoppende dak tab 9,6 mg/500 mg/150 mg");
                auto ppakning2 = pakninger2[0];
                auto pakning2 = festDeserializerDb4_0_0_0_to_latest.Unpack(ppakning2);
                AssertEquals(pakning2.GetLegemiddelpakning().GetNavnFormStyrke(), "Tiberal tab 500 mg");
                auto kodeverk1 = fest1.GetKodeverk(festDeserializerDb4_0_0_0_to_latest);
                auto kodeverk2 = fest2.GetKodeverk(festDeserializerDb4_0_0_0_to_latest);
                AssertSize(kodeverk1, 1);
                AssertSize(kodeverk2, 1);
                auto atc1 = festDeserializerDb4_0_0_0_to_latest.Unpack(kodeverk1[0]);
                auto atc2 = festDeserializerDb4_0_0_0_to_latest.Unpack(kodeverk2[0]);
                AssertEquals(atc1.GetInfo().GetKortnavn(), "ATC");
                AssertEquals(atc2.GetInfo().GetKortnavn(), "ATC");
                auto atc1element = atc1.GetElement();
                auto atc2element = atc2.GetElement();
                AssertSize(atc1element, 2);
                AssertSize(atc2element, 2);
                auto atc1element0term = atc1element[0].GetTermList();
                auto atc2element0term = atc2element[0].GetTermList();
                AssertSize(atc1element0term, 1);
                AssertSize(atc2element0term, 2);
                AssertEquals(atc1element0term[0].GetTerm(), "Covid-19, RNA-basert vaksine");
                AssertEquals(atc2element0term[0].GetTerm(), "Tocopherol (vit E)");
                AssertEquals(atc2element0term[1].GetTerm(), "Tokoferol (Vit E)");
                AssertEquals(atc1element[1].GetKode(), "A11HA03");
                AssertEquals(atc2element[1].GetKode(), "C01DX16");
            }
        }
    }
}