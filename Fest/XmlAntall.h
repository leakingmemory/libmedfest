//
// Created by sigsegv on 12/15/22.
//

#ifndef LEGEMFEST_XMLANTALL_H
#define LEGEMFEST_XMLANTALL_H

#include "XmlContentElement.h"

class XmlAntall {
private:
    int antall{0};
public:
    virtual ~XmlAntall() = default;
    void SetAntall(int antall);
    [[nodiscard]] int GetAntall() const;
};

class XmlAntallHandler : public XmlContentElementHandler<XmlAntall> {
public:
    XmlAntallHandler() : XmlContentElementHandler<XmlAntall>("Antall") {}
    bool Merge(std::shared_ptr<XmlAntall> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLANTALL_H
