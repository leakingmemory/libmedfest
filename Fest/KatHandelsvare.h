//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_KATHANDELSVARE_H
#define LEGEMFEST_KATHANDELSVARE_H

#include "XMLObject.h"
#include "Fest.h"
#include "../Struct/Decoded/Handelsvare.h"

class XmlOppfHandelsvare;

class KatHandelsvare : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatHandelsvare(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    [[nodiscard]] bool Merge(const XmlOppfHandelsvare &oppf);
};

class KatHandelsvareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfHandelsvare : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatHandelsvare> kat;
    MedForbrMatr medForbrMatr{};
    Naringsmiddel naringsmiddel{};
public:
    XmlOppfHandelsvare(std::shared_ptr<KatHandelsvare> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetMedForbrMatr(const MedForbrMatr &medForbrMatr);
    [[nodiscard]] MedForbrMatr GetMedForbrMatr() const;
    void SetNaringsmiddel(const Naringsmiddel &naringsmiddel);
    [[nodiscard]] Naringsmiddel GetNaringsmiddel() const;
    [[nodiscard]] bool Merge();
};

class OppfHandelsvareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATHANDELSVARE_H
