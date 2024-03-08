//
// Created by sigsegv on 12/13/22.
//

#ifndef LEGEMFEST_XMLPAKNINGSTYPE_H
#define LEGEMFEST_XMLPAKNINGSTYPE_H

#include "XmlValueWithCodeSet.h"
#include <Struct/Decoded/Pakningstype.h>
#include <memory>

class XmlPakningstype {
private:
    Pakningstype pakningstype{};
public:
    virtual ~XmlPakningstype() = default;
    void SetPakningstype(const Pakningstype &pakningstype);
    [[nodiscard]] Pakningstype GetPakningstype() const;
};

class XmlPakningstypeHandler : public XmlValueWithCodeSetHandler<XmlPakningstype> {
public:
    XmlPakningstypeHandler() : XmlValueWithCodeSetHandler<XmlPakningstype>("Pakningstype") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningstype>> obj) override;
};


#endif //LEGEMFEST_XMLPAKNINGSTYPE_H
