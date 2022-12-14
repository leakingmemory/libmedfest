//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPRISVARE_H
#define LEGEMFEST_XMLPRISVARE_H

#include "XMLObject.h"
#include "XmlLegemiddelpakning.h"
#include "XmlGyldigFraDato.h"

class XmlPrisVare : public XMLObject, public XmlGyldigFraDato {
    std::shared_ptr<XmlLegemiddelpakning> parent;
    ValueWithCodeSet type{};
    Pris pris{};
public:
    XmlPrisVare(std::shared_ptr<XmlLegemiddelpakning> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetType(const ValueWithCodeSet &type);
    void SetPris(const Pris &pris);
    bool Merge();
};

class XmlPrisVareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlTypeHandler : public XmlValueWithCodeSetHandler<XmlPrisVare> {
public:
    XmlTypeHandler() : XmlValueWithCodeSetHandler<XmlPrisVare>("Type") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPrisVare>> obj) override;
};

class XmlPrisHandler : public XmlValueUnitHandler<XmlPrisVare> {
public:
    XmlPrisHandler() : XmlValueUnitHandler<XmlPrisVare>("Pris") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLPRISVARE_H
