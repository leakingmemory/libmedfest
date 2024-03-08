//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_XMLINFO_H
#define LEGEMFEST_XMLINFO_H

#include <Fest/XMLObject.h>
#include "FestIdObject.h"
#include "XmlContentElement.h"
#include <memory>
#include <map>

class XmlOppfKodeverk;

class XmlInfo : public XMLObject, public FestIdObject {
private:
    std::shared_ptr<XmlOppfKodeverk> parent;
    std::string betegnelse{};
    std::string kortnavn{};
    std::string ansvarligUtgiver{};
public:
    XmlInfo(std::shared_ptr<XmlOppfKodeverk> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetBetegnelse(const std::string &betegnelse);
    void SetKortnavn(const std::string &kortnavn);
    void SetAnsvarligUtgiver(const std::string &ansvarligUtgiver);
    bool Merge();
};

class XmlInfoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlBetegnelseHandler : public XmlContentElementHandler<XmlInfo> {
public:
    XmlBetegnelseHandler() : XmlContentElementHandler<XmlInfo>("Betegnelse") {}
    bool Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) override;
};

class XmlKortnavnHandler : public XmlContentElementHandler<XmlInfo> {
public:
    XmlKortnavnHandler() : XmlContentElementHandler<XmlInfo>("Kortnavn") {}
    bool Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) override;
};

class XmlAnsvarligUtgiverHandler : public XmlContentElementHandler<XmlInfo> {
public:
    XmlAnsvarligUtgiverHandler() : XmlContentElementHandler<XmlInfo>("AnsvarligUtgiver") {}
    bool Merge(std::shared_ptr<XmlInfo> parent, const std::string &content) override;
};
#endif //LEGEMFEST_XMLINFO_H
