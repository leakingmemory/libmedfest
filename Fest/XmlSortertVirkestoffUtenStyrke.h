//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLSORTERTVIRKESTOFFUTENSTYRKE_H
#define LEGEMFEST_XMLSORTERTVIRKESTOFFUTENSTYRKE_H

#include <Fest/XMLObject.h>
#include "XmlSortering.h"
#include "XmlRefVirkestoff.h"
#include <memory>
#include <map>


class XmlSortertVirkestoffUtenStyrke;

class XmlSortertVirkestoffUtenStyrkeObject : public XMLObject, public XmlSortering, public XmlRefVirkestoff {
private:
    std::shared_ptr<XmlSortertVirkestoffUtenStyrke> parent;
public:
    explicit XmlSortertVirkestoffUtenStyrkeObject(std::shared_ptr<XmlSortertVirkestoffUtenStyrke> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Merge();
};

class XmlSortertVirkestoffUtenStyrke {
private:
    std::vector<std::unique_ptr<XmlSortertVirkestoffUtenStyrkeObject>> refs;
public:
    virtual ~XmlSortertVirkestoffUtenStyrke() = default;
    void Add(XmlSortertVirkestoffUtenStyrkeObject &ref);
    [[nodiscard]] std::vector<std::string> GetSortertVirkestoffUtenStyrke();
};

class XmlSortertVirkestoffUtenStyrkeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLSORTERTVIRKESTOFFUTENSTYRKE_H
