//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_LIBZIP_ZIP_H
#define LEGEMFEST_LIBZIP_ZIP_H

#include <string>

class zip;

class libzip_zip {
private:
    zip *z;
    static constexpr void swap(libzip_zip &, libzip_zip &);
public:
    constexpr libzip_zip();
    explicit libzip_zip(const std::string &zipname);
    ~libzip_zip();
    libzip_zip(const libzip_zip &) = delete;
    libzip_zip &operator = (const libzip_zip &) = delete;
    constexpr libzip_zip(libzip_zip &&);
    libzip_zip &operator =(libzip_zip &&);

    int64_t NumEntries(bool unchanged = true);
    std::string Filename(int64_t index);
};


#endif //LEGEMFEST_LIBZIP_ZIP_H
