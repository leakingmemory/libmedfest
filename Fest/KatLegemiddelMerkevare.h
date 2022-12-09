//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_KATLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_KATLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "TidspunktObject.h"
#include <memory>

class Fest;
class OppfLegemiddelMerkevare;

class KatLegemiddelMerkevare : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
public:
    KatLegemiddelMerkevare(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() override;
    void Merge(const OppfLegemiddelMerkevare &oppf);
};

class KatLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class OppfLegemiddelMerkevare : public XMLObject,
        public FestIdObject,
        public TidspunktObject {
private:
    std::shared_ptr<KatLegemiddelMerkevare> kat;
public:
    OppfLegemiddelMerkevare(std::shared_ptr<KatLegemiddelMerkevare> kat) : kat(kat) {}
    std::string GetName();
    void Merge();
};

class OppfLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_KATLEGEMIDDELMERKEVARE_H
