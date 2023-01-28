//
// Created by sigsegv on 12/17/22.
//

#include "XmlVirkestoffMedStyrke.h"
#include "KatVirkestoff.h"
#include <iostream>

std::string XmlVirkestoffMedStyrke::GetName() const {
    return "VirkestoffMedStyrke";
}

void XmlVirkestoffMedStyrke::SetStyrke(const Styrke &styrke) {
    this->styrke = styrke;
}

void XmlVirkestoffMedStyrke::SetStyrkenevner(const Styrkenevner &styrkenevner) {
    this->styrkenevner = styrkenevner;
}

void XmlVirkestoffMedStyrke::SetStyrkeoperator(const Styrkeoperator &styrkeoperator) {
    this->styrkeoperator = styrkeoperator;
}

void XmlVirkestoffMedStyrke::SetAlternativStyrke(const Styrke &alternativStyrke) {
    this->alternativStyrke = alternativStyrke;
}

void XmlVirkestoffMedStyrke::SetAlternativStyrkenevner(const Styrkenevner &styrkenevner) {
    this->alternativStyrkenevner = styrkenevner;
}

void XmlVirkestoffMedStyrke::SetAtcKombipreparat(const Atc &atc) {
    this->atcKombipreparat = atc;
}

void XmlVirkestoffMedStyrke::SetStyrkeOvreVerdi(double styrkeOvreVerdi) {
    this->styrkeOvreVerdi = styrkeOvreVerdi;
}

bool XmlVirkestoffMedStyrke::Merge() {
    auto refVirkestoff = GetRefVirkestoff();
    if (refVirkestoff.size() < 1) {
        std::cerr << "Error: VirkestoffMedStyrke: No RefVirkestoff\n";
        return false;
    }
    if (refVirkestoff.size() > 1) {
        std::cerr << "Error: VirkestoffMedStyrke: Multiple RefVirkestoff\n";
        return false;
    }
    oppfVirkestoff->SetVirkestoffMedStyrke({GetId(), refVirkestoff[0], styrke, styrkenevner, styrkeoperator, alternativStyrke, alternativStyrkenevner, atcKombipreparat, styrkeOvreVerdi});
    return true;
}

std::shared_ptr <XMLObject>
XmlVirkestoffMedStyrkeHandler::StartElement(const std::shared_ptr <XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<XmlOppfVirkestoff> oppf = std::dynamic_pointer_cast<XmlOppfVirkestoff>(parent);
    if (!oppf) {
        std::cerr << "Error: Virkestoff not expected here\n";
        return {};
    }
    return std::make_shared<XmlVirkestoffMedStyrke>(oppf);
}

bool XmlVirkestoffMedStyrkeHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *oppf = dynamic_cast<XmlVirkestoffMedStyrke*>(&(*obj));
    if (oppf == nullptr) {
        std::cerr << "Error: End of Virkestoff, but not currently a V..\n";
        return false;
    }
    return oppf->Merge();
}

bool XmlStyrkeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetStyrke({obj->GetValueUnit()});
    return true;
}

bool XmlStyrkeoperatorHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVirkestoffMedStyrke>> obj) {
    obj->GetParent()->SetStyrkeoperator({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlStyrkeNevnerHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetStyrkenevner({obj->GetValueUnit()});
    return true;
}

bool XmlAlternativStyrkeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetAlternativStyrke({obj->GetValueUnit()});
    return true;
}

bool XmlAlternativStyrkeNevnerHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetAlternativStyrkenevner({obj->GetValueUnit()});
    return true;
}

bool XmlAtcKombipreparatHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlVirkestoffMedStyrke>> obj) {
    obj->GetParent()->SetAtcKombipreparat({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlStyrkeOvreVerdiHandler::Merge(std::shared_ptr<XmlVirkestoffMedStyrke> parent, const std::string &content) {
    char *err;
    double value = strtod(content.c_str(), &err);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: StyrkeOvreVerdi: Invalid value: " << content << "\n";
        return false;
    }
    parent->SetStyrkeOvreVerdi(value);
    return true;
}