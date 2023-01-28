//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLREFUSJONSKODE_H
#define LEGEMFEST_XMLREFUSJONSKODE_H

#include "XMLObject.h"
#include "XmlRefusjonsgruppe.h"
#include "XmlGyldigFraDato.h"
#include "XmlContentElement.h"
#include "XmlRefusjonsvilkar.h"
#include "XmlForskrivesTilDato.h"

class XmlRefusjonskode : public XMLObject, public XmlGyldigFraDato, public XmlRefRefusjonsvilkar,
                         public XmlForskrivesTilDato {
private:
    std::shared_ptr<XmlRefusjonsgruppe> parent;
    ValueWithCodeSet refusjonskode{};
    std::vector<std::string> underterm{};
public:
    XmlRefusjonskode(std::shared_ptr<XmlRefusjonsgruppe> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetRefusjonskode(const ValueWithCodeSet &refusjonskode);
    void AddUnderterm(const std::string &underterm);
    bool Merge();
};

class XmlRefusjonskodeHandler : private XmlValueWithCodeSetHandler<XmlRefusjonskode> {
public:
    XmlRefusjonskodeHandler() : XmlValueWithCodeSetHandler<XmlRefusjonskode>("Refusjonskode") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) override;
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonskode>> obj) override;
};

class XmlUndertermHandler : public XmlContentElementHandler<XmlRefusjonskode> {
public:
    XmlUndertermHandler() : XmlContentElementHandler<XmlRefusjonskode>("Underterm") {}
    bool Merge(std::shared_ptr<XmlRefusjonskode> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFUSJONSKODE_H
