//
// Created by sigsegv on 1/2/23.
//

#ifndef LEGEMFEST_PACKEXCEPTION_H
#define LEGEMFEST_PACKEXCEPTION_H

#include <exception>

class PackException : public std::exception {
private:
    const char *message;
public:
    PackException() : std::exception(), message(nullptr) {}
    PackException(const char *message) : std::exception(), message(message) {}
    PackException(const PackException &) = default;
    PackException(PackException &&) = default;
    PackException &operator =(const PackException &) = default;
    PackException &operator =(PackException &&) = default;
    const char * what() const noexcept override;
};


#endif //LEGEMFEST_PACKEXCEPTION_H
