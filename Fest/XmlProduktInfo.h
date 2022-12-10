//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLPRODUKTINFO_H
#define LEGEMFEST_XMLPRODUKTINFO_H

#include "XMLObject.h"
#include "XmlLegemiddelMerkevare.h"
#include <memory>
#include <map>

class XmlProduktInfo : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddelMerkevare> parent;
    std::string produsent{};
    MaybeBoolean varseltrekant{MaybeBoolean::UNSPECIFIED};
    std::string referanseprodukt;
public:
    XmlProduktInfo(std::shared_ptr<XmlLegemiddelMerkevare> parent) : parent(parent) {}
    virtual ~XmlProduktInfo() = default;
    std::string GetName() const override;
    void SetProdusent(const std::string &produsent);
    void SetVarseltrekant(MaybeBoolean varseltrekant);
    void SetReferanseprodukt(const std::string &referanseprodukt);
    bool Merge();
};

class XmlProduktInfoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlProdusentHandler : public XmlContentElementHandler<XmlProduktInfo> {
public:
    XmlProdusentHandler() : XmlContentElementHandler<XmlProduktInfo>("Produsent") {}
    bool Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) override;
};

class XmlVarseltrekantHandler : public XmlContentElementHandler<XmlProduktInfo> {
public:
    XmlVarseltrekantHandler() : XmlContentElementHandler<XmlProduktInfo>("Varseltrekant") {}
    bool Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) override;
};

class XmlReferanseproduktHandler : public XmlContentElementHandler<XmlProduktInfo> {
public:
    XmlReferanseproduktHandler() : XmlContentElementHandler<XmlProduktInfo>("Referanseprodukt") {}
    bool Merge(std::shared_ptr<XmlProduktInfo> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLPRODUKTINFO_H
