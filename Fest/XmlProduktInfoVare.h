//
// Created by sigsegv on 12/19/22.
//

#ifndef LEGEMFEST_XMLPRODUKTINFOVARE_H
#define LEGEMFEST_XMLPRODUKTINFOVARE_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include "XmlValueWithCodeSet.h"
#include "../Struct/Decoded/EnhetStorrelse.h"
#include "../Struct/Decoded/MaybeBoolean.h"
#include <memory>
#include <map>

class XmlMedForbrMatr;

class XmlProduktInfoVare : public XMLObject {
private:
    std::shared_ptr<XmlMedForbrMatr> parent;
    std::string produktNr{};
    std::string volum{};
    EnhetStorrelse enhetStorrelse{};
    int antPerPakning{0};
    MaybeBoolean tillattMerMakspris{MaybeBoolean::UNSPECIFIED};
public:
    XmlProduktInfoVare(const std::shared_ptr<XmlMedForbrMatr> &parent) : parent(parent) {}
    std::string GetName() const override;
    void SetProduktNr(const std::string &produktNr);
    void SetVolum(const std::string &volum);
    void SetEnhetStorrelse(const EnhetStorrelse &enhetStorrelse);
    void SetAntPerPakning(int antPerPakning);
    void SetTillattMerMakspris(bool tillattMerMakspris);
    bool Merge();
};

class XmlProduktInfoVareHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlProduktNrHandler : public XmlContentElementHandler<XmlProduktInfoVare> {
public:
    XmlProduktNrHandler() : XmlContentElementHandler<XmlProduktInfoVare>("ProduktNr") {}
    bool Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) override;
};

class XmlVolumHandler : public XmlContentElementHandler<XmlProduktInfoVare> {
public:
    XmlVolumHandler() : XmlContentElementHandler<XmlProduktInfoVare>("Volum") {}
    bool Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) override;
};

class XmlEnhetStorrelseHandler : public XmlValueWithCodeSetHandler<XmlProduktInfoVare> {
public:
    XmlEnhetStorrelseHandler() : XmlValueWithCodeSetHandler<XmlProduktInfoVare>("EnhetStorrelse") {}
    bool Merge(std::shared_ptr<XmlValueWithCodeSet<XmlProduktInfoVare>> obj) override;
};

class XmlAntPerPakningHandler : public XmlContentElementHandler<XmlProduktInfoVare> {
public:
    XmlAntPerPakningHandler() : XmlContentElementHandler<XmlProduktInfoVare>("AntPerPakning") {}
    bool Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) override;
};

class XmlTillattMerMaksprisHandler : public XmlContentElementHandler<XmlProduktInfoVare> {
public:
    XmlTillattMerMaksprisHandler() : XmlContentElementHandler<XmlProduktInfoVare>("TillattMerMakspris") {}
    bool Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLPRODUKTINFOVARE_H
