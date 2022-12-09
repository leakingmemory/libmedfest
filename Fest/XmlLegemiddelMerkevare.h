//
// Created by jeo on 12/9/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "KatLegemiddelMerkevare.h"

class XmlLegemiddelMerkevare :
        public XMLObject,
        public FestIdObject {
private:
    std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare;
public:
    XmlLegemiddelMerkevare(std::shared_ptr<XmlOppfLegemiddelMerkevare> oppfLegemiddelMerkevare) : oppfLegemiddelMerkevare(oppfLegemiddelMerkevare) {}
    std::string GetName() override;
    void Merge();
};

class XmlLegemiddelMerkevareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_XMLLEGEMIDDELMERKEVARE_H
