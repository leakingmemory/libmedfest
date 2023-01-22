//
// Created by sigsegv on 12/18/22.
//

#ifndef LEGEMFEST_XMLLEGEMIDDELVIRKESTOFF_H
#define LEGEMFEST_XMLLEGEMIDDELVIRKESTOFF_H

#include "XMLObject.h"
#include "KatLegemiddelVirkestoff.h"
#include "XmlLegemiddel.h"
#include "XmlRefusjon.h"
#include "XmlRefLegemiddelMerkevare.h"
#include "XmlRefPakning.h"
#include "XmlValueWithCodeSet.h"

class XmlLegemiddelVirkestoff : public XMLObject, public FestIdObject, public XmlLegemiddel, public XmlRefusjon,
                                public XmlRefLegemiddelMerkevare, public XmlRefPakning {
private:
    std::shared_ptr<XmlOppfLegemiddelVirkestoff> oppfLegemiddelVirkestoff;
    EnhetForskrivning forskrivningsenhetResept{};
public:
    XmlLegemiddelVirkestoff(const std::shared_ptr<XmlOppfLegemiddelVirkestoff> &oppfLegemiddelVirkestoff) :
            oppfLegemiddelVirkestoff(oppfLegemiddelVirkestoff) {}
    std::string GetName() const override;
    bool SetForskrivningsenhetResept(const EnhetForskrivning &forskrivningsenhetResept);
    [[nodiscard]] bool Merge();
};

class XmlLegemiddelVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlForskrivningsenhetReseptHandler : public XmlValueWithCodeSetHandler<XmlLegemiddelVirkestoff> {
public:
    XmlForskrivningsenhetReseptHandler() : XmlValueWithCodeSetHandler<XmlLegemiddelVirkestoff>("ForskrivningsenhetResept") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddelVirkestoff>> obj) override;
};

#endif //LEGEMFEST_XMLLEGEMIDDELVIRKESTOFF_H
