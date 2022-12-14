//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELPAKNING_H
#define LEGEMFEST_XMLLEGEMIDDELPAKNING_H

#include "XMLObject.h"
#include "KatLegemiddelpakning.h"
#include "XmlLegemiddelCore.h"
#include "XmlPreparattypeObject.h"
#include "XmlContentElement.h"
#include "XmlPakningsinfo.h"
#include "XmlRefusjon.h"
#include "XmlPreparatomtaleavsnitt.h"

class XmlLegemiddelpakning : public XMLObject,
                                public FestIdObject,
                                public XmlLegemiddelCore,
                                public XmlPreparattypeObject,
                                public XmlPakningsinfo,
                                public XmlRefusjon,
                                public XmlPreparatomtaleavsnitt {
private:
    std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning;
    std::string varenr{};
    Oppbevaring oppbevaring{};
    Markedsforingsinfo markedsforingsinfo{};
    std::string ean{};
    std::vector<PrisVare> prisVare{};
    PakningByttegruppe pakningByttegruppe{};
public:
    XmlLegemiddelpakning(std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning) : oppfLegemiddelpakning(oppfLegemiddelpakning) {}
    std::string GetName() const override;
    void SetVarenr(const std::string &varenr);
    void SetOppbevaring(const Oppbevaring &oppbevaring);
    void SetMarkedsforingsinfo(const Markedsforingsinfo &markedsforingsinfo);
    void SetEan(const std::string &ean);
    void AddPrisVare(const PrisVare &prisVare);
    void SetPakningByttegruppe(const PakningByttegruppe &pakningByttegruppe);
    void Merge();
};

class XmlLegemiddelpakningHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlVarenrHandler : public XmlContentElementHandler<XmlLegemiddelpakning> {
public:
    XmlVarenrHandler() : XmlContentElementHandler<XmlLegemiddelpakning>("Varenr") {}
    bool Merge(std::shared_ptr<XmlLegemiddelpakning> parent, const std::string &content) override;
};

class XmlOppbevaringHandler : public XmlValueWithDistinguishedNameHandler<XmlLegemiddelpakning> {
public:
    XmlOppbevaringHandler() : XmlValueWithDistinguishedNameHandler<XmlLegemiddelpakning>("Oppbevaring") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlEanHandler : public XmlContentElementHandler<XmlLegemiddelpakning> {
public:
    XmlEanHandler() : XmlContentElementHandler<XmlLegemiddelpakning>("Ean") {}
    bool Merge(std::shared_ptr<XmlLegemiddelpakning> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELPAKNING_H
