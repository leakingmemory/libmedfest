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
#include "../Struct/Decoded/OppfLegemiddelVirkestoff.h"
#include "../Struct/Decoded/OppfHandelsvare.h"
#include "../Struct/Decoded/OppfRefusjon.h"
#include "../Struct/Decoded/OppfVilkar.h"
#include "../Struct/Decoded/OppfVarselSlv.h"
#include "../Struct/Decoded/OppfKodeverk.h"
#include "../Struct/Decoded/OppfByttegruppe.h"
#include "../Struct/Decoded/OppfLegemiddeldose.h"
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
class XmlOppfLegemiddelVirkestoff;
class XmlOppfHandelsvare;
class XmlOppfRefusjon;
class XmlOppfVilkar;
class XmlOppfVarselSlv;
class XmlOppfKodeverk;
class XmlOppfByttegruppe;
class XmlOppfLegemiddeldose;

class Fest : public XMLObject {
private:
    std::string hentetDato{};
    std::vector<OppfLegemiddelMerkevare> oppfLegemiddelMerkevare{};
    std::vector<OppfLegemiddelpakning> oppfLegemiddelpakning{};
    std::vector<OppfVirkestoff> oppfVirkestoff{};
    std::vector<OppfVirkestoffMedStyrke> oppfVirkestoffMedStyrke{};
    std::vector<OppfLegemiddelVirkestoff> oppfLegemiddelVirkestoff{};
    std::vector<OppfMedForbrMatr> oppfMedForbrVare{};
    std::vector<OppfNaringsmiddel> oppfNaringsmiddel{};
    std::vector<OppfBrystprotese> oppfBrystprotese{};
    std::vector<OppfRefusjon> oppfRefusjon{};
    std::vector<OppfVilkar> oppfVilkar{};
    std::vector<OppfVarselSlv> oppfVarselSlv{};
    std::vector<OppfKodeverk> oppfKodeverk{};
    std::vector<OppfByttegruppe> oppfByttegruppe{};
    std::vector<OppfLegemiddeldose> oppfLegemiddeldose{};
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
    void Add(const XmlOppfLegemiddelVirkestoff &);
    [[nodiscard]] bool Add(const XmlOppfHandelsvare &);
    void Add(const XmlOppfRefusjon &);
    void Add(const XmlOppfVilkar &);
    void Add(const XmlOppfVarselSlv &);
    void Add(const XmlOppfKodeverk &);
    void Add(const XmlOppfByttegruppe &);
    void Add(const XmlOppfLegemiddeldose &);
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
