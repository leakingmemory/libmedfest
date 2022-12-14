//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLPAKNINGSINFO_H
#define LEGEMFEST_XMLPAKNINGSINFO_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/Pakningsinfo.h"
#include "XmlRefLegemiddelMerkevare.h"
#include "XmlValueUnit.h"
#include "XmlPakningstype.h"
#include "XmlMengde.h"
#include "XmlSortering.h"
#include <memory>
#include <map>
#include <vector>

class XmlPakningsinfo;

class XmlPakningsinfoObject : public XMLObject, public XmlRefLegemiddelMerkevare, public XmlPakningstype, public XmlMengde, public XmlSortering {
    friend XmlPakningsinfo;
private:
    std::shared_ptr<XmlPakningsinfo> parent;
    std::string pakningsstr{};
    EnhetPakning enhetPakning{};
    Pakningstype pakningstype{};
    std::string mengde{};
    DDD ddd{};
    std::vector<Pakningskomponent> pakningskomponent{};
    double statistikkfaktor{0.0};
    int antall{0};
public:
    XmlPakningsinfoObject(std::shared_ptr<XmlPakningsinfo> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetPakningsstr(const std::string &pakningsstr);
    void SetEnhetPakning(const EnhetPakning &enhetPakning);
    bool Mengde(const std::string &mengde) override;
    void SetDDD(const DDD &ddd);
    void AddPakningskomponent(const Pakningskomponent &pakningskomponent);
    void SetStatistikkfaktor(double statistikkfaktor);
    void SetAntall(int antall);
    std::shared_ptr<XmlPakningsinfo> GetParent() const;
};

class XmlPakningsinfoHandler;

class XmlPakningsinfo {
    friend XmlPakningsinfoObject;
    friend XmlPakningsinfoHandler;
private:
    std::vector<std::shared_ptr<XmlPakningsinfoObject>> pakningsinfo{};
    bool hasInfo{false};
public:
    virtual ~XmlPakningsinfo() = default;
    [[nodiscard]] std::vector<Pakningsinfo> GetPakningsinfo() const;
};

class XmlPakningsinfoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlPakningsstrHandler : public XmlContentElementHandler<XmlPakningsinfoObject> {
public:
    XmlPakningsstrHandler() : XmlContentElementHandler<XmlPakningsinfoObject>("Pakningsstr") {}
    bool Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) override;
};

class XmlEnhetPakningHandler : public XmlValueWithCodeSetHandler<XmlPakningsinfoObject> {
public:
    XmlEnhetPakningHandler() : XmlValueWithCodeSetHandler<XmlPakningsinfoObject>("EnhetPakning") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningsinfoObject>> obj) override;
};

class XmlDDDHandler : public XmlValueUnitHandler<XmlPakningsinfoObject> {
public:
    XmlDDDHandler() : XmlValueUnitHandler<XmlPakningsinfoObject>("DDD") {}
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

class XmlStatistikkfaktorHandler : public XmlContentElementHandler<XmlPakningsinfoObject> {
public:
    XmlStatistikkfaktorHandler() : XmlContentElementHandler<XmlPakningsinfoObject>("Statistikkfaktor") {}
    bool Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) override;
};

class XmlAntallHandler : public XmlContentElementHandler<XmlPakningsinfoObject> {
public:
    XmlAntallHandler() : XmlContentElementHandler<XmlPakningsinfoObject>("Antall") {}
    bool Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLPAKNINGSINFO_H
