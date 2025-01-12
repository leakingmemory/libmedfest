//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_FESTZIP_H
#define LEGEMFEST_FESTZIP_H

#include <memory>
#include <string>

class libzip_zip;
class libzip_file;
class Fest;

class FestZip {
private:
    std::shared_ptr<libzip_zip> z;
public:
    explicit FestZip(const std::string &zipname);
    std::shared_ptr<libzip_file> GetXmlFile();
    std::shared_ptr<Fest> Decode();
};


#endif //LEGEMFEST_FESTZIP_H
