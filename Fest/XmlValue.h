//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLVALUE_H
#define LEGEMFEST_XMLVALUE_H

#include <Struct/Decoded/ValueWithDistinguishedName.h>
#include <Fest/XMLObject.h>
#include <memory>
#include <map>
#include <iostream>

template <typename ParentType> class XmlValue : public XMLObject {
private:
    std::shared_ptr<ParentType> parent;
    std::string name;
    std::string value;
public:
    XmlValue(const std::shared_ptr<ParentType> &parent, const std::string &name, const std::string &value)
            : parent(parent), name(name), value(value) {}
    [[nodiscard]] std::shared_ptr<ParentType> GetParent() const {
        return parent;
    }
    std::string GetName() const override {
        return name;
    }
    [[nodiscard]] std::string GetValue() const {
        return value;
    }
};

template <typename ParentType> class XmlValueHandler {
public:
    typedef XmlValue<ParentType> XmlType;
private:
    std::string name;
public:
    XmlValueHandler(const std::string &name) : name(name) {}
    virtual std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
        std::shared_ptr<ParentType> typedParent = std::dynamic_pointer_cast<ParentType>(parent);
        if (!typedParent) {
            std::cerr << "Error: " << name << " was not expected here.\n";
            return {};
        }
        auto i_v = attributes.find("V");
        if (i_v == attributes.end()) {
            std::cerr << "Error: " << name << " expects at least V\n";
            return {};
        }
        return std::make_shared<XmlType>(typedParent, name, i_v->second);
    }
    virtual bool Merge(std::shared_ptr<XmlType> obj) = 0;
    bool EndElement(const std::shared_ptr<XMLObject> &obj) {
        std::shared_ptr<XmlType> xmlType = std::dynamic_pointer_cast<XmlType>(obj);
        if (!obj) {
            std::cerr << "Error: ends the wrong obj at " << name << "\n";
            return false;
        }
        return Merge(xmlType);
    }
    [[nodiscard]] std::string GetName() const {
        return name;
    }
};

#endif //LEGEMFEST_XMLVALUE_H
