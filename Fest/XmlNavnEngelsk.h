//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_XMLNAVNENGELSK_H
#define LEGEMFEST_XMLNAVNENGELSK_H

#include "XmlContentElement.h"
#include <string>
#include <memory>

class XmlNavnEngelsk {
private:
    std::string navnEngelsk{};
public:
    virtual ~XmlNavnEngelsk() = default;
    void SetNavnEngelsk(const std::string &name);
    [[nodiscard]] std::string GetNavnEngelsk() const;
};

class XmlNavnEngelskHandler : public XmlContentElementHandler<XmlNavnEngelsk> {
public:
    XmlNavnEngelskHandler() : XmlContentElementHandler<XmlNavnEngelsk>("NavnEngelsk") {}
    bool Merge(std::shared_ptr<XmlNavnEngelsk> parent, const std::string &content) override;
};


#endif //LEGEMFEST_XMLNAVNENGELSK_H
