//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPRISVARE_H
#define LEGEMFEST_XMLPRISVARE_H

#include "XMLObject.h"
#include "XmlGyldigFraDato.h"
#include "XmlGyldigTilDato.h"
#include "XmlValueWithCodeSet.h"
#include "XmlValueUnit.h"
#include "../Struct/Decoded/PrisVare.h"
#include <vector>

class XmlPrisVare {
private:
    std::vector<PrisVare> prisVare{};
public:
    virtual ~XmlPrisVare() = default;
    void AddPrisVare(const PrisVare &prisVare);
    [[nodiscard]] std::vector<PrisVare> GetPrisVare() const;
};

class XmlPrisVareObject : public XMLObject, public XmlGyldigFraDato, public XmlGyldigTilDato {
    std::shared_ptr<XmlPrisVare> parent;
    ValueWithCodeSet type{};
    Pris pris{};
public:
    XmlPrisVareObject(std::shared_ptr<XmlPrisVare> parent) : parent(parent) {}
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

class XmlTypeHandler : public XmlValueWithCodeSetHandler<XmlPrisVareObject> {
public:
    XmlTypeHandler() : XmlValueWithCodeSetHandler<XmlPrisVareObject>("Type") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPrisVareObject>> obj) override;
};

class XmlPrisHandler : public XmlValueUnitHandler<XmlPrisVareObject> {
public:
    XmlPrisHandler() : XmlValueUnitHandler<XmlPrisVareObject>("Pris") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLPRISVARE_H
