//
// Created by sigsegv on 12/25/22.
//

#ifndef LEGEMFEST_XMLREFVILKAR_H
#define LEGEMFEST_XMLREFVILKAR_H

#include "XmlContentElement.h"
#include <vector>
#include <string>

class XmlRefVilkar {
private:
    std::vector<std::string> refVilkar{};
public:
    virtual ~XmlRefVilkar() = default;
    [[nodiscard]] std::vector<std::string> GetRefVilkar() const;
    void AddRefVilkar(const std::string &refVilkar);
};

class XmlRefVilkarHandler : public XmlContentElementHandler<XmlRefVilkar> {
public:
    XmlRefVilkarHandler() : XmlContentElementHandler<XmlRefVilkar>("RefVilkar") {}
    bool Merge(std::shared_ptr<XmlRefVilkar> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFVILKAR_H
