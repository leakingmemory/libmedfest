//
// Created by sigsegv on 12/16/22.
//

#ifndef LEGEMFEST_XMLMULTIPPEL_H
#define LEGEMFEST_XMLMULTIPPEL_H

#include "XmlContentElement.h"
#include <memory>

class XmlMultippel {
private:
    int multippel;
public:
    virtual ~XmlMultippel() = default;
    void SetMultippel(int multippel);
    int GetMultippel() const;
};

class XmlMultippelHandler : public XmlContentElementHandler<XmlMultippel> {
public:
    XmlMultippelHandler() : XmlContentElementHandler<XmlMultippel>("Multippel") {}
    bool Merge(std::shared_ptr<XmlMultippel> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLMULTIPPEL_H
