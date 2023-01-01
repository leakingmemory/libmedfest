//
// Created by sigsegv on 12/30/22.
//

#include "XmlKortdose.h"

void XmlKortdose::AddKortdose(const ValueWithCodeSet &kortdose) {
    this->kortdose.emplace_back(kortdose);
}

std::vector<ValueWithCodeSet> XmlKortdose::GetKortdose() const {
    return kortdose;
}

bool XmlKortdoseObject::SetKortdose(const Kortdose &kortdose) {
    if (this->kortdose.GetKortdose().GetValue().empty()) {
        this->kortdose = kortdose;
        return true;
    } else {
        std::cerr << "Error: Multiple Kortdose -> Kortdose\n";
        return false;
    }
}

Kortdose XmlKortdoseObject::GetKortdose() const {
    return kortdose;
}

std::string XmlKortdoseObjectObject::GetName() const {
    return "Kortdose";
}

bool XmlKortdoseObjectObject::AddLegemiddelforbruk(const Legemiddelforbruk &legemiddelforbruk) {
    this->legemiddelforbruk.emplace_back(legemiddelforbruk);
    return true;
}

bool XmlKortdoseObjectObject::Merge() {
    ValueWithCodeSet kortdose{};
    {
        auto kortdoser = GetKortdose();
        if (kortdoser.size() < 1) {
            std::cerr << "Error: Expected Kortdose -> Kortdose\n";
            return false;
        }
        if (kortdoser.size() > 1) {
            std::cerr << "Error: Multiple Kortdose -> Kortdose\n";
            return false;
        }
        kortdose = kortdoser[0];
    }
    return parent->SetKortdose({kortdose, GetBeskrivelseTerm(), legemiddelforbruk});
}

std::shared_ptr<XMLObject> XmlKortdoseHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                            const std::map<std::string, std::string> &attributes) {
    {
        auto hasV = attributes.find("V") != attributes.end();
        auto hasS = attributes.find("S") != attributes.end();
        auto hasDN = attributes.find("DN") != attributes.end();
        if (hasV && hasS && hasDN) {
            return XmlValueWithCodeSetHandler<XmlKortdose>::StartElement(parent, attributes);
        }
    }
    std::shared_ptr<XmlKortdoseObject> typedParent = std::dynamic_pointer_cast<XmlKortdoseObject>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Kortdose\n";
        return {};
    }
    return std::make_shared<XmlKortdoseObjectObject>(typedParent);
}

bool XmlKortdoseHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *k = dynamic_cast<XmlKortdoseObjectObject *>(&(*obj));
    if (k == nullptr) {
        return XmlValueWithCodeSetHandler<XmlKortdose>::EndElement(obj);
    }
    return k->Merge();
}

bool XmlKortdoseHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlKortdose>> obj) {
    obj->GetParent()->AddKortdose({obj->GetValueWithCodeSet()});
    return true;
}
