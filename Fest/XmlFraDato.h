//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_XMLFRADATO_H
#define LEGEMFEST_XMLFRADATO_H

#include "XmlContentElement.h"

class XmlFraDato {
private:
    std::string fraDato;
public:
    virtual ~XmlFraDato() = default;
    void SetFraDato(const std::string &fraDato);
    [[nodiscard]] std::string GetFraDato() const;
};

class XmlFraDatoHandler : public XmlContentElementHandler<XmlFraDato> {
public:
    XmlFraDatoHandler() : XmlContentElementHandler<XmlFraDato>("FraDato") {}
    bool Merge(std::shared_ptr<XmlFraDato> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLFRADATO_H
