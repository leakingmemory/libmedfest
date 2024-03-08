//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_KATSTRDOSERING_H
#define LEGEMFEST_KATSTRDOSERING_H

#include <Fest/XMLObject.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include "XmlKortdose.h"
#include <memory>
#include <map>

class Fest;
class XmlOppfStrDosering;

class KatStrDosering : public XMLObject, public XmlKortdoseObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatStrDosering(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(XmlOppfStrDosering &);
};

class XmlOppfStrDosering : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject,
                           public XmlKortdoseObject {
private:
    std::shared_ptr<KatStrDosering> kat;
public:
    XmlOppfStrDosering(std::shared_ptr<KatStrDosering> kat) : kat(kat) {}
    std::string GetName() const override;
    bool Merge();
};

class KatStrDoseringHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfStrDoseringHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATSTRDOSERING_H
