//
// Created by sigsegv on 12/9/22.
//

#ifndef LEGEMFEST_FESTIDOBJECT_H
#define LEGEMFEST_FESTIDOBJECT_H

#include "XMLObject.h"
#include <string>
#include <memory>
#include <map>

class FestIdObject {
private:
    std::string id{};
public:
    virtual ~FestIdObject() = default;
    std::string GetId() const;
    void SetId(const std::string &id);
};

class XmlIdObject : public XMLObject {
private:
    std::shared_ptr<FestIdObject> festIdObject;
    std::string id;
public:
    XmlIdObject(std::shared_ptr<FestIdObject> festIdObject) : festIdObject(festIdObject) {}
    std::string GetName() const override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class FestIdHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_FESTIDOBJECT_H
