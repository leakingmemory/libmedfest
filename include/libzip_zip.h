//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_LIBZIP_ZIP_H
#define LEGEMFEST_LIBZIP_ZIP_H

#include <string>
#include <memory>

class zip;
class libzip_file;

class libzip_zip : public std::enable_shared_from_this<libzip_zip> {
private:
    zip *z;
    static constexpr void swap(libzip_zip &, libzip_zip &);
    constexpr libzip_zip();
    explicit libzip_zip(const std::string &zipname);
public:
    template <typename... TArgs> [[nodiscard]] static std::shared_ptr<libzip_zip> Create(TArgs&&... args) {
        return std::shared_ptr<libzip_zip>(new libzip_zip(args...));
    }
    ~libzip_zip();
    libzip_zip(const libzip_zip &) = delete;
    libzip_zip &operator = (const libzip_zip &) = delete;
    constexpr libzip_zip(libzip_zip &&);
    libzip_zip &operator =(libzip_zip &&);

    int64_t NumEntries(bool unchanged = true);
    std::string Filename(int64_t index);
    std::shared_ptr<libzip_file> Open(const std::string &filename, bool unchanged = true);
};


#endif //LEGEMFEST_LIBZIP_ZIP_H
