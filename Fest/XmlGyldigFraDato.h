//
// Created by sigsegv on 12/14/22.
//

#ifndef LEGEMFEST_XMLGYLDIGFRADATO_H
#define LEGEMFEST_XMLGYLDIGFRADATO_H

#include "XmlContentElement.h"
#include <string>
#include <memory>

class XmlGyldigFraDato {
private:
    std::string gyldigFraDato{};
public:
    virtual ~XmlGyldigFraDato() = default;
    void SetGyldigFraDato(const std::string &gyldigFraDato);
    [[nodiscard]] std::string GetGyldigFraDato() const;
};

class XmlGyldigFraDatoHandler : public XmlContentElementHandler<XmlGyldigFraDato> {
public:
    XmlGyldigFraDatoHandler() : XmlContentElementHandler<XmlGyldigFraDato>("GyldigFraDato") {}
    bool Merge(std::shared_ptr<XmlGyldigFraDato> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLGYLDIGFRADATO_H
