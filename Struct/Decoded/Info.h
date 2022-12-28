//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_INFO_H
#define LEGEMFEST_INFO_H

#include <string>

class Info {
private:
    std::string id;
    std::string betegnelse;
    std::string kortnavn;
    std::string ansvarligUtgiver;
public:
    Info() : id(), betegnelse(), kortnavn(), ansvarligUtgiver() {}
    Info(const std::string &id, const std::string &betegnelse, const std::string &kortnavn,
         const std::string &ansvarligUtgiver) :
            id(id), betegnelse(betegnelse), kortnavn(kortnavn), ansvarligUtgiver(ansvarligUtgiver) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetBetegnelse() const;
    [[nodiscard]] std::string GetKortnavn() const;
    [[nodiscard]] std::string GetAnsvarligUtgiver() const;
};


#endif //LEGEMFEST_INFO_H
