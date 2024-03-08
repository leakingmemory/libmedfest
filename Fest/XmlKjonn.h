//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLKJONN_H
#define LEGEMFEST_XMLKJONN_H

#include <Struct/Decoded/ValueWithDistinguishedName.h>
#include "XmlValueWithDistinguishedName.h"

class XmlKjonn {
private:
    ValueWithDistinguishedName kjonn{};
public:
    virtual ~XmlKjonn() = default;
    void SetKjonn(const ValueWithDistinguishedName &kjonn);
    [[nodiscard]] ValueWithDistinguishedName GetKjonn() const;
};

class XmlKjonnHandler : public XmlValueWithDistinguishedNameHandler<XmlKjonn> {
public:
    XmlKjonnHandler() : XmlValueWithDistinguishedNameHandler<XmlKjonn>("Kjonn") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLKJONN_H
