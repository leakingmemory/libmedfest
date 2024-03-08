//
// Created by sigsegv on 12/13/22.
//

#ifndef LEGEMFEST_XMLMENGDE_H
#define LEGEMFEST_XMLMENGDE_H

#include <Struct/Decoded/ValueUnit.h>
#include <Fest/XMLObject.h>
#include <memory>
#include <map>

class XmlMengde {
public:
    virtual bool Mengde(const std::string &);
    virtual bool Mengde(const ValueUnit &);
};

class XmlMengdeObject : public XMLObject {
private:
    std::shared_ptr<XmlMengde> parent;
    std::string content{};
    bool vu{false};
public:
    XmlMengdeObject(std::shared_ptr<XmlMengde> parent) : parent(parent) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    bool Mengde(const ValueUnit &);
    bool Merge();
};

class XmlMengdeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLMENGDE_H
