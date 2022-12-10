//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLRESEPTGYLDIGHET_H
#define LEGEMFEST_XMLRESEPTGYLDIGHET_H

#include "XMLObject.h"
#include "XmlLegemiddelMerkevare.h"
#include "XmlVarighet.h"
#include <memory>
#include <map>

class XmlReseptgyldighet : public XMLObject, public XmlVarighet {
private:
    std::shared_ptr<XmlLegemiddelMerkevare> parent;
public:
    XmlReseptgyldighet(std::shared_ptr<XmlLegemiddelMerkevare> parent) : parent(parent) {}
    virtual ~XmlReseptgyldighet() = default;
    std::string GetName() const override;
    bool Merge();
};

class XmlReseptgyldighetHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_XMLRESEPTGYLDIGHET_H
