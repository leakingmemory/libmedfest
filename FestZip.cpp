//
// Created by jeo on 12/8/22.
//

#include "FestZip.h"
#include "libzip_zip.h"
#include "FestObjectStream.h"
#include <iostream>

FestZip::FestZip(const std::string &zipname) {
    z = libzip_zip::Create(zipname);
}

std::shared_ptr<libzip_file> FestZip::GetXmlFile() {
    std::string xmlname{};
    {
        auto num = z->NumEntries();
        for (typeof(num) i = 0; i < num; i++) {
            std::string filename = z->Filename(i);
            {
                std::string filename_lower{filename};
                std::transform(filename_lower.begin(), filename_lower.end(), filename_lower.begin(),
                               [](auto ch) { return std::tolower(ch); });
                if (filename_lower.ends_with(".xml")) {
                    if (!xmlname.empty()) {
                        return {};
                    }
                    xmlname = filename;
                }
            }
        }
    }
    if (xmlname.empty()) {
        return {};
    }
    return z->Open(xmlname);
}

void FestZip::Decode() {
    auto file = GetXmlFile();
    if (!file) {
        std::cerr << "Error: Couldn't find xml file inside the zip archive\n";
    }
    FestObjectStream inputStream{file};
    inputStream.read();
}
