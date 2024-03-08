//
// Created by sigsegv on 12/31/22.
//

#ifndef LEGEMFEST_XMLDOSERING_H
#define LEGEMFEST_XMLDOSERING_H

#include <Fest/XMLObject.h>
#include <Struct/Decoded/DoseFastTidspunkt.h>
#include <memory>
#include <map>
#include <vector>

class XmlLegemiddelforbruk;

class XmlDosering : public XMLObject {
private:
    std::shared_ptr<XmlLegemiddelforbruk> parent;
    std::vector<DoseFastTidspunkt> doseFastTidspunkt{};
public:
    XmlDosering(std::shared_ptr<XmlLegemiddelforbruk> parent) : parent(parent) {}
    [[nodiscard]] bool AddDoseFastTidspunkt(const DoseFastTidspunkt &doseFastTidspunkt);
    std::string GetName() const override;
    bool Merge();
};

class XmlDoseringHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::map<std::string,std::string> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_XMLDOSERING_H
