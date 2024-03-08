//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_TIDSPUNKTOBJECT_H
#define LEGEMFEST_TIDSPUNKTOBJECT_H

#include <Fest/XMLObject.h>
#include <memory>
#include <map>

class TidspunktObject {
private:
    std::string tidspunkt{};
public:
    virtual ~TidspunktObject() = default;
    std::string GetTidspunkt() const;
    void SetTidspunkt(const std::string &tidspunkt);
};

class XmlTidspunktObject : public XMLObject {
private:
    std::shared_ptr<TidspunktObject> tidspunktObject;
    std::string tidspunkt{};
public:
    XmlTidspunktObject(std::shared_ptr<TidspunktObject> tidspunktObject) : tidspunktObject(tidspunktObject) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class XmlTidspunktObjectHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_TIDSPUNKTOBJECT_H
