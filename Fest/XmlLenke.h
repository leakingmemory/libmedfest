//
// Created by sigsegv on 12/27/22.
//

#ifndef LEGEMFEST_XMLLENKE_H
#define LEGEMFEST_XMLLENKE_H

#include "XMLObject.h"
#include "XmlValue.h"
#include "XmlContentElement.h"
#include "XmlValue.h"
#include "../Struct/Decoded/Lenke.h"
#include <memory>

class XmlLenke {
private:
    Lenke lenke{};
public:
    virtual ~XmlLenke() = default;
    void SetLenke(const Lenke &lenke);
    [[nodiscard]] Lenke GetLenke() const;
};

class XmlLenkeValue {
private:
    std::string lenke{};
public:
    virtual ~XmlLenkeValue() = default;
    void SetLenke(const std::string &lenke);
    [[nodiscard]] std::string GetLenke() const;
};

class XmlLenkeObject : public XMLObject {
private:
    std::shared_ptr<XmlLenke> parent;
    std::string beskrivelse{};
    std::string www{};
public:
    XmlLenkeObject(std::shared_ptr<XmlLenke> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetBeskrivelse(const std::string &beskrivelse);
    void SetWww(const std::string &www);
    bool Merge();
};

class XmlLenkeHandler : private XmlValueHandler<XmlLenkeValue> {
public:
    XmlLenkeHandler() : XmlValueHandler<XmlLenkeValue>("Lenke") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) override;
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlBeskrivelseHandler : public XmlContentElementHandler<XmlLenkeObject> {
public:
    XmlBeskrivelseHandler() : XmlContentElementHandler<XmlLenkeObject>("Beskrivelse") {}
    bool Merge(std::shared_ptr<XmlLenkeObject> parent, const std::string &content) override;
};

class XmlWwwHandler : public XmlValueHandler<XmlLenkeObject> {
public:
    XmlWwwHandler() : XmlValueHandler<XmlLenkeObject>("Www") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLLENKE_H
