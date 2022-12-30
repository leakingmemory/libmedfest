//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLSUBSTANS_H
#define LEGEMFEST_XMLSUBSTANS_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include "XmlAtc.h"
#include "XmlRefVirkestoff.h"
#include <memory>
#include <map>

class XmlSubstansgruppe;

class XmlSubstans : public XMLObject, public XmlAtc, public XmlRefVirkestoff {
private:
    std::shared_ptr<XmlSubstansgruppe> parent;
    std::string substans{};
public:
    XmlSubstans(const std::shared_ptr<XmlSubstansgruppe> &parent) : parent(parent) {}
    std::string GetName() const override;
    void SetSubstans(const std::string &substans);
    bool Merge();
};

class XmlSubstansHandler : private XmlContentElementHandler<XmlSubstans> {
public:
    XmlSubstansHandler() : XmlContentElementHandler<XmlSubstans>("Substans") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlSubstans> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLSUBSTANS_H
