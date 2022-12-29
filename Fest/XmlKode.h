//
// Created by sigsegv on 12/29/22.
//

#ifndef LEGEMFEST_XMLKODE_H
#define LEGEMFEST_XMLKODE_H

#include "XmlContentElement.h"
#include "XmlValueWithDistinguishedName.h"
#include <string>

class XmlKode {
private:
    std::string kode{};
    ValueWithDistinguishedName vdnKode{};
public:
    virtual ~XmlKode() = default;
    void SetKode(const std::string &kode);
    [[nodiscard]] std::string GetKode() const;
    void SetKode(const ValueWithDistinguishedName &kode);
    [[nodiscard]] ValueWithDistinguishedName GetKodeValueWithDN() const;
};

class XmlKodeHandler : private XmlValueWithDistinguishedNameHandler<XmlKode>, private XmlContentElementHandler<XmlKode> {
public:
    XmlKodeHandler() : XmlValueWithDistinguishedNameHandler<XmlKode>("Kode"), XmlContentElementHandler<XmlKode>("Kode") {}
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
    bool Merge(std::shared_ptr<XmlKode> parent, const std::string &content) override;
    bool Merge(std::shared_ptr<XmlType> obj) override;
};

#endif //LEGEMFEST_XMLKODE_H
