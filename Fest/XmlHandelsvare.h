//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_XMLHANDELSVARE_H
#define LEGEMFEST_XMLHANDELSVARE_H

#include "XMLObject.h"
#include "XmlNavn.h"
#include "XmlPrisVare.h"
#include "XmlRefusjon.h"
#include "../Struct/Decoded/ProduktInfoVare.h"
#include "../Struct/Decoded/Leverandor.h"
#include <memory>

class XmlOppfHandelsvare;

class XmlHandelsvare : public XMLObject, public XmlNavn, public XmlPrisVare, public XmlRefusjon {
protected:
    std::shared_ptr<XmlOppfHandelsvare> oppf;
    std::string nr{};
    ProduktInfoVare produktInfoVare{};
    Leverandor leverandor{};
public:
    XmlHandelsvare(std::shared_ptr<XmlOppfHandelsvare> oppf) : oppf(oppf) {}
    std::string GetName() const override = 0;
    void SetNr(const std::string &nr);
    void SetProduktInfoVare(const ProduktInfoVare &produktInfoVare);
    void SetLeverandor(const Leverandor &leverandor);
    virtual bool Merge() = 0;
};

class XmlMedForbrMatr : public XmlHandelsvare {
public:
    XmlMedForbrMatr(std::shared_ptr<XmlOppfHandelsvare> oppf) : XmlHandelsvare(oppf) {}
    std::string GetName() const override;
    bool Merge() override;
};

class XmlNaringsmiddel : public XmlHandelsvare {
public:
    XmlNaringsmiddel(std::shared_ptr<XmlOppfHandelsvare> oppf) : XmlHandelsvare(oppf) {}
    std::string GetName() const override;
    bool Merge() override;
};

class XmlMedForbrMatrHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlNaringsmiddelHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlNrHandler : public XmlContentElementHandler<XmlHandelsvare> {
public:
    XmlNrHandler() : XmlContentElementHandler<XmlHandelsvare>("Nr") {}
    bool Merge(std::shared_ptr<XmlHandelsvare> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLHANDELSVARE_H
