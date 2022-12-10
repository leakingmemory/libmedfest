//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLSORTERTVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_XMLSORTERTVIRKESTOFFMEDSTYRKE_H

#include "XMLObject.h"
#include "XmlSortering.h"
#include "XmlRefVirkestoffMedStyrke.h"
#include <memory>
#include <map>

class XmlSortertVirkestoffMedStyrke;

class XmlSortertVirkestoffMedStyrkeObject : public XMLObject, public XmlSortering, public XmlRefVirkestoffMedStyrke {
private:
    std::shared_ptr<XmlSortertVirkestoffMedStyrke> parent;
public:
    explicit XmlSortertVirkestoffMedStyrkeObject(std::shared_ptr<XmlSortertVirkestoffMedStyrke> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Merge();
};

class XmlSortertVirkestoffMedStyrke {
private:
    std::vector<std::unique_ptr<XmlSortertVirkestoffMedStyrkeObject>> refs;
public:
    virtual ~XmlSortertVirkestoffMedStyrke() = default;
    void Add(XmlSortertVirkestoffMedStyrkeObject &ref);
    [[nodiscard]] std::vector<std::string> GetSortertVirkestoffMedStyrke();
};

class XmlSortertVirkestoffMedStyrkeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_XMLSORTERTVIRKESTOFFMEDSTYRKE_H
