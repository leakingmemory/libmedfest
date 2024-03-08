//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLKORTDOSE_H
#define LEGEMFEST_XMLKORTDOSE_H

#include "XmlValueWithCodeSet.h"
#include "XmlBeskrivelseTerm.h"
#include <Struct/Decoded/Kortdose.h>
#include <vector>

class XmlKortdose {
private:
    std::vector<ValueWithCodeSet> kortdose{};
public:
    virtual ~XmlKortdose() = default;
    void AddKortdose(const ValueWithCodeSet &kortdose);
    [[nodiscard]] std::vector<ValueWithCodeSet> GetKortdose() const;
};

class XmlKortdoseObject {
private:
    Kortdose kortdose{};
public:
    virtual ~XmlKortdoseObject() = default;
    [[nodiscard]] bool SetKortdose(const Kortdose &kortdose);
    [[nodiscard]] Kortdose GetKortdose() const;
};

class XmlKortdoseObjectObject : public XMLObject, public XmlKortdose, public XmlBeskrivelseTerm {
private:
    std::shared_ptr<XmlKortdoseObject> parent;
    std::vector<Legemiddelforbruk> legemiddelforbruk{};
public:
    XmlKortdoseObjectObject(std::shared_ptr<XmlKortdoseObject> parent) : parent(parent) {}
    std::string GetName() const override;
    bool AddLegemiddelforbruk(const Legemiddelforbruk &legemiddelforbruk);
    bool Merge();
};

class XmlKortdoseHandler : private XmlValueWithCodeSetHandler<XmlKortdose> {
public:
    XmlKortdoseHandler() : XmlValueWithCodeSetHandler<XmlKortdose>("Kortdose") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) override;
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlKortdose>> obj) override;
};

#endif //LEGEMFEST_XMLKORTDOSE_H
