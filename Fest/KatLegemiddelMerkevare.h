//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_KATLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_KATLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include "StatusObject.h"
#include <memory>

class Fest;
class XmlOppfLegemiddelMerkevare;

class KatLegemiddelMerkevare : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatLegemiddelMerkevare(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() override;
    void Merge(const XmlOppfLegemiddelMerkevare &oppf);
};

class KatLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlOppfLegemiddelMerkevare : public XMLObject,
                                   public FestIdObject,
                                   public TidspunktObject,
                                   public StatusObject {
private:
    std::shared_ptr<KatLegemiddelMerkevare> kat;
public:
    XmlOppfLegemiddelMerkevare(std::shared_ptr<KatLegemiddelMerkevare> kat) : kat(kat) {}
    std::string GetName();
    void Merge();
};

class OppfLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATLEGEMIDDELMERKEVARE_H
