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
#include <memory>
#include <map>

class XmlPakningsinfo;

class XmlPakningsinfoObject : public XMLObject, public XmlRefLegemiddelMerkevare {
private:
    std::shared_ptr<XmlPakningsinfo> parent;
    std::string pakningsstr{};
    EnhetPakning enhetPakning{};
    Pakningstype pakningstype{};
    std::string mengde{};
    DDD ddd{};
    int statistikkfaktor{0};
public:
    XmlPakningsinfoObject(std::shared_ptr<XmlPakningsinfo> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetPakningsstr(const std::string &pakningsstr);
    void SetEnhetPakning(const EnhetPakning &enhetPakning);
    void SetPakningstype(const Pakningstype &pakningstype);
    void SetMengde(const std::string &mengde);
    void SetDDD(const DDD &ddd);
    void SetStatistikkfaktor(int statistikkfaktor);
    bool Merge();
};

class XmlPakningsinfo {
    friend XmlPakningsinfoObject;
private:
    Pakningsinfo pakningsinfo{};
    bool hasInfo{false};
public:
    virtual ~XmlPakningsinfo() = default;
    [[nodiscard]] Pakningsinfo GetPakningsinfo() const;
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

class XmlPakningstypeHandler : public XmlValueWithCodeSetHandler<XmlPakningsinfoObject> {
public:
    XmlPakningstypeHandler() : XmlValueWithCodeSetHandler<XmlPakningsinfoObject>("Pakningstype") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlPakningsinfoObject>> obj) override;
};

class XmlMengdeHandler : public XmlContentElementHandler<XmlPakningsinfoObject> {
public:
    XmlMengdeHandler() : XmlContentElementHandler<XmlPakningsinfoObject>("Mengde") {}
    bool Merge(std::shared_ptr<XmlPakningsinfoObject> parent, const std::string &content) override;
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

#endif //LEGEMFEST_XMLPAKNINGSINFO_H
