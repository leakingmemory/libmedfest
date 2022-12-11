//
// Created by sigsegv on 12/11/22.
//

#ifndef LEGEMFEST_XMLREFVIRKESTOFF_H
#define LEGEMFEST_XMLREFVIRKESTOFF_H

#include "XmlContentElement.h"
#include <vector>

class XmlRefVirkestoff {
private:
    std::vector<std::string> refs{};
public:
    virtual ~XmlRefVirkestoff() = default;
    void AddRefVirkestoff(const std::string &ref);
    [[nodiscard]] std::vector<std::string> GetRefVirkestoff() const;
};

class XmlRefVirkestoffHandler : public XmlContentElementHandler<XmlRefVirkestoff> {
public:
    XmlRefVirkestoffHandler() : XmlContentElementHandler<XmlRefVirkestoff>("RefVirkestoff") {}
    bool Merge(std::shared_ptr<XmlRefVirkestoff> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFVIRKESTOFF_H
