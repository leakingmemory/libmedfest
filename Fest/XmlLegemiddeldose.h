//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELDOSE_H
#define LEGEMFEST_XMLLEGEMIDDELDOSE_H

#include <Fest/XMLObject.h>
#include "XmlLegemiddelCore.h"
#include "XmlPreparattypeObject.h"
#include "FestIdObject.h"
#include "XmlContentElement.h"
#include "XmlMengde.h"
#include "XmlRefLegemiddelMerkevare.h"
#include "XmlRefPakning.h"
#include "XmlPakningskomponent.h"
#include <Struct/Decoded/ValueUnit.h>
#include <memory>
#include <map>

class XmlOppfLegemiddeldose;

class XmlLegemiddeldose : public XMLObject, public XmlLegemiddelCore, public XmlPreparattypeObject, public FestIdObject,
                          public XmlMengde, public XmlRefLegemiddelMerkevare, public XmlRefPakning,
                          public XmlPakningskomponentInfo, public XmlPakningstype {
private:
    std::shared_ptr<XmlOppfLegemiddeldose> parent;
    std::string lmrLopenr{};
    ValueUnit mengde{};
    std::vector<PakningskomponentInfo> pakningskomponent{};
public:
    XmlLegemiddeldose(std::shared_ptr<XmlOppfLegemiddeldose> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetLmrLopenr(const std::string &lmrLopenr);
    bool Mengde(const ValueUnit &mengde) override;
    bool Mengde(const std::string &) override;
    bool Merge(const PakningskomponentInfo &pakningskomponent) override;
    bool Merge();
};

class XmlLegemiddeldoseHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlLmrLopenrHandler : public XmlContentElementHandler<XmlLegemiddeldose> {
public:
    XmlLmrLopenrHandler() : XmlContentElementHandler<XmlLegemiddeldose>("LmrLopenr") {}
    bool Merge(std::shared_ptr<XmlLegemiddeldose> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELDOSE_H
