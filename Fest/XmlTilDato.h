//
// Created by sigsegv on 8/20/24.
//

#ifndef LIBMEDFEST_XMLTILDATO_H
#define LIBMEDFEST_XMLTILDATO_H

#include "XmlContentElement.h"

class XmlTilDato {
private:
    std::string tilDato;
public:
    virtual ~XmlTilDato() = default;
    void SetTilDato(const std::string &tilDato);
    [[nodiscard]] std::string GetTilDato() const;
};

class XmlTilDatoHandler : public XmlContentElementHandler<XmlTilDato> {
public:
    XmlTilDatoHandler() : XmlContentElementHandler<XmlTilDato>("TilDato") {}
    bool Merge(std::shared_ptr<XmlTilDato> parent, const std::string &content) override;
};

#endif //LIBMEDFEST_XMLTILDATO_H
