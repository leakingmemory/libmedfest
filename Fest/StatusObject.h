//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_STATUSOBJECT_H
#define LEGEMFEST_STATUSOBJECT_H

#include <Struct/Decoded/Status.h>
#include <Fest/XMLObject.h>
#include <string>
#include <memory>
#include <map>

class StatusObject {
private:
    Status status{};
public:
    virtual ~StatusObject() = default;
    Status GetStatus() const;
    void SetStatus(const Status &status);
};

class XmlStatusObject : public XMLObject {
public:
    std::string GetName() const override;
};

class XmlStatusObjectHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_STATUSOBJECT_H
