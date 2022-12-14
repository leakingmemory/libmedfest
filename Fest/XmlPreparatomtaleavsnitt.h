//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H
#define LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H

#include "XMLObject.h"
#include "XmlValue.h"
#include "XmlValueWithDistinguishedName.h"
#include "../Struct/Decoded/Preparatomtaleavsnitt.h"

class XmlPreparatomtaleavsnitt {
private:
    Preparatomtaleavsnitt preparatomtaleavsnitt{};
public:
    void SetPreparatomtaleavsnitt(const Preparatomtaleavsnitt &preparatomtaleavsnitt);
    [[nodiscard]] Preparatomtaleavsnitt GetPreparatomtaleavsnitt() const;
};

class XmlPreparatomtaleavsnittObject : public XMLObject {
private:
    std::shared_ptr<XmlPreparatomtaleavsnitt> parent;
    ValueWithDistinguishedName avsnittoverskrift{};
    std::string link{};
public:
    XmlPreparatomtaleavsnittObject(std::shared_ptr<XmlPreparatomtaleavsnitt> parent) : parent(parent) {}
    std::string GetName() const;
    void SetAvsnittoverskrift(const ValueWithDistinguishedName &avsnittoverskrift);
    void SetLink(const std::string &link);
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

class XmlLenke : public XMLObject {
private:
    std::shared_ptr<XmlPreparatomtaleavsnittObject> parent;
    std::string link{};
public:
    XmlLenke(std::shared_ptr<XmlPreparatomtaleavsnittObject> parent) : parent(parent) {}
    std::string GetName() const;
    void SetLink(const std::string &link);
    bool Merge();
};

class XmlLenkeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlWwwHandler : public XmlValueHandler<XmlLenke> {
public:
    XmlWwwHandler() : XmlValueHandler<XmlLenke>("Www") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H
