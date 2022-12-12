//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_XMLREFLEGEMIDDELMERKEVARE_H
#define LEGEMFEST_XMLREFLEGEMIDDELMERKEVARE_H

#include "XMLObject.h"
#include "XmlContentElement.h"
#include <vector>

class XmlRefLegemiddelMerkevare {
private:
    std::vector<std::string> refs{};
public:
    virtual ~XmlRefLegemiddelMerkevare() = default;
    void AddRefLegemiddelMerkevare(const std::string &ref);
    [[nodiscard]] std::vector<std::string> GetRefLegemiddelMerkevare() const;
};

class XmlRefLegemiddelMerkevareHandler : public XmlContentElementHandler<XmlRefLegemiddelMerkevare> {
public:
    XmlRefLegemiddelMerkevareHandler() : XmlContentElementHandler<XmlRefLegemiddelMerkevare>("RefLegemiddelMerkevare") {}
    bool Merge(std::shared_ptr<XmlRefLegemiddelMerkevare> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLREFLEGEMIDDELMERKEVARE_H
