//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_KATKODEVERK_H
#define LEGEMFEST_KATKODEVERK_H

#include <Fest/XMLObject.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <Struct/Decoded/Info.h>
#include <Struct/Decoded/Element.h>
#include <memory>
#include <map>
#include <vector>

class Fest;
class XmlOppfKodeverk;

class KatKodeverk : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatKodeverk(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(XmlOppfKodeverk &);
};

class XmlOppfKodeverk : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatKodeverk> kat;
    Info info{};
    std::vector<Element> element{};
public:
    XmlOppfKodeverk(std::shared_ptr<KatKodeverk> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetInfo(const Info &info);
    [[nodiscard]] Info GetInfo() const;
    void AddElement(const Element &element);
    [[nodiscard]] std::vector<Element> GetElement() const;
    void Merge();
};

class KatKodeverkHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class OppfKodeverkHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATKODEVERK_H
