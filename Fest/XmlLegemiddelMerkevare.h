//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "KatLegemiddelMerkevare.h"
#include "XmlLegemiddel.h"
#include "XmlPreparattypeObject.h"

class XmlLegemiddelMerkevare :
        public XMLObject,
        public FestIdObject,
        public XmlLegemiddel,
        public XmlPreparattypeObject {
private:
    std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare;
public:
    XmlLegemiddelMerkevare(std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare) : oppfLegemiddelMerkevare(oppfLegemiddelMerkevare) {}
    std::string GetName() const override;
    void Merge();
};

class XmlLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
