//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "KatLegemiddelMerkevare.h"
#include "XmlLegemiddel.h"
#include "XmlPreparattypeObject.h"
#include "XmlSortertVirkestoffUtenStyrke.h"

class XmlLegemiddelMerkevare :
        public XMLObject,
        public FestIdObject,
        public XmlLegemiddel,
        public XmlPreparattypeObject,
        public XmlSortertVirkestoffUtenStyrke {
private:
    std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare;
    std::string varenavn{};
    std::string legemiddelformLang{};
    std::string produsent{};
    std::vector<Reseptgyldighet> reseptgyldighet{};
    MaybeBoolean varseltrekant{MaybeBoolean::UNSPECIFIED};
    std::string referanseprodukt{};
    Preparatomtaleavsnitt preparatomtaleavsnitt{};
    Smak smak{};
    Vaksinestandard vaksinestandard{};
public:
    XmlLegemiddelMerkevare(std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare) : oppfLegemiddelMerkevare(oppfLegemiddelMerkevare) {}
    std::string GetName() const override;
    void SetVarenavn(const std::string &varenavn);
    void SetLegemiddelformLang(const std::string &legemiddelformLang);
    void SetProdusent(const std::string &produsent);
    void AddReseptgyldighet(const Reseptgyldighet &reseptgyldighet);
    void SetVarseltrekant(MaybeBoolean varseltrekant);
    void SetReferanseprodukt(const std::string &referanseprodukt);
    void SetPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt);
    void SetSmak(const Smak &smak);
    void SetVaksinestandard(const Vaksinestandard &vaksinestandard);
    void Merge();
};

class XmlLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlVarenavnHandler : public XmlContentElementHandler<XmlLegemiddelMerkevare> {
public:
    XmlVarenavnHandler() : XmlContentElementHandler<XmlLegemiddelMerkevare>("Varenavn") {}
    bool Merge(std::shared_ptr<XmlLegemiddelMerkevare> parent, const std::string &content) override;
};

class XmlLegemiddelformLangHandler : public XmlContentElementHandler<XmlLegemiddelMerkevare> {
public:
    XmlLegemiddelformLangHandler() : XmlContentElementHandler<XmlLegemiddelMerkevare>("LegemiddelformLang") {}
    bool Merge(std::shared_ptr<XmlLegemiddelMerkevare> parent, const std::string &content) override;
};

class XmlSmakHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddelMerkevare> {
public:
    XmlSmakHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddelMerkevare>("Smak") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};


#endif //LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
