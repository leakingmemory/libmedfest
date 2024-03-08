//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLVALUEWITHCODESET_H
#define LEGEMFEST_XMLVALUEWITHCODESET_H


#include "XmlValueWithDistinguishedName.h"
#include <Struct/Decoded/ValueWithCodeSet.h>

template <typename ParentType> class XmlValueWithCodeSet : public XmlValueWithDistinguishedName<ParentType> {
private:
    std::string codeSet;
public:
    XmlValueWithCodeSet(const std::shared_ptr<ParentType> &parent, const std::string &name, const ValueWithCodeSet &valueWithCodeSet) : XmlValueWithDistinguishedName<ParentType>(parent, name, valueWithCodeSet), codeSet(valueWithCodeSet.GetCodeSet()) {}
    [[nodiscard]] ValueWithCodeSet GetValueWithCodeSet() const {
        return {XmlValueWithDistinguishedName<ParentType>::GetValueWithDistinguishedName(), codeSet};
    }
};

template <typename ParentType> class XmlValueWithCodeSetHandler : public XmlValueWithDistinguishedNameHandler<ParentType> {
public:
    XmlValueWithCodeSetHandler(const std::string &name) : XmlValueWithDistinguishedNameHandler<ParentType>(name) {}

    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent,
                                            const std::map<std::string, std::string> &attributes) override {
        auto dnValue = XmlValueWithDistinguishedNameHandler<ParentType>::StartElement(parent, attributes);
        if (!dnValue) {
            return {};
        }
        std::shared_ptr<typename XmlValueWithDistinguishedNameHandler<ParentType>::XmlType> typedDnValue = std::dynamic_pointer_cast<typename XmlValueWithDistinguishedNameHandler<ParentType>::XmlType>(dnValue);
        if (!typedDnValue) {
            std::cerr << "Error: Expected return value XmlValueWithDistinguishedNameHandler<ParentType>::XmlType\n";
            return {};
        }
        auto i_s = attributes.find("S");
        if (i_s == attributes.end()) {
            std::cerr << "Error: " << XmlValueWithDistinguishedNameHandler<ParentType>::GetName() << " requires at least V, S, DN\n";
            return {};
        }
        return std::make_shared<XmlValueWithCodeSet<ParentType>>(typedDnValue->GetParent(), XmlValueWithDistinguishedNameHandler<ParentType>::GetName(), ValueWithCodeSet(typedDnValue->GetValueWithDistinguishedName(), i_s->second));
    }
    virtual bool Merge(std::shared_ptr<XmlValueWithCodeSet<ParentType>> obj) = 0;
    bool Merge(std::shared_ptr<typename XmlValueWithDistinguishedNameHandler<ParentType>::XmlType> obj) override final {
        std::shared_ptr<XmlValueWithCodeSet<ParentType>> typedObj = std::dynamic_pointer_cast<XmlValueWithCodeSet<ParentType>>(obj);
        return Merge(typedObj);
    }
};


#endif //LEGEMFEST_XMLVALUEWITHCODESET_H
