//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLATC_H
#define LEGEMFEST_XMLATC_H

#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/Atc.h"

class XmlAtc {
private:
    Atc atc{};
public:
    virtual ~XmlAtc() = default;
    void SetAtc(const Atc &atc);
    [[nodiscard]] Atc GetAtc() const;
};

class XmlAtcHandler : public XmlValueWithCodeSetHandler<XmlAtc> {
public:
    XmlAtcHandler() : XmlValueWithCodeSetHandler<XmlAtc>("Atc") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlAtc>> obj) override;
};

#endif //LEGEMFEST_XMLATC_H
