//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H
#define LEGEMFEST_XMLPREPARATOMTALEAVSNITT_H

#include "XMLObject.h"
#include "XmlLegemiddelMerkevare.h"
#include "XmlValue.h"

class XmlPreparatomtaleavsnitt : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddelMerkevare> parent;
    ValueWithDistinguishedName avsnittoverskrift{};
    std::string link{};
public:
    XmlPreparatomtaleavsnitt(std::shared_ptr<XmlLegemiddelMerkevare> parent) : parent(parent) {}
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

class XmlAvsnittoverskriftHandler : public XmlValueWithDistinguishedNameHandler<XmlPreparatomtaleavsnitt> {
public:
    XmlAvsnittoverskriftHandler() : XmlValueWithDistinguishedNameHandler<XmlPreparatomtaleavsnitt>("Avsnittoverskrift") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlLenke : public XMLObject {
private:
    std::shared_ptr<XmlPreparatomtaleavsnitt> parent;
    std::string link{};
public:
    XmlLenke(std::shared_ptr<XmlPreparatomtaleavsnitt> parent) : parent(parent) {}
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
