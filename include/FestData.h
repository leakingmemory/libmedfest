//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_FESTDATA_H
#define LEGEMFEST_FESTDATA_H

class FestSerializer;
class PFest_V_0_0_0;
class PFest;

class FestData {
    friend FestSerializer;
    friend PFest_V_0_0_0;
    friend PFest;
private:
    std::string dato;
    std::vector<uint16_t> legemiddelMerkevare{};
    std::vector<uint16_t> legemiddelpakning{};
    std::vector<uint16_t> legemiddelVirkestoff{};
    std::vector<uint16_t> medForbrMatr{};
    std::vector<uint16_t> naringsmiddel{};
    std::vector<uint16_t> brystprotese{};
    std::vector<uint16_t> legemiddeldose{};
    std::vector<uint16_t> virkestoffMedStyrke{};
    std::vector<uint16_t> virkestoff{};
    std::vector<uint16_t> kodeverk{};
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
