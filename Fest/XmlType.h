//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_XMLTYPE_H
#define LEGEMFEST_XMLTYPE_H

#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/ValueWithCodeSet.h"

class XmlTypeObject {
private:
    ValueWithCodeSet type{};
public:
    virtual ~XmlTypeObject() = default;
    void SetType(const ValueWithCodeSet &type);
    [[nodiscard]] ValueWithCodeSet GetType() const;
};

class XmlTypeHandler : public XmlValueWithCodeSetHandler<XmlTypeObject> {
public:
    XmlTypeHandler() : XmlValueWithCodeSetHandler<XmlTypeObject>("Type") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlTypeObject>> obj) override;
};

#endif //LEGEMFEST_XMLTYPE_H
