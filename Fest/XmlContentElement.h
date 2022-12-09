//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLCONTENTELEMENT_H
#define LEGEMFEST_XMLCONTENTELEMENT_H

#include "XMLObject.h"
#include <memory>
#include <map>
#include <iostream>

template <typename ParentType> class XmlContentElement : public XMLObject {
private:
    std::shared_ptr<ParentType> parent;
    std::string name;
    std::string content{};
public:
    XmlContentElement(const std::shared_ptr<ParentType> &parent, const std::string &name) : parent(parent), name(name) {}
    bool AppendCharacterData(const std::string &charData) override {
        content.append(charData);
        return true;
    }
    std::string GetName() const override {
        return name;
    }
    [[nodiscard]] std::shared_ptr<ParentType> GetParent() const {
        return parent;
    }
    [[nodiscard]] std::string GetContent() const {
        return content;
    }
};

template <typename ParentType> class XmlContentElementHandler {
private:
    std::string name;
public:
    XmlContentElementHandler(const std::string &name) : name(name) {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
        std::shared_ptr<ParentType> typedParent = std::dynamic_pointer_cast<ParentType>(parent);
        if (!typedParent) {
            std::cerr << "Error: " << GetName() << " not accepted here\n";
            return {};
        }
        return std::make_shared<XmlContentElement<ParentType>>(typedParent, GetName());
    }
    bool EndElement(const std::shared_ptr<XMLObject> &obj) {
        std::shared_ptr<XmlContentElement<ParentType>> typedObject = std::dynamic_pointer_cast<XmlContentElement<ParentType>>(obj);
        if (!typedObject) {
            std::cerr << "Error: Ending, but not a " << GetName() << "\n";
            return false;
        }
        return Merge(typedObject->GetParent(), typedObject->GetContent());
    }
    [[discard]] std::string GetName() const {
        return name;
    }
    virtual bool Merge(std::shared_ptr<ParentType> parent, const std::string &content) = 0;
};


#endif //LEGEMFEST_XMLCONTENTELEMENT_H
