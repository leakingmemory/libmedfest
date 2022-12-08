//
// Created by jeo on 12/8/22.
//

#include <iostream>
#include "cppmain.h"
#include "FestZip.h"

int DecodeFest(const std::string &zipname) {
    FestZip festzip{zipname};
    festzip.Decode();
}

int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <fest.zip>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        return usage(cmd);
    }
    const std::string &festZip = args.at(0);
    return DecodeFest(festZip);
}