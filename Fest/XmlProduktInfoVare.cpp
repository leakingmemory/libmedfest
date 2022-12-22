//
// Created by sigsegv on 12/19/22.
//

#include "XmlProduktInfoVare.h"
#include "XmlHandelsvare.h"

std::string XmlProduktInfoVare::GetName() const {
    return "ProduktInfoVare";
}

void XmlProduktInfoVare::SetProduktNr(const std::string &produktNr) {
    this->produktNr = produktNr;
}

void XmlProduktInfoVare::SetVolum(const std::string &volum) {
    this->volum = volum;
}

void XmlProduktInfoVare::SetEnhetStorrelse(const EnhetStorrelse &enhetStorrelse) {
    this->enhetStorrelse = enhetStorrelse;
}

void XmlProduktInfoVare::SetAntPerPakning(int antPerPakning) {
    this->antPerPakning = antPerPakning;
}

void XmlProduktInfoVare::SetTillattMerMakspris(bool tillattMerMakspris) {
    this->tillattMerMakspris = tillattMerMakspris ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

bool XmlProduktInfoVare::Merge() {
    parent->SetProduktInfoVare({produktNr, volum, enhetStorrelse, antPerPakning, tillattMerMakspris});
    return true;
}

std::shared_ptr<XMLObject>
XmlProduktInfoVareHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes) {
    std::shared_ptr<XmlHandelsvare> typedParent = std::dynamic_pointer_cast<XmlHandelsvare>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected ProductInfoVare\n";
        return {};
    }
    return std::make_shared<XmlProduktInfoVare>(typedParent);
}

bool XmlProduktInfoVareHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *pi = dynamic_cast<XmlProduktInfoVare *>(&(*obj));
    if (pi == nullptr) {
        std::cerr << "Error: Not ending ProductInfoVare\n";
        return false;
    }
    return pi->Merge();
}

bool XmlProduktNrHandler::Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) {
    parent->SetProduktNr(content);
    return true;
}

bool XmlVolumHandler::Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) {
    parent->SetVolum(content);
    return true;
}

bool XmlEnhetStorrelseHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlProduktInfoVare>> obj) {
    obj->GetParent()->SetEnhetStorrelse({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlAntPerPakningHandler::Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) {
    char *err;
    long lval = strtol(content.c_str(), &err, 10);
    if (err == nullptr || *err != '\0') {
        std::cerr << "Error: AntPerPakning: Invalid value: " << content << "\n";
        return false;
    }
    int value = (int) lval;
    if (((long) value) != lval) {
        std::cerr << "Error: AntPerPakning: Invalid value: " << content << " (overflow)\n";
        return false;
    }
    parent->SetAntPerPakning(value);
    return true;
}

bool XmlTillattMerMaksprisHandler::Merge(std::shared_ptr<XmlProduktInfoVare> parent, const std::string &content) {
    if (content == "true") {
        parent->SetTillattMerMakspris(true);
        return true;
    } else if (content == "false") {
        parent->SetTillattMerMakspris(false);
        return true;
    }
    std::cerr << "Error: TillattMerMakspris: Invalid value: " << content << "\n";
    return false;
}