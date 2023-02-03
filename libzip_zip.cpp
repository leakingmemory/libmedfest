//
// Created by jeo on 12/8/22.
//

#include "libzip_zip.h"
#include "libzip_file.h"
#include "exttype_zip_file.h"
#include <zip.h>

constexpr libzip_zip::libzip_zip() : z(nullptr) {
}

libzip_zip::libzip_zip(const std::string &zipname) {
    int err;
    z = zip_open(zipname.c_str(), ZIP_RDONLY, &err);
}

libzip_zip::~libzip_zip() {
    if (z != nullptr) {
        zip_close(z);
        z = nullptr;
    }
}

constexpr void libzip_zip::swap(libzip_zip &z1, libzip_zip &z2) {
    zip *tmp = z1.z;
    z1.z = z2.z;
    z2.z = tmp;
}

constexpr libzip_zip::libzip_zip(libzip_zip &&mv) : z(mv.z) {
    if (&mv != this) {
        mv.z = nullptr;
    }
}

libzip_zip &libzip_zip::operator=(libzip_zip &&mv) {
    libzip_zip ztmp{std::move(mv)};
    swap(*this, ztmp);
    return *this;
}

int64_t libzip_zip::NumEntries(bool unchanged) {
    if (z == nullptr) {
        return 0;
    }
    zip_flags_t flags{0};
    if (unchanged) {
        flags |= ZIP_FL_UNCHANGED;
    }
    return zip_get_num_entries(z, flags);
}

std::string libzip_zip::Filename(int64_t index) {
    if (z == nullptr) {
        return {};
    }
    const char *cname = zip_get_name(z, index, ZIP_FL_ENC_GUESS);
    if (cname == NULL) {
        return {};
    }
    std::string name{cname};
    return name;
}

std::shared_ptr<libzip_file> libzip_zip::Open(const std::string &filename, bool unchanged) {
    if (z == nullptr) {
        return {};
    }
    zip_flags_t flags{0};
    if (unchanged) {
        flags |= ZIP_FL_UNCHANGED;
    }
    zip_stat_t st;
    if (zip_stat(z, filename.c_str(), flags, &st) != 0) {
        return {};
    }
    zip_file_t *f = zip_fopen(z, filename.c_str(), flags);
    if (f == NULL) {
        return {};
    }
    std::shared_ptr<libzip_zip> ref = shared_from_this();
    return std::shared_ptr<libzip_file>(new libzip_file(ref, exttype_zip_file::create(f), (size_t) st.size));
}