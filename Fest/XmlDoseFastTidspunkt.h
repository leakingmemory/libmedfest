//
// Created by sigsegv on 12/31/22.
//

#ifndef LEGEMFEST_XMLDOSEFASTTIDSPUNKT_H
#define LEGEMFEST_XMLDOSEFASTTIDSPUNKT_H

#include "XMLObject.h"
#include "XmlMengde.h"
#include "XmlValueUnit.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlContentElement.h"
#include "../Struct/Decoded/ValueUnit.h"
#include "../Struct/Decoded/ValueWithDistinguishedName.h"
#include "../Struct/Decoded/MaybeBoolean.h"
#include "../Struct/Decoded/FastDose.h"
#include <memory>
#include <map>

class XmlDosering;

class XmlDoseFastTidspunkt : public XMLObject, public XmlMengde {
private:
    std::shared_ptr<XmlDosering> parent;
    ValueUnit mengde{};
    ValueUnit intervall{};
    ValueWithDistinguishedName tidsomrade{};
    MaybeBoolean gisEksakt{MaybeBoolean::UNSPECIFIED};
    FastDose fastDose{};
public:
    XmlDoseFastTidspunkt(std::shared_ptr<XmlDosering> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Mengde(const ValueUnit &) override;
    void SetIntervall(const ValueUnit &intervall);
    void SetTidsomrade(const ValueWithDistinguishedName &tidsomrade);
    void SetGisEksakt(bool gisEksakt);
    bool SetFastDose(const FastDose &fastDose);
    bool Merge();
};

class XmlDoseFastTidspunktHandler  {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlIntervallHandler : public XmlValueUnitHandler<XmlDoseFastTidspunkt> {
public:
    XmlIntervallHandler() : XmlValueUnitHandler<XmlDoseFastTidspunkt>("Intervall") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlTidsomradeHandler : public XmlValueWithDistinguishedNameHandler<XmlDoseFastTidspunkt> {
public:
    XmlTidsomradeHandler() : XmlValueWithDistinguishedNameHandler<XmlDoseFastTidspunkt>("Tidsomrade") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlGisEksaktHandler : public XmlContentElementHandler<XmlDoseFastTidspunkt> {
public:
    XmlGisEksaktHandler() : XmlContentElementHandler<XmlDoseFastTidspunkt>("GisEksakt") {}
    bool Merge(std::shared_ptr<XmlDoseFastTidspunkt> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLDOSEFASTTIDSPUNKT_H
