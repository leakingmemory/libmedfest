//
// Created by sigsegv on 12/20/22.
//

#ifndef LEGEMFEST_XMLLEVERANDOR_H
#define LEGEMFEST_XMLLEVERANDOR_H

#include "XMLObject.h"
#include "XmlNavn.h"
#include "XmlContentElement.h"
#include <memory>

class XmlHandelsvare;

class XmlLeverandor : public XMLObject, public XmlNavn {
private:
    std::shared_ptr<XmlHandelsvare> parent;
    std::string adresse{};
    std::string telefon{};
public:
    XmlLeverandor(std::shared_ptr<XmlHandelsvare> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetAdresse(const std::string &adresse);
    void SetTelefon(const std::string &telefon);
    bool Merge();
};

class XmlLeverandorHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlAdresseHandler : public XmlContentElementHandler<XmlLeverandor> {
public:
    XmlAdresseHandler() : XmlContentElementHandler<XmlLeverandor>("Adresse") {}
    bool Merge(std::shared_ptr<XmlLeverandor> parent, const std::string &content) override;
};

class XmlTelefonHandler : public XmlContentElementHandler<XmlLeverandor> {
public:
    XmlTelefonHandler() : XmlContentElementHandler<XmlLeverandor>("Telefon") {}
    bool Merge(std::shared_ptr<XmlLeverandor> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLLEVERANDOR_H
