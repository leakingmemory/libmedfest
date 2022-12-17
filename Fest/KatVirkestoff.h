//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_KATVIRKESTOFF_H
#define LEGEMFEST_KATVIRKESTOFF_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include "../Struct/Decoded/Virkestoff.h"
#include <memory>
#include <map>

class Fest;
class XmlOppfVirkestoff;

class KatVirkestoff : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatVirkestoff(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(XmlOppfVirkestoff &);
};

class KatVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfVirkestoff : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatVirkestoff> kat;
    Virkestoff virkestoff{};
public:
    XmlOppfVirkestoff(std::shared_ptr<KatVirkestoff> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetVirkestoff(const Virkestoff &virkestoff);
    [[nodiscard]] Virkestoff GetVirkestoff() const;
    void Merge();
};

class XmlOppfVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_KATVIRKESTOFF_H
