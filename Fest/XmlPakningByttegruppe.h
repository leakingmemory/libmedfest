//
// Created by sigsegv on 12/14/22.
//

#ifndef LEGEMFEST_XMLPAKNINGBYTTEGRUPPE_H
#define LEGEMFEST_XMLPAKNINGBYTTEGRUPPE_H

#include "XmlLegemiddelpakning.h"
#include "XmlContentElement.h"

class XmlPakningByttegruppe : public XMLObject, public XmlGyldigFraDato {
private:
    std::shared_ptr<XmlLegemiddelpakning> parent;
    std::string refByttegruppe;
public:
    XmlPakningByttegruppe(std::shared_ptr<XmlLegemiddelpakning> parent) : parent(parent) {}
    std::string GetName() const override;
    [[nodiscard]] bool SetRefByttegruppe(const std::string &refByttegruppe);
    bool Merge();
};

class XmlPakningByttegruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlRefByttegruppeHandler : public XmlContentElementHandler<XmlPakningByttegruppe> {
public:
    XmlRefByttegruppeHandler() : XmlContentElementHandler<XmlPakningByttegruppe>("RefByttegruppe") {}
    bool Merge(std::shared_ptr<XmlPakningByttegruppe> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLPAKNINGBYTTEGRUPPE_H
