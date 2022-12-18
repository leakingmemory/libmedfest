//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_KATLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_KATLEGEMIDDELVIRKESTOFF_H

#include "XMLObject.h"
#include "Fest.h"
#include "../Struct/Decoded/LegemiddelVirkestoff.h"

class XmlOppfLegemiddelVirkestoff;

class KatLegemiddelVirkestoff : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatLegemiddelVirkestoff(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() const override;
    void Merge(const XmlOppfLegemiddelVirkestoff &oppf);
};

class KatLegemiddelVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfLegemiddelVirkestoff : public XMLObject, public FestIdObject, public TidspunktObject, public StatusObject {
private:
    std::shared_ptr<KatLegemiddelVirkestoff> kat;
    LegemiddelVirkestoff legemiddelVirkestoff{};
public:
    XmlOppfLegemiddelVirkestoff(std::shared_ptr<KatLegemiddelVirkestoff> kat) : kat(kat) {}
    std::string GetName() const override;
    void SetLegemiddelVirkestoff(const LegemiddelVirkestoff &legemiddelVirkestoff);
    [[nodiscard]] LegemiddelVirkestoff GetLegemiddelVirkestoff() const;
    void Merge();
};

class OppfLegemiddelVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATLEGEMIDDELVIRKESTOFF_H
