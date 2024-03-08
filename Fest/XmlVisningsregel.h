//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLVISNINGSREGEL_H
#define LEGEMFEST_XMLVISNINGSREGEL_H

#include "XmlValueWithCodeSet.h"
#include <Struct/Decoded/Visningsregel.h>
#include <vector>

class XmlVisningsregel {
private:
    std::vector<Visningsregel> visningsregel{};
public:
    virtual ~XmlVisningsregel() = default;
    void AddVisningsregel(const Visningsregel &visningsregel);
    [[nodiscard]] std::vector<Visningsregel> GetVisningsregel() const;
};

class XmlVisningsregelHandler : public XmlValueWithCodeSetHandler<XmlVisningsregel> {
public:
    XmlVisningsregelHandler() : XmlValueWithCodeSetHandler<XmlVisningsregel>("Visningsregel") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVisningsregel>> obj) override;
};

#endif //LEGEMFEST_XMLVISNINGSREGEL_H
