//
// Created by sigsegv on 1/1/23.
//

#ifndef LEGEMFEST_XMLFASTDOSE_H
#define LEGEMFEST_XMLFASTDOSE_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include <memory>
#include <map>

class XmlDoseFastTidspunkt;

class XmlFastDose : public XMLObject {
private:
    std::shared_ptr<XmlDoseFastTidspunkt> parent;
    int dagerPa{0};
    int dagerAv{0};
public:
    XmlFastDose(std::shared_ptr<XmlDoseFastTidspunkt> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetDagerPa(int dagerPa);
    void SetDagerAv(int dagerAv);
    bool Merge();
};

class XmlFastDoseHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlDagerPaHandler : public XmlContentElementHandler<XmlFastDose> {
public:
    XmlDagerPaHandler() : XmlContentElementHandler<XmlFastDose>("DagerPa") {}
    bool Merge(std::shared_ptr<XmlFastDose> parent, const std::string &content) override;
};

class XmlDagerAvHandler : public XmlContentElementHandler<XmlFastDose> {
public:
    XmlDagerAvHandler() : XmlContentElementHandler<XmlFastDose>("DagerAv") {}
    bool Merge(std::shared_ptr<XmlFastDose> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLFASTDOSE_H
