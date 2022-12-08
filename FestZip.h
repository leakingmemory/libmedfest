//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_FESTZIP_H
#define LEGEMFEST_FESTZIP_H

#include <memory>

class libzip_zip;

class FestZip {
private:
    std::shared_ptr<libzip_zip> z;
public:
    explicit FestZip(const std::string &zipname);
    void Decode();
};


#endif //LEGEMFEST_FESTZIP_H
