//
// Created by jeo on 12/8/22.
//

#include "libzip_file.h"
#include "libzip_zip.h"
#include "exttype_zip_file.h"
#include <zip.h>

libzip_file::libzip_file() : archive(), file(nullptr), fsize(0) {
}

libzip_file::libzip_file(const std::shared_ptr<libzip_zip> &archive, exttype_zip_file *file, int fsize) : archive(archive), file(file), fsize(fsize) {
}

void libzip_file::swap(libzip_file &f1, libzip_file &f2) {
    auto f1_archive = f1.archive;
    auto f1_file = f1.file;
    f1.archive = f2.archive;
    f1.file = f2.file;
    f2.archive = f1_archive;
    f2.file = f1_file;
}

libzip_file::~libzip_file() {
    if (file != nullptr) {
        zip_fclose(file->native());
        file = nullptr;
    }
}

libzip_file::libzip_file(libzip_file &&mv) : archive(mv.archive), file(mv.file) {
    if (&mv != this) {
        mv.archive = {};
        mv.file = nullptr;
    }
}

libzip_file &libzip_file::operator=(libzip_file &&mv) {
    libzip_file tmp{std::move(mv)};
    swap(*this, tmp);
    return *this;
}

int libzip_file::read(void *buf, int nbytes) {
    if (file == nullptr) {
        return -1;
    }
    return (int) zip_fread(file->native(), buf, nbytes);
}

size_t libzip_file::size() {
    if (file == nullptr) {
        return -1;
    }
    return fsize;
}
