//
// Created by sigsegv on 12/28/22.
//

#ifndef LEGEMFEST_XMLBYTTEGRUPPE_H
#define LEGEMFEST_XMLBYTTEGRUPPE_H

#include "XMLObject.h"
#include "FestIdObject.h"
#include "XmlKode.h"
#include "XmlContentElement.h"
#include "XmlGyldigFraDato.h"
#include "../Struct/Decoded/MaybeBoolean.h"
#include <memory>
#include <map>

class XmlOppfByttegruppe;

class XmlByttegruppe : public XMLObject, public FestIdObject, public XmlKode, public XmlGyldigFraDato {
private:
    std::shared_ptr<XmlOppfByttegruppe> parent;
    std::string beskrivelseByttbarhet{};
    MaybeBoolean merknadTilByttbarhet{MaybeBoolean::UNSPECIFIED};
public:
    XmlByttegruppe(std::shared_ptr<XmlOppfByttegruppe> parent) : parent(parent) {}
    std::string GetName() const override;
    void SetBeskrivelseByttbarhet(const std::string &beskrivelseByttbarhet);
    void SetMerknadTilByttbarhet(bool merknadTilByttbarhet);
    bool Merge();
};

class XmlByttegruppeHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class XmlMerknadTilByttbarhetHandler : public XmlContentElementHandler<XmlByttegruppe> {
public:
    XmlMerknadTilByttbarhetHandler() : XmlContentElementHandler<XmlByttegruppe>("MerknadTilByttbarhet") {}
    bool Merge(std::shared_ptr<XmlByttegruppe> parent, const std::string &content) override;
};

class XmlBeskrivelseByttbarhetHandler : public XmlContentElementHandler<XmlByttegruppe> {
public:
    XmlBeskrivelseByttbarhetHandler() : XmlContentElementHandler<XmlByttegruppe>("BeskrivelseByttbarhet") {}
    bool Merge(std::shared_ptr<XmlByttegruppe> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLBYTTEGRUPPE_H
