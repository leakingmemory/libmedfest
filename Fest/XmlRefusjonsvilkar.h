//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLREFUSJONSVILKAR_H
#define LEGEMFEST_XMLREFUSJONSVILKAR_H

#include "XMLObject.h"
#include "XmlRefVilkar.h"
#include "../Struct/Decoded/RefRefusjonsvilkar.h"
#include <vector>
#include <memory>
#include <map>

class XmlRefRefusjonsvilkar {
private:
    std::vector<RefRefusjonsvilkar> refusjonsvilkar{};
public:
    virtual ~XmlRefRefusjonsvilkar() = default;
    void AddRefusjonsvilkar(const RefRefusjonsvilkar &refusjonsvilkar);
    [[nodiscard]] std::vector<RefRefusjonsvilkar> GetRefusjonsvilkar() const;
};

class XmlRefusjonsvilkarMergeable {
public:
    virtual bool Merge() = 0;
};

class XmlRefRefusjonsvilkarObject : public XMLObject, public XmlRefusjonsvilkarMergeable, public XmlRefVilkar {
private:
    std::shared_ptr<XmlRefRefusjonsvilkar> parent;
    std::string fraDato{};
public:
    XmlRefRefusjonsvilkarObject(std::shared_ptr<XmlRefRefusjonsvilkar> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetFraDato(const std::string &fraDato);
    bool Merge() override;
};

class XmlRefusjonsvilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlFraDatoHandler : public XmlContentElementHandler<XmlRefRefusjonsvilkarObject> {
public:
    XmlFraDatoHandler() : XmlContentElementHandler<XmlRefRefusjonsvilkarObject>("FraDato") {}
    bool Merge(std::shared_ptr<XmlRefRefusjonsvilkarObject> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFUSJONSVILKAR_H
