//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_XMLMEDFORBRMATR_H
#define LEGEMFEST_XMLMEDFORBRMATR_H

#include "XMLObject.h"
#include "XmlNavn.h"
#include "XmlPrisVare.h"
#include "XmlRefusjon.h"
#include "../Struct/Decoded/ProduktInfoVare.h"
#include "../Struct/Decoded/Leverandor.h"
#include <memory>

class XmlOppfHandelsvare;

class XmlMedForbrMatr : public XMLObject, public XmlNavn, public XmlPrisVare, public XmlRefusjon {
private:
    std::shared_ptr<XmlOppfHandelsvare> oppf;
    std::string nr{};
    ProduktInfoVare produktInfoVare{};
    Leverandor leverandor{};
public:
    XmlMedForbrMatr(std::shared_ptr<XmlOppfHandelsvare> oppf) : oppf(oppf) {}
    std::string GetName() const override;
    void SetNr(const std::string &nr);
    void SetProduktInfoVare(const ProduktInfoVare &produktInfoVare);
    void SetLeverandor(const Leverandor &leverandor);
    bool Merge();
};

class XmlMedForbrMatrHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlNrHandler : public XmlContentElementHandler<XmlMedForbrMatr> {
public:
    XmlNrHandler() : XmlContentElementHandler<XmlMedForbrMatr>("Nr") {}
    bool Merge(std::shared_ptr<XmlMedForbrMatr> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLMEDFORBRMATR_H
