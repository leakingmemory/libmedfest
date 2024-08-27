//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLREFUSJONSVILKAR_H
#define LEGEMFEST_XMLREFUSJONSVILKAR_H

#include <Fest/XMLObject.h>
#include "XmlRefVilkar.h"
#include "XmlFraDato.h"
#include "XmlTilDato.h"
#include <Struct/Decoded/RefRefusjonsvilkar.h>
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

class XmlRefRefusjonsvilkarObject : public XMLObject, public XmlRefusjonsvilkarMergeable, public XmlRefVilkar,
                                    public XmlFraDato, public XmlTilDato {
private:
    std::shared_ptr<XmlRefRefusjonsvilkar> parent;
public:
    XmlRefRefusjonsvilkarObject(std::shared_ptr<XmlRefRefusjonsvilkar> parent) : parent(parent) {}
    std::string GetName() const override;
    bool Merge() override;
};

class XmlRefusjonsvilkarHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLREFUSJONSVILKAR_H
