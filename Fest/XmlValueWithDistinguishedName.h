//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLVALUEWITHDISTINGUISHEDNAME_H
#define LEGEMFEST_XMLVALUEWITHDISTINGUISHEDNAME_H

#include "../Struct/Decoded/ValueWithDistinguishedName.h"
#include "XMLObject.h"
#include <memory>
#include <map>
#include <iostream>

template <typename ParentType> class XmlValueWithDistinguishedName : public XMLObject {
private:
    std::shared_ptr<ParentType> parent;
    std::string name;
    ValueWithDistinguishedName valueWithDistinguishedName;
public:
    XmlValueWithDistinguishedName(const std::shared_ptr<ParentType> &parent, const std::string &name, const ValueWithDistinguishedName &valueWithDistinguishedName)
            : parent(parent), name(name), valueWithDistinguishedName(valueWithDistinguishedName) {}
    [[nodiscard]] std::shared_ptr<ParentType> GetParent() {
        return parent;
    }
    std::string GetName() override {
        return name;
    }
    [[nodiscard]] ValueWithDistinguishedName GetValueWithDistinguishedName() const {
        return valueWithDistinguishedName;
    }
};

template <typename ParentType> class XmlValueWithDistinguishedNameHandler {
public:
    typedef XmlValueWithDistinguishedName<ParentType> XmlType;
private:
    std::string name;
public:
    XmlValueWithDistinguishedNameHandler(const std::string &name) : name(name) {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
        std::shared_ptr<ParentType> typedParent = std::dynamic_pointer_cast<ParentType>(parent);
        if (!typedParent) {
            std::cerr << "Error: " << name << " was not expected here.\n";
            return {};
        }
        auto i_v = attributes.find("V");
        auto i_dn = attributes.find("DN");
        if (i_v == attributes.end() || i_dn == attributes.end()) {
            std::cerr << "Error: " << name << " expects at least V and DN\n";
            return {};
        }
        return std::make_shared<XmlType>(typedParent, name, ValueWithDistinguishedName(i_v->second, i_dn->second));
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
};

#endif //LEGEMFEST_XMLVALUEWITHDISTINGUISHEDNAME_H
