//
// Created by sigsegv on 12/24/22.
//

#ifndef LEGEMFEST_XMLREFUSJONSHJEMMEL_H
#define LEGEMFEST_XMLREFUSJONSHJEMMEL_H

#include <Fest/XMLObject.h>
#include "KatRefusjon.h"
#include "XmlValueWithCodeSet.h"
#include "XmlContentElement.h"
#include <Struct/Decoded/Refusjonsgruppe.h>
#include <memory>
#include <map>

class XmlRefusjonshjemmel : public XMLObject {
private:
    std::shared_ptr<XmlOppfRefusjon> parent;
    ValueWithCodeSet refusjonshjemmel{};
    MaybeBoolean kreverVarekobling{MaybeBoolean::UNSPECIFIED};
    MaybeBoolean kreverVedtak{MaybeBoolean::UNSPECIFIED};
    Refusjonsgruppe refusjongruppe{};
public:
    XmlRefusjonshjemmel(std::shared_ptr<XmlOppfRefusjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetRefusjonshjemmel(const ValueWithCodeSet &refusjonshjemmel);
    void SetKreverVarekobling(bool kreverVarekobling);
    void SetKreverVedtak(bool kreverVedtak);
    void SetRefusjonsgruppe(const Refusjonsgruppe &refusjonsgruppe);
    bool Merge();
};

class XmlRefusjonshjemmelHandler : private XmlValueWithCodeSetHandler<XmlRefusjonshjemmel> {
public:
    XmlRefusjonshjemmelHandler() : XmlValueWithCodeSetHandler<XmlRefusjonshjemmel>("Refusjonshjemmel") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) override;
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlRefusjonshjemmel>> obj) override;
};

class XmlKreverVarekoblingHandler : public XmlContentElementHandler<XmlRefusjonshjemmel> {
public:
    XmlKreverVarekoblingHandler() : XmlContentElementHandler<XmlRefusjonshjemmel>("KreverVarekobling") {}
    bool Merge(std::shared_ptr<XmlRefusjonshjemmel> parent, const std::string &content) override;
};

class XmlKreverVedtakHandler : public XmlContentElementHandler<XmlRefusjonshjemmel> {
public:
    XmlKreverVedtakHandler() : XmlContentElementHandler<XmlRefusjonshjemmel>("KreverVedtak") {}
    bool Merge(std::shared_ptr<XmlRefusjonshjemmel> parent, const std::string &content) override;
};


#endif //LEGEMFEST_XMLREFUSJONSHJEMMEL_H
