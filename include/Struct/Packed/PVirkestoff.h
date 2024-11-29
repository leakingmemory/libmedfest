//
// Created by sigsegv on 2/4/23.
//

#ifndef LEGEMFEST_PVIRKESTOFF_H
#define LEGEMFEST_PVIRKESTOFF_H

#include "GenericListStorage.h"
#include "PFestId.h"
#include "PString.h"
#include <vector>
#include <variant>

class FestDeserializer;
class Virkestoff;
class FestUuidList_0_0_0;
class FestUuidList_0_4_0;
class FestUuid;
class PVirkestoff_0_4_0;

class PVirkestoff_0_0_0 {
    friend FestDeserializer;
    friend PVirkestoff_0_4_0;
private:
    GenericListItems32 refVirkestoff;
    PFestId id;
    PString navn;
    PString navnEngelsk;
public:
    PVirkestoff_0_0_0(const Virkestoff &, FestUuidList_0_0_0 &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                std::map<std::string,uint32_t> &cache);
    bool operator == (const PVirkestoff_0_0_0 &) const;
    [[nodiscard]] PFestId GetId() const {
        return id;
    }
    [[nodiscard]] PString GetNavn() const {
        return navn;
    }
    [[nodiscard]] PString GetNavnEngelsk() const {
        return navnEngelsk;
    }
};

class PVirkestoff_0_4_0 {
    friend FestDeserializer;
private:
    GenericListItems64 refVirkestoff;
    PFestId id;
    PString navn;
    PString navnEngelsk;
public:
    PVirkestoff_0_4_0(const Virkestoff &, FestUuidList_0_4_0 &festUuidList, std::vector<FestUuid> &idblock, std::string &strblock,
                std::map<std::string,uint32_t> &cache);
    PVirkestoff_0_4_0(const PVirkestoff_0_0_0 &);
    bool operator == (const PVirkestoff_0_4_0 &) const;
    [[nodiscard]] PFestId GetId() const {
        return id;
    }
    [[nodiscard]] PString GetNavn() const {
        return navn;
    }
    [[nodiscard]] PString GetNavnEngelsk() const {
        return navnEngelsk;
    }
};

class PVirkestoff : public std::variant<PVirkestoff_0_0_0,PVirkestoff_0_4_0> {
public:
    PVirkestoff(const PVirkestoff_0_0_0 &);
    PVirkestoff(const PVirkestoff_0_4_0 &);
    [[nodiscard]] PFestId GetId() const {
        if (std::holds_alternative<PVirkestoff_0_4_0>(*this)) {
            return std::get<PVirkestoff_0_4_0>(*this).GetId();
        } else {
            return std::get<PVirkestoff_0_0_0>(*this).GetId();
        }
    }
    [[nodiscard]] PString GetNavn() const {
        if (std::holds_alternative<PVirkestoff_0_4_0>(*this)) {
            return std::get<PVirkestoff_0_4_0>(*this).GetNavn();
        } else {
            return std::get<PVirkestoff_0_0_0>(*this).GetNavn();
        }
    }
    [[nodiscard]] PString GetNavnEngelsk() const {
        if (std::holds_alternative<PVirkestoff_0_4_0>(*this)) {
            return std::get<PVirkestoff_0_4_0>(*this).GetNavnEngelsk();
        } else {
            return std::get<PVirkestoff_0_0_0>(*this).GetNavnEngelsk();
        }
    }
};

#endif //LEGEMFEST_PVIRKESTOFF_H
