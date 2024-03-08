//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_KATLEGEMIDDELPAKNING_H
#define LEGEMFEST_KATLEGEMIDDELPAKNING_H

#include <Fest/XMLObject.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <Struct/Decoded/Legemiddelpakning.h>
#include <memory>
#include <map>

class Fest;
class XmlOppfLegemiddelpakning;

class KatLegemiddelpakning : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatLegemiddelpakning(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfLegemiddelpakning &oppf);
};

class KatLegemiddelpakningHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfLegemiddelpakning : public XMLObject,
                                   public FestIdObject,
                                   public TidspunktObject,
                                   public StatusObject {
private:
    std::shared_ptr<KatLegemiddelpakning> kat;
    Legemiddelpakning legemiddelpakning;
public:
    XmlOppfLegemiddelpakning(std::shared_ptr<KatLegemiddelpakning> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetLegemiddelpakning(const Legemiddelpakning &legemiddelpakning);
    [[nodiscard]] Legemiddelpakning GetLegemiddelpakning() const;
    void Merge();
};

class OppfLegemiddelpakningHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATLEGEMIDDELPAKNING_H
