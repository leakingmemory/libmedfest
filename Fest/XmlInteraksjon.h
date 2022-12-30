//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_XMLINTERAKSJON_H
#define LEGEMFEST_XMLINTERAKSJON_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlContentElement.h"
#include "XmlVisningsregel.h"
#include "../Struct/Decoded/Relevans.h"
#include "../Struct/Decoded/Kildegrunnlag.h"
#include "../Struct/Decoded/Referanse.h"
#include "../Struct/Decoded/Substansgruppe.h"
#include <memory>
#include <map>

class XmlOppfInteraksjon;

class XmlInteraksjon : public XMLObject, public FestIdObject, public XmlVisningsregel {
private:
    std::shared_ptr<XmlOppfInteraksjon> parent;
    Relevans relevans{};
    std::string kliniskKonsekvens{};
    std::string interaksjonsmekanisme{};
    Kildegrunnlag kildegrunnlag{};
    std::string handtering{};
    std::vector<Referanse> referanse{};
    std::vector<Substansgruppe> substansgruppe{};
    std::string situasjonskriterium{};
public:
    XmlInteraksjon(std::shared_ptr<XmlOppfInteraksjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetRelevans(const Relevans &relevans);
    void SetKliniskKonsekvens(const std::string &kliniskKonsekvens);
    void SetInteraksjonsmekanisme(const std::string &interaksjonsmekanisme);
    void SetKildegrunnlag(const Kildegrunnlag &kildegrunnlag);
    void SetHandtering(const std::string &handtering);
    void AddReferanse(const Referanse &referanse);
    void AddSubstansgruppe(const Substansgruppe &substansgruppe);
    void SetSituasjonskriterium(const std::string &situasjonskriterium);
    bool Merge();
};

class XmlInteraksjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlRelevansHandler : public XmlValueWithDistinguishedNameHandler<XmlInteraksjon> {
public:
    XmlRelevansHandler() : XmlValueWithDistinguishedNameHandler<XmlInteraksjon>("Relevans") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlKliniskKonsekvensHandler : public XmlContentElementHandler<XmlInteraksjon> {
public:
    XmlKliniskKonsekvensHandler() : XmlContentElementHandler<XmlInteraksjon>("KliniskKonsekvens") {}
    bool Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) override;
};

class XmlInteraksjonsmekanismeHandler : public XmlContentElementHandler<XmlInteraksjon> {
public:
    XmlInteraksjonsmekanismeHandler() : XmlContentElementHandler<XmlInteraksjon>("Interaksjonsmekanisme") {}
    bool Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) override;
};

class XmlKildegrunnlagHandler : public XmlValueWithDistinguishedNameHandler<XmlInteraksjon> {
public:
    XmlKildegrunnlagHandler() : XmlValueWithDistinguishedNameHandler<XmlInteraksjon>("Kildegrunnlag") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlHandteringHandler : public XmlContentElementHandler<XmlInteraksjon> {
public:
    XmlHandteringHandler() : XmlContentElementHandler<XmlInteraksjon>("Handtering") {}
    bool Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) override;
};

class XmlSituasjonskriteriumHandler : public XmlContentElementHandler<XmlInteraksjon> {
public:
    XmlSituasjonskriteriumHandler() : XmlContentElementHandler<XmlInteraksjon>("Situasjonskriterium") {}
    bool Merge(std::shared_ptr<XmlInteraksjon> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLINTERAKSJON_H
