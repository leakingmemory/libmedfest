//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELFORBRUK_H
#define LEGEMFEST_XMLLEGEMIDDELFORBRUK_H

#include <Fest/XMLObject.h>
#include "XmlContentElement.h"
#include "XmlMengde.h"
#include <Struct/Decoded/Dosering.h>
#include <memory>
#include <map>

class XmlKortdoseObjectObject;

class XmlLegemiddelforbruk : public XMLObject, public XmlMengde {
private:
    std::shared_ptr<XmlKortdoseObjectObject> parent;
    int lopenr{0};
    int iterasjoner{0};
    double mengde{0.0};
    std::string periode{};
    std::vector<Dosering> dosering{};
public:
    XmlLegemiddelforbruk(const std::shared_ptr<XmlKortdoseObjectObject> &parent) : parent(parent) {}
    std::string GetName() const override;
    void SetLopenr(int lopenr);
    void SetIterasjoner(int iterasjoner);
    bool Mengde(const std::string &) override;
    void SetPeriode(const std::string &periode);
    [[nodiscard]] bool AddDosering(const Dosering &dosering);
    bool Merge();
};

class XmlLegemiddelforbrukHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlLopenrHandler : public XmlContentElementHandler<XmlLegemiddelforbruk> {
public:
    XmlLopenrHandler() : XmlContentElementHandler<XmlLegemiddelforbruk>("Lopenr") {}
    bool Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) override;
};

class XmlPeriodeHandler : public XmlContentElementHandler<XmlLegemiddelforbruk> {
public:
    XmlPeriodeHandler() : XmlContentElementHandler<XmlLegemiddelforbruk>("Periode") {}
    bool Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) override;
};

class XmlIterasjonerHandler : public XmlContentElementHandler<XmlLegemiddelforbruk> {
public:
    XmlIterasjonerHandler() : XmlContentElementHandler<XmlLegemiddelforbruk>("Iterasjoner") {}
    bool Merge(std::shared_ptr<XmlLegemiddelforbruk> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELFORBRUK_H
