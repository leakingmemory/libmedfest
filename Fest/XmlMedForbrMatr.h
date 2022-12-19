//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_XMLMEDFORBRMATR_H
#define LEGEMFEST_XMLMEDFORBRMATR_H

#include "XMLObject.h"
#include "XmlNavn.h"
#include <memory>

class XmlOppfHandelsvare;

class XmlMedForbrMatr : public XMLObject, public XmlNavn {
private:
    std::shared_ptr<XmlOppfHandelsvare> oppf;
    std::string nr{};
public:
    XmlMedForbrMatr(std::shared_ptr<XmlOppfHandelsvare> oppf) : oppf(oppf) {}
    std::string GetName() const override;
    void SetNr(const std::string &nr);
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
