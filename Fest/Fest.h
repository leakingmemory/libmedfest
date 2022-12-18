//
// Created by sigsegv on 12/8/22.
//

#ifndef LEGEMFEST_FEST_H
#define LEGEMFEST_FEST_H

#include "../Struct/Decoded/OppfLegemiddelMerkevare.h"
#include "../Struct/Decoded/OppfLegemiddelpakning.h"
#include "XMLObject.h"
#include "KatLegemiddelpakning.h"
#include "../Struct/Decoded/OppfVirkestoff.h"
#include "KatVirkestoff.h"
#include "../Struct/Decoded/OppfVirkestoffMedStyrke.h"
#include <memory>
#include <map>
#include <vector>

class Fest;

class HentetDato : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
    std::string date;
public:
    HentetDato(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class XmlOppfLegemiddelMerkevare;

class Fest : public XMLObject {
private:
    std::string hentetDato{};
    std::vector<OppfLegemiddelMerkevare> oppfLegemiddelMerkevare{};
    std::vector<OppfLegemiddelpakning> oppfLegemiddelpakning{};
    std::vector<OppfVirkestoff> oppfVirkestoff{};
    std::vector<OppfVirkestoffMedStyrke> oppfVirkestoffMedStyrke{};
public:
    std::string GetName() const override;
    void SetHentetDato(const std::string &hentetDato) {
        this->hentetDato = hentetDato;
    }
    std::string GetHentetDato() {
        return hentetDato;
    }
    void Add(const XmlOppfLegemiddelMerkevare &);
    void Add(const XmlOppfLegemiddelpakning &);
    [[nodiscard]] bool Add(const XmlOppfVirkestoff &);
};

class FestHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class HentetDatoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_FEST_H
