//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_FESTDATA_H
#define LEGEMFEST_FESTDATA_H

class FestSerializer;
class PFest_V_0_0_0;
class PFest_V_0_2_0_or_later;
class PFest_V_0_2_0;
class PFest_V_0_3_0;
class PFest_V_0_4_0;

class FestData {
    friend FestSerializer;
    friend PFest_V_0_0_0;
    friend PFest_V_0_2_0_or_later;
    friend PFest_V_0_2_0;
    friend PFest_V_0_3_0;
    friend PFest_V_0_4_0;
private:
    std::string dato;
    std::vector<uint16_t> legemiddelMerkevare_0_0_0{};
    std::vector<uint16_t> legemiddelMerkevare_0_4_0{};
    std::vector<uint32_t> legemiddelpakning_0_0_0{};
    std::vector<uint32_t> legemiddelpakning_0_4_0{};
    std::vector<uint16_t> legemiddelVirkestoff_0_0_0{};
    std::vector<uint16_t> legemiddelVirkestoff_0_4_0{};
    std::vector<uint16_t> medForbrMatr{};
    std::vector<uint16_t> naringsmiddel{};
    std::vector<uint16_t> brystprotese{};
    std::vector<uint16_t> legemiddeldose_0_0_0{};
    std::vector<uint16_t> legemiddeldose_0_4_0{};
    std::vector<uint16_t> virkestoffMedStyrke{};
    std::vector<uint16_t> virkestoff{};
    std::vector<uint16_t> kodeverk_0_0_0{};
    std::vector<uint16_t> kodeverk_0_3_0{};
    std::vector<uint16_t> refusjon{};
    std::vector<uint16_t> vilkar{};
    std::vector<uint16_t> varselSlv{};
    std::vector<uint16_t> byttegruppe{};
    std::vector<uint16_t> interaksjon{};
    std::vector<uint16_t> interaksjonIkkeVurdert{};
    std::vector<uint16_t> strDosering{};
public:
    FestData(const std::string &dato);
};

#endif //LEGEMFEST_FESTDATA_H
