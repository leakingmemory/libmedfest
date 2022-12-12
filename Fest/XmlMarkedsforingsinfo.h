//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLMARKEDSFORINGSINFO_H
#define LEGEMFEST_XMLMARKEDSFORINGSINFO_H

#include "XmlLegemiddelpakning.h"
#include <memory>

class XmlMarkedsforingsinfo : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddelpakning> parent;
    std::string markedsforingsdato{};
public:
    XmlMarkedsforingsinfo(std::shared_ptr<XmlLegemiddelpakning> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetMarkedsforingsdato(const std::string &markedsforingsdato);
    bool Merge();
};

class XmlMarkedsforingsinfoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlMarkedsforingsdatoHandler : public XmlContentElementHandler<XmlMarkedsforingsinfo> {
public:
    XmlMarkedsforingsdatoHandler() : XmlContentElementHandler<XmlMarkedsforingsinfo>("Markedsforingsdato") {}
    bool Merge(std::shared_ptr<XmlMarkedsforingsinfo> parent, const std::string &content) override;
};


#endif //LEGEMFEST_XMLMARKEDSFORINGSINFO_H
