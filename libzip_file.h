//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_LIBZIP_FILE_H
#define LEGEMFEST_LIBZIP_FILE_H

#include <memory>

class libzip_zip;
class exttype_zip_file;

class libzip_file {
    friend libzip_zip;
private:
    std::shared_ptr<libzip_zip> archive;
    exttype_zip_file *file;

    libzip_file();
    libzip_file(const std::shared_ptr<libzip_zip> &archive, exttype_zip_file *file);
    static void swap(libzip_file &, libzip_file &);
public:
    ~libzip_file();
    libzip_file(const libzip_file &) = delete;
    libzip_file &operator =(const libzip_file &) = delete;
    libzip_file(libzip_file &&);
    libzip_file &operator =(libzip_file &&);
};


#endif //LEGEMFEST_LIBZIP_FILE_H
