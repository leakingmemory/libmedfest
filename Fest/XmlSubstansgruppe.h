//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLSUBSTANSGRUPPE_H
#define LEGEMFEST_XMLSUBSTANSGRUPPE_H

#include "XMLObject.h"
#include "XmlNavn.h"
#include "../Struct/Decoded/Substans.h"
#include <memory>
#include <map>
#include <vector>

class XmlInteraksjon;

class XmlSubstansgruppe : public XMLObject, public XmlNavn {
private:
    std::shared_ptr<XmlInteraksjon> parent;
    std::vector<Substans> substans{};
public:
    XmlSubstansgruppe(std::shared_ptr<XmlInteraksjon> parent) : parent(parent) {}
    std::string GetName() const override;
    void AddSubstans(const Substans &substans);
    bool Merge();
};

class XmlSubstansgruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLSUBSTANSGRUPPE_H
