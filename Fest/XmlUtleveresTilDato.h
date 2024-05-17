//
// Created by sigsegv on 5/14/24.
//

#ifndef LIBMEDFEST_XMLUTLEVERESTILDATO_H
#define LIBMEDFEST_XMLUTLEVERESTILDATO_H

#include "XmlContentElement.h"
#include <string>
#include <memory>

class XmlUtleveresTilDato {
private:
    std::string utleveresTilDato;
public:
    virtual ~XmlUtleveresTilDato() = default;
    void SetUtleveresTilDato(const std::string &utleveresTilDato);
    [[nodiscard]] std::string GetUtleveresTilDato() const;
};

class XmlUtleveresTilDatoHandler : public XmlContentElementHandler<XmlUtleveresTilDato> {
public:
    XmlUtleveresTilDatoHandler() : XmlContentElementHandler<XmlUtleveresTilDato>("UtleveresTilDato") {}
    bool Merge(std::shared_ptr<XmlUtleveresTilDato> parent, const std::string &content) override;
};


#endif //LIBMEDFEST_XMLUTLEVERESTILDATO_H
