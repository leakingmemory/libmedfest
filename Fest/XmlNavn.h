//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_XMLNAVN_H
#define LEGEMFEST_XMLNAVN_H

#include "XmlContentElement.h"
#include <string>

class XmlNavn {
private:
    std::string navn{};
public:
    virtual ~XmlNavn() = default;
    void SetNavn(const std::string &name);
    [[nodiscard]] std::string GetNavn() const;
};

class XmlNavnHandler : public XmlContentElementHandler<XmlNavn> {
public:
    XmlNavnHandler() : XmlContentElementHandler<XmlNavn>("Navn") {}
    bool Merge(std::shared_ptr<XmlNavn> parent, const std::string &content) override;
};


#endif //LEGEMFEST_XMLNAVN_H
