//
// Created by sigsegv on 12/23/22.
//

#ifndef LEGEMFEST_KATREFUSJON_H
#define LEGEMFEST_KATREFUSJON_H

#include "XMLObject.h"
#include "Fest.h"
#include "FestIdObject.h"
#include "StatusObject.h"
#include "TidspunktObject.h"
#include <memory>

class XmlOppfRefusjon;

class KatRefusjon : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatRefusjon(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfRefusjon &);
};

class KatRefusjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfRefusjon : public XMLObject, public FestIdObject, public StatusObject, public TidspunktObject {
private:
    std::shared_ptr<KatRefusjon> parent;
    Refusjonshjemmel refusjonshjemmel;
public:
    XmlOppfRefusjon(std::shared_ptr<KatRefusjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetRefusjonshjemmel(const Refusjonshjemmel &refusjonshjemmel);
    [[nodiscard]] Refusjonshjemmel GetRefusjonshjemmel() const;
    void Merge();
};

class OppfRefusjonHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATREFUSJON_H
