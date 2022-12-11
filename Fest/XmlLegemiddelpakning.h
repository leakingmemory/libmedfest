//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELPAKNING_H
#define LEGEMFEST_XMLLEGEMIDDELPAKNING_H

#include "XMLObject.h"
#include "KatLegemiddelpakning.h"
#include "XmlLegemiddelCore.h"
#include "XmlPreparattypeObject.h"

class XmlLegemiddelpakning : public XMLObject,
                                public FestIdObject,
                                public XmlLegemiddelCore,
                                public XmlPreparattypeObject {
private:
    std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning;
public:
    XmlLegemiddelpakning(std::shared_ptr<XmlOppfLegemiddelpakning> oppfLegemiddelpakning) : oppfLegemiddelpakning(oppfLegemiddelpakning) {}
    std::string GetName() const override;
    void Merge();
};

class XmlLegemiddelpakningHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLLEGEMIDDELPAKNING_H
