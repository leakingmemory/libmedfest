//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLREFVIRKESTOFFMEDSTYRKE_H
#define LEGEMFEST_XMLREFVIRKESTOFFMEDSTYRKE_H

#include "XmlContentElement.h"
#include <vector>

class XmlRefVirkestoffMedStyrke {
private:
    std::vector<std::string> refs{};
public:
    virtual ~XmlRefVirkestoffMedStyrke() = default;
    void AddRefVirkestoffMedStyrke(const std::string &ref);
    [[nodiscard]] std::vector<std::string> GetRefVirkestoffMedStyrke() const;
};

class XmlRefVirkestoffMedStyrkeHandler : public XmlContentElementHandler<XmlRefVirkestoffMedStyrke> {
public:
    XmlRefVirkestoffMedStyrkeHandler() : XmlContentElementHandler<XmlRefVirkestoffMedStyrke>("RefVirkestoffMedStyrke") {}
    bool Merge(std::shared_ptr<XmlRefVirkestoffMedStyrke> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFVIRKESTOFFMEDSTYRKE_H
