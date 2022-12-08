//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_EXTTYPE_ZIP_FILE_H
#define LEGEMFEST_EXTTYPE_ZIP_FILE_H

#include <zip.h>

class exttype_zip_file {
public:
    exttype_zip_file() = delete;
    ~exttype_zip_file() = delete;
    exttype_zip_file(const exttype_zip_file &) = delete;
    exttype_zip_file(exttype_zip_file &&) = delete;
    exttype_zip_file &operator =(const exttype_zip_file &) = delete;
    exttype_zip_file &operator =(exttype_zip_file &&) = delete;

    static exttype_zip_file *create(zip_file_t *zipFile) {
        return (exttype_zip_file *) zipFile;
    }
    zip_file_t * native() const {
        return (zip_file_t *) this;
    };
};


#endif //LEGEMFEST_EXTTYPE_ZIP_FILE_H
