//
// Created by sigsegv on 12/8/22.
//

#ifndef LEGEMFEST_FEST_H
#define LEGEMFEST_FEST_H

#include "../Struct/Decoded/OppfLegemiddelMerkevare.h"
#include "../Struct/Decoded/OppfLegemiddelpakning.h"
#include "XMLObject.h"
#include "../Struct/Decoded/OppfVirkestoff.h"
#include "../Struct/Decoded/OppfVirkestoffMedStyrke.h"
#include "../Struct/Decoded/OppfLegemiddelVirkestoff.h"
#include "../Struct/Decoded/OppfHandelsvare.h"
#include "../Struct/Decoded/OppfRefusjon.h"
#include "../Struct/Decoded/OppfVilkar.h"
#include "../Struct/Decoded/OppfVarselSlv.h"
#include "../Struct/Decoded/OppfKodeverk.h"
#include "../Struct/Decoded/OppfByttegruppe.h"
#include "../Struct/Decoded/OppfLegemiddeldose.h"
#include "../Struct/Decoded/OppfInteraksjon.h"
#include "../Struct/Decoded/OppfInteraksjonIkkeVurdert.h"
#include "../Struct/Decoded/OppfStrDosering.h"
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
class XmlOppfInteraksjon;
class XmlOppfStrDosering;

class FestVisitor {
public:
    virtual void Progress(int done, int total) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfLegemiddelMerkevare &merkevare) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfLegemiddelpakning &pakning) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfLegemiddelVirkestoff &virkestoff) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfMedForbrMatr &medForbrMatr) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfNaringsmiddel &naringsmiddel) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfBrystprotese &brystprotese) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfLegemiddeldose &legemiddeldose) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfVirkestoffMedStyrke &virkestoffMedStyrke) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfVirkestoff &virkestoff) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfKodeverk &kodeverk) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfRefusjon &refusjon) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfVilkar &vilkar) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfVarselSlv &varselSlv) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfByttegruppe &byttegruppe) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfInteraksjon &interaksjon) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfInteraksjonIkkeVurdert &interaksjonIkkeVurdert) = 0;
    [[nodiscard]] virtual bool Visit(const std::string &fest, const OppfStrDosering &strDosering) = 0;
};

class XmlOppfLegemiddelpakning;
class XmlOppfVirkestoff;

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
    std::vector<OppfInteraksjon> oppfInteraksjon{};
    std::vector<OppfInteraksjonIkkeVurdert> oppfInteraksjonIkkeVurdert{};
    std::vector<OppfStrDosering> oppfStrDosering{};
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
    [[nodiscard]] bool Add(const XmlOppfInteraksjon &);
    void Add(const XmlOppfStrDosering &);

    [[nodiscard]] bool Accept(FestVisitor &visitor) const;
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
