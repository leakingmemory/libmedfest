//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPRISVARE_H
#define LEGEMFEST_XMLPRISVARE_H

#include <Fest/XMLObject.h>
#include "XmlGyldigFraDato.h"
#include "XmlGyldigTilDato.h"
#include "XmlValueWithCodeSet.h"
#include "XmlValueUnit.h"
#include "XmlType.h"
#include <Struct/Decoded/PrisVare.h>
#include <vector>

class XmlPrisVare {
private:
    std::vector<PrisVare> prisVare{};
public:
    virtual ~XmlPrisVare() = default;
    void AddPrisVare(const PrisVare &prisVare);
    [[nodiscard]] std::vector<PrisVare> GetPrisVare() const;
};

class XmlPrisVareObject : public XMLObject, public XmlGyldigFraDato, public XmlGyldigTilDato, public XmlTypeObject {
    std::shared_ptr<XmlPrisVare> parent;
    Pris pris{};
public:
    XmlPrisVareObject(std::shared_ptr<XmlPrisVare> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetPris(const Pris &pris);
    bool Merge();
};

class XmlPrisVareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlPrisHandler : public XmlValueUnitHandler<XmlPrisVareObject> {
public:
    XmlPrisHandler() : XmlValueUnitHandler<XmlPrisVareObject>("Pris") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLPRISVARE_H
