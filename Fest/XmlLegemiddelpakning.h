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
#include "XmlPrisVare.h"

class XmlLegemiddelpakning : public XMLObject,
                                public FestIdObject,
                                public XmlLegemiddelCore,
                                public XmlPreparattypeObject,
                                public XmlPakningsinfo,
                                public XmlRefusjon,
                                public XmlPreparatomtaleavsnitt,
                                public XmlPrisVare {
private:
    std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning;
    std::string varenr{};
    Oppbevaring oppbevaring{};
    Markedsforingsinfo markedsforingsinfo{};
    std::string ean{};
    PakningByttegruppe pakningByttegruppe{};
    bool ikkeKonservering{false};
public:
    XmlLegemiddelpakning(std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning) : oppfLegemiddelpakning(oppfLegemiddelpakning) {}
    std::string GetName() const override;
    void SetVarenr(const std::string &varenr);
    void SetOppbevaring(const Oppbevaring &oppbevaring);
    void SetMarkedsforingsinfo(const Markedsforingsinfo &markedsforingsinfo);
    void SetEan(const std::string &ean);
    [[nodiscard]] bool SetPakningByttegruppe(const PakningByttegruppe &pakningByttegruppe);
    void SetIkkeKonservering(bool ikkeKonservering);
    [[nodiscard]] bool Merge();
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

class XmlIkkeKonserveringHandler : public XmlContentElementHandler<XmlLegemiddelpakning> {
public:
    XmlIkkeKonserveringHandler() : XmlContentElementHandler<XmlLegemiddelpakning>("IkkeKonservering") {}
    bool Merge(std::shared_ptr<XmlLegemiddelpakning> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELPAKNING_H
