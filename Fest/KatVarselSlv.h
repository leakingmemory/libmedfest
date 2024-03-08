//
// Created by sigsegv on 12/26/22.
//

#ifndef LEGEMFEST_KATVARSELSLV_H
#define LEGEMFEST_KATVARSELSLV_H

#include <Fest/XMLObject.h>
#include <Fest/Fest.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <Struct/Decoded/VarselSlv.h>
#include <map>

class XmlOppfVarselSlv;

class KatVarselSlv : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatVarselSlv(const std::shared_ptr<Fest> &fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(XmlOppfVarselSlv &oppf);
};

class XmlOppfVarselSlv : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatVarselSlv> kat;
    VarselSlv varselSlv;
public:
    XmlOppfVarselSlv(const std::shared_ptr<KatVarselSlv> &kat) : kat(kat) {}
    std::string GetName() const override;
    void SetVarselSlv(const VarselSlv &varselSlv);
    [[nodiscard]] VarselSlv GetVarselSlv() const;
    void Merge();
};

class KatVarselSlvHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfVarselSlvHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_KATVARSELSLV_H
