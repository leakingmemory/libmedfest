//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_XMLREFPAKNING_H
#define LEGEMFEST_XMLREFPAKNING_H

#include "XmlContentElement.h"
#include <vector>

class XmlRefPakning {
private:
    std::vector<std::string> refs;
public:
    virtual ~XmlRefPakning() = default;
    void AddRefPakning(const std::string &ref);
    [[nodiscard]] std::vector<std::string> GetRefPakning() const;
};

class XmlRefPakningHandler : public XmlContentElementHandler<XmlRefPakning> {
public:
    XmlRefPakningHandler() : XmlContentElementHandler<XmlRefPakning>("RefPakning") {}
    bool Merge(std::shared_ptr<XmlRefPakning> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFPAKNING_H
