//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_KATVILKAR_H
#define LEGEMFEST_KATVILKAR_H

#include <Fest/Fest.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <Struct/Decoded/Vilkar.h>

class XmlOppfVilkar;

class KatVilkar : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatVilkar(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfVilkar &oppf);
};

class XmlOppfVilkar : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatVilkar> kat;
    Vilkar vilkar{};
public:
    XmlOppfVilkar(std::shared_ptr<KatVilkar> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetVilkar(const Vilkar &vilkar);
    [[nodiscard]] Vilkar GetVilkar() const;
    void Merge();
};

class KatVilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class OppfVilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATVILKAR_H
