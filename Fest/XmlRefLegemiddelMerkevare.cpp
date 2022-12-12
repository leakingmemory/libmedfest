//
// Created by sigsegv on 12/12/22.
//

#include "XmlRefLegemiddelMerkevare.h"

void XmlRefLegemiddelMerkevare::AddRefLegemiddelMerkevare(const std::string &ref) {
    refs.push_back(ref);
}

std::vector<std::string> XmlRefLegemiddelMerkevare::GetRefLegemiddelMerkevare() const {
    return refs;
}

bool
XmlRefLegemiddelMerkevareHandler::Merge(std::shared_ptr<XmlRefLegemiddelMerkevare> parent, const std::string &content) {
    parent->AddRefLegemiddelMerkevare(content);
    return true;
}