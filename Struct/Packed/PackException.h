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
    PackException(const char *message) : std::exception() {}
    const char * what() const noexcept override;
};


#endif //LEGEMFEST_PACKEXCEPTION_H
