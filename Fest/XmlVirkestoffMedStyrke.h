//
// Created by sigsegv on 12/17/22.
//

#ifndef LEGEMFEST_XMLVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_XMLVIRKESTOFFMEDSTYRKE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "../Struct/Decoded/Styrke.h"
#include "../Struct/Decoded/Styrkenevner.h"
#include "../Struct/Decoded/Styrkeoperator.h"
#include "XmlRefVirkestoff.h"
#include "XmlValueUnit.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/Atc.h"
#include <memory>
#include <map>

class XmlOppfVirkestoff;

class XmlVirkestoffMedStyrke : public XMLObject, public FestIdObject, public XmlRefVirkestoff {
private:
    std::shared_ptr<XmlOppfVirkestoff> oppfVirkestoff;
    Styrke styrke{};
    Styrkenevner styrkenevner{};
    Styrkeoperator styrkeoperator{};
    Styrke alternativStyrke{};
    Styrkenevner alternativStyrkenevner{};
    Atc atcKombipreparat{};
    double styrkeOvreVerdi{0.0};
public:
    XmlVirkestoffMedStyrke(std::shared_ptr<XmlOppfVirkestoff> oppfVirkestoff) : oppfVirkestoff(oppfVirkestoff) {}
    std::string GetName() const override;
    void SetStyrke(const Styrke &styrke);
    void SetStyrkenevner(const Styrkenevner &styrkenevner);
    void SetStyrkeoperator(const Styrkeoperator &styrkeoperator);
    void SetAlternativStyrke(const Styrke &alternativStyrke);
    void SetAlternativStyrkenevner(const Styrkenevner &alternativStyrke);
    void SetAtcKombipreparat(const Atc &atc);
    void SetStyrkeOvreVerdi(double styrkeOvreVerdi);
    [[nodiscard]] bool Merge();
};

class XmlVirkestoffMedStyrkeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlStyrkeHandler : public XmlValueUnitHandler<XmlVirkestoffMedStyrke> {
public:
    XmlStyrkeHandler() : XmlValueUnitHandler<XmlVirkestoffMedStyrke>("Styrke") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlStyrkeoperatorHandler : public XmlValueWithCodeSetHandler<XmlVirkestoffMedStyrke> {
public:
    XmlStyrkeoperatorHandler() : XmlValueWithCodeSetHandler<XmlVirkestoffMedStyrke>("Styrkeoperator") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVirkestoffMedStyrke>> obj) override;
};

class XmlStyrkeNevnerHandler : public XmlValueUnitHandler<XmlVirkestoffMedStyrke> {
public:
    XmlStyrkeNevnerHandler() : XmlValueUnitHandler<XmlVirkestoffMedStyrke>("StyrkeNevner") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlAlternativStyrkeHandler : public XmlValueUnitHandler<XmlVirkestoffMedStyrke> {
public:
    XmlAlternativStyrkeHandler() : XmlValueUnitHandler<XmlVirkestoffMedStyrke>("AlternativStyrke") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlAlternativStyrkeNevnerHandler : public XmlValueUnitHandler<XmlVirkestoffMedStyrke> {
public:
    XmlAlternativStyrkeNevnerHandler() : XmlValueUnitHandler<XmlVirkestoffMedStyrke>("AlternativStyrkeNevner") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlAtcKombipreparatHandler : public XmlValueWithCodeSetHandler<XmlVirkestoffMedStyrke> {
public:
    XmlAtcKombipreparatHandler() : XmlValueWithCodeSetHandler<XmlVirkestoffMedStyrke>("AtcKombipreparat") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVirkestoffMedStyrke>> obj) override;
};

class XmlStyrkeOvreVerdiHandler : public XmlContentElementHandler<XmlVirkestoffMedStyrke> {
public:
    XmlStyrkeOvreVerdiHandler() : XmlContentElementHandler<XmlVirkestoffMedStyrke>("StyrkeOvreVerdi") {}
    bool Merge(std::shared_ptr<XmlVirkestoffMedStyrke> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLVIRKESTOFFMEDSTYRKE_H
