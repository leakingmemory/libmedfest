//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_XMLVIRKESTOFF_H
#define LEGEMFEST_XMLVIRKESTOFF_H

#include <Fest/XMLObject.h>
#include "KatVirkestoff.h"
#include "FestIdObject.h"
#include "XmlNavn.h"
#include "XmlNavnEngelsk.h"
#include "XmlRefVirkestoff.h"

class XmlVirkestoff :
        public XMLObject, public FestIdObject, public XmlNavn, public XmlNavnEngelsk, public XmlRefVirkestoff {
private:
    std::shared_ptr<XmlOppfVirkestoff> oppfVirkestoff;
public:
    XmlVirkestoff(std::shared_ptr<XmlOppfVirkestoff> oppfVirkestoff) : oppfVirkestoff(oppfVirkestoff) {}
    std::string GetName() const override;
    void Merge();
};

class XmlVirkestoffHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};


#endif //LEGEMFEST_XMLVIRKESTOFF_H
