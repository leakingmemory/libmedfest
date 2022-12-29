//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_KATBYTTEGRUPPE_H
#define LEGEMFEST_KATBYTTEGRUPPE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include "../Struct/Decoded/Byttegruppe.h"
#include <memory>
#include <map>

class Fest;
class XmlOppfByttegruppe;

class KatByttegruppe : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatByttegruppe(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(XmlOppfByttegruppe &oppf);
};

class XmlOppfByttegruppe : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatByttegruppe> kat;
    Byttegruppe byttegruppe{};
public:
    XmlOppfByttegruppe(std::shared_ptr<KatByttegruppe> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetByttegruppe(const Byttegruppe &byttegruppe);
    [[nodiscard]] Byttegruppe GetByttegruppe() const;
    void Merge();
};

class KatByttegruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfByttegruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_KATBYTTEGRUPPE_H
