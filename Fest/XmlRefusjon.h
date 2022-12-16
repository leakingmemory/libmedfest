//
// Created by sigsegv on 12/13/22.
//

#ifndef LEGEMFEST_XMLREFUSJON_H
#define LEGEMFEST_XMLREFUSJON_H

#include "../Struct/Decoded/Refusjon.h"
#include "XMLObject.h"
#include "XmlContentElement.h"
#include "XmlGyldigFraDato.h"
#include <memory>
#include <map>

class XmlRefusjon {
private:
    Refusjon refusjon{};
public:
    virtual ~XmlRefusjon() = default;
    void SetRefusjon(const Refusjon &refusjon);
    [[nodiscard]] Refusjon GetRefusjon() const;
};

class XmlRefusjonObject : public XMLObject, public XmlGyldigFraDato {
private:
    std::shared_ptr<XmlRefusjon> parent;
    std::string ref;
    std::string forskrivesTilDato;
    std::string utleveresTilDato;
public:
    XmlRefusjonObject(std::shared_ptr<XmlRefusjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetRefRefusjonsgruppe(const std::string &ref);
    void SetForskrivesTilDato(const std::string &forskrivesTilDato);
    void SetUtleveresTilDato(const std::string &utleveresTilDato);
    bool Merge();
};

class XmlRefusjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlRefRefusjonsgruppeHandler : public XmlContentElementHandler<XmlRefusjonObject> {
public:
    XmlRefRefusjonsgruppeHandler() : XmlContentElementHandler<XmlRefusjonObject>("RefRefusjonsgruppe") {}
    bool Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) override;
};

class XmlForskrivesTilDatoHandler : public XmlContentElementHandler<XmlRefusjonObject> {
public:
    XmlForskrivesTilDatoHandler() : XmlContentElementHandler<XmlRefusjonObject>("ForskrivesTilDato") {}
    bool Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) override;
};

class XmlUtleveresTilDatoHandler : public XmlContentElementHandler<XmlRefusjonObject> {
public:
    XmlUtleveresTilDatoHandler() : XmlContentElementHandler<XmlRefusjonObject>("UtleveresTilDato") {}
    bool Merge(std::shared_ptr<XmlRefusjonObject> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFUSJON_H
