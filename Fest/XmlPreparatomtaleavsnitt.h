//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H
#define LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H

#include "XMLObject.h"
#include "XmlValue.h"
#include "XmlValueWithDistinguishedName.h"
#include "XmlLenke.h"
#include "../Struct/Decoded/Preparatomtaleavsnitt.h"

class XmlPreparatomtaleavsnitt {
private:
    Preparatomtaleavsnitt preparatomtaleavsnitt{};
public:
    void SetPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt);
    [[nodiscard]] Preparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
};

class XmlPreparatomtaleavsnittObject : public XMLObject, public XmlLenke {
private:
    std::shared_ptr<XmlPreparatomtaleavsnitt> parent;
    ValueWithDistinguishedName avsnittoverskrift{};
public:
    XmlPreparatomtaleavsnittObject(std::shared_ptr<XmlPreparatomtaleavsnitt> parent) : parent(parent) {}
    std::string GetName() const;
    void SetAvsnittoverskrift(const ValueWithDistinguishedName &avsnittoverskrift);
    bool Merge();
};

class XmlPreparatomtaleavsnittHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlAvsnittoverskriftHandler : public XmlValueWithDistinguishedNameHandler<XmlPreparatomtaleavsnittObject> {
public:
    XmlAvsnittoverskriftHandler() : XmlValueWithDistinguishedNameHandler<XmlPreparatomtaleavsnittObject>("Avsnittoverskrift") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H
