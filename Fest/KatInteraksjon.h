//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_KATINTERAKSJON_H
#define LEGEMFEST_KATINTERAKSJON_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include "../Struct/Decoded/Interaksjon.h"
#include <memory>
#include <map>

class Fest;
class XmlOppfInteraksjon;

class KatInteraksjon : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatInteraksjon(const std::shared_ptr<Fest> &fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfInteraksjon &);
};

class XmlOppfInteraksjon : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatInteraksjon> kat;
    Interaksjon interaksjon{};
public:
    XmlOppfInteraksjon(const std::shared_ptr<KatInteraksjon> &kat) : kat(kat) {}
    std::string GetName() const override;
    [[nodiscard]] bool SetInteraksjon(const Interaksjon &interaksjon);
    [[nodiscard]] Interaksjon GetInteraksjon() const;
    void Merge();
};

class KatInteraksjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfInteraksjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATINTERAKSJON_H
