//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLFORSKRIVESTILDATO_H
#define LEGEMFEST_XMLFORSKRIVESTILDATO_H

#include "XmlContentElement.h"
#include <string>
#include <memory>

class XmlForskrivesTilDato {
private:
    std::string forskrivesTilDato;
public:
    virtual ~XmlForskrivesTilDato() = default;
    void SetForskrivesTilDato(const std::string &forskrivesTilDato);
    [[nodiscard]] std::string GetForskrivesTilDato() const;
};

class XmlForskrivesTilDatoHandler : public XmlContentElementHandler<XmlForskrivesTilDato> {
public:
    XmlForskrivesTilDatoHandler() : XmlContentElementHandler<XmlForskrivesTilDato>("ForskrivesTilDato") {}
    bool Merge(std::shared_ptr<XmlForskrivesTilDato> parent, const std::string &content) override;
};



#endif //LEGEMFEST_XMLFORSKRIVESTILDATO_H
