//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLPREPARATTYPEOBJECT_H
#define LEGEMFEST_XMLPREPARATTYPEOBJECT_H


#include "../Struct/Decoded/Preparattype.h"
#include "XmlValueWithDistinguishedName.h"

class XmlPreparattypeObject {
private:
    Preparattype preparattype{};
public:
    virtual ~XmlPreparattypeObject() = default;
    void SetPreparattype(const Preparattype &preparattype);
    Preparattype GetPreparattype() const;
};

class XmlPreparattypeObjectHandler : public XmlValueWithDistinguishedNameHandler<XmlPreparattypeObject> {
public:
    XmlPreparattypeObjectHandler() : XmlValueWithDistinguishedNameHandler<XmlPreparattypeObject>("Preparattype") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};


#endif //LEGEMFEST_XMLPREPARATTYPEOBJECT_H
