//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_KATLEGEMIDDELDOSE_H
#define LEGEMFEST_KATLEGEMIDDELDOSE_H

#include <Fest/XMLObject.h>
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <Struct/Decoded/Legemiddeldose.h>
#include <memory>
#include <map>

class Fest;
class XmlOppfLegemiddeldose;

class KatLegemiddeldose : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatLegemiddeldose(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfLegemiddeldose &);
};

class XmlOppfLegemiddeldose : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatLegemiddeldose> kat;
    Legemiddeldose legemiddeldose{};
public:
    XmlOppfLegemiddeldose(std::shared_ptr<KatLegemiddeldose> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetLegemiddeldose(const Legemiddeldose &legemiddeldose);
    [[nodiscard]] Legemiddeldose GetLegemiddeldose() const;
    void Merge();
};

class KatLegemiddeldoseHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfLegemiddeldoseHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATLEGEMIDDELDOSE_H
