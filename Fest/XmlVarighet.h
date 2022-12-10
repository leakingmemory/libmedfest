//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLVARIGHET_H
#define LEGEMFEST_XMLVARIGHET_H

#include "XmlContentElement.h"

class XmlVarighet {
private:
    std::string varighet;
public:
    virtual ~XmlVarighet() = default;
    void SetVarighet(const std::string &varighet);
    [[nodiscard]] std::string GetVarighet() const;
};

class XmlVarighetHandler : public XmlContentElementHandler<XmlVarighet> {
public:
    XmlVarighetHandler() : XmlContentElementHandler<XmlVarighet>("Varighet") {}
    bool Merge(std::shared_ptr<XmlVarighet> parent, const std::string &content) override;
};


#endif //LEGEMFEST_XMLVARIGHET_H
