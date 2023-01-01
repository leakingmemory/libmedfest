//
// Created by sigsegv on 12/30/22.
//

#ifndef LEGEMFEST_XMLBESKRIVELSETERM_H
#define LEGEMFEST_XMLBESKRIVELSETERM_H

#include "XmlContentElement.h"

class XmlBeskrivelseTerm {
private:
    std::string beskrivelseTerm{};
public:
    virtual ~XmlBeskrivelseTerm() = default;
    void SetBeskrivelseTerm(const std::string &beskrivelseTerm);
    [[nodiscard]] std::string GetBeskrivelseTerm() const;
};

class XmlBeskrivelseTermHandler : public XmlContentElementHandler<XmlBeskrivelseTerm> {
public:
    XmlBeskrivelseTermHandler() : XmlContentElementHandler<XmlBeskrivelseTerm>("BeskrivelseTerm") {}
    bool Merge(std::shared_ptr<XmlBeskrivelseTerm> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLBESKRIVELSETERM_H
