//
// Created by sigsegv on 12/31/22.
//

#include <iostream>
#include "XmlDoseFastTidspunkt.h"
#include "XmlDosering.h"

std::string XmlDoseFastTidspunkt::GetName() const {
    return "DoseFastTidspunkt";
}

bool XmlDoseFastTidspunkt::Mengde(const ValueUnit &mengde) {
    this->mengde = mengde;
    return true;
}

void XmlDoseFastTidspunkt::SetIntervall(const ValueUnit &intervall) {
    this->intervall = intervall;
}

void XmlDoseFastTidspunkt::SetTidsomrade(const ValueWithDistinguishedName &tidsomrade) {
    this->tidsomrade = tidsomrade;
}

void XmlDoseFastTidspunkt::SetGisEksakt(bool gisEksakt) {
    this->gisEksakt = gisEksakt ? MaybeBoolean::MTRUE : MaybeBoolean::MFALSE;
}

bool XmlDoseFastTidspunkt::SetFastDose(const FastDose &fastDose) {
    if (this->fastDose.GetDagerPa() != 0 || this->fastDose.GetDagerAv() != 0) {
        std::cerr << "Error: Duplicate FastDose\n";
        return false;
    }
    this->fastDose = fastDose;
    return true;
}

bool XmlDoseFastTidspunkt::Merge() {
    bool gisEksakt;
    {
        switch (this->gisEksakt) {
            case MaybeBoolean::MFALSE:
                gisEksakt = false;
                break;
            case MaybeBoolean::MTRUE:
                gisEksakt = true;
                break;
            default:
                std::cerr << "Error: GisEksakt: Not specified\n";
                return false;
        }
    }
    return parent->AddDoseFastTidspunkt({mengde, intervall, tidsomrade, gisEksakt, fastDose});
}

std::shared_ptr<XMLObject> XmlDoseFastTidspunktHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                     const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlDosering> typedParent = std::dynamic_pointer_cast<XmlDosering>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected DoseFastTidspunkt\n";
        return {};
    }
    return std::make_shared<XmlDoseFastTidspunkt>(typedParent);
}

bool XmlDoseFastTidspunktHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *d = dynamic_cast<XmlDoseFastTidspunkt *>(&(*obj));
    if (d == nullptr) {
        std::cerr << "Error: Not ending DoseFastTidspunkt\n";
        return false;
    }
    return d->Merge();
}

bool XmlIntervallHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetIntervall({obj->GetValueUnit()});
    return true;
}

bool XmlTidsomradeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetTidsomrade({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlGisEksaktHandler::Merge(std::shared_ptr<XmlDoseFastTidspunkt> parent, const std::string &content) {
    if (content == "false") {
        parent->SetGisEksakt(false);
        return true;
    } else if (content == "true") {
        parent->SetGisEksakt(true);
        return true;
    } else {
        std::cerr << "Error: GisEksakt: Invalid value: " << content << "\n";
        return false;
    }
}