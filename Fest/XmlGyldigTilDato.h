//
// Created by sigsegv on 12/14/22.
//

#ifndef LEGEMFEST_XMLGYLDIGTILDATO_H
#define LEGEMFEST_XMLGYLDIGTILDATO_H

#include "XmlContentElement.h"
#include <string>
#include <memory>

class XmlGyldigTilDato {
private:
    std::string gyldigTilDato{};
public:
    virtual ~XmlGyldigTilDato() = default;
    void SetGyldigTilDato(const std::string &gyldigTilDato);
    [[nodiscard]] std::string GetGyldigTilDato() const;
};

class XmlGyldigTilDatoHandler : public XmlContentElementHandler<XmlGyldigTilDato> {
public:
    XmlGyldigTilDatoHandler() : XmlContentElementHandler<XmlGyldigTilDato>("GyldigTilDato") {}
    bool Merge(std::shared_ptr<XmlGyldigTilDato> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLGYLDIGTILDATO_H
