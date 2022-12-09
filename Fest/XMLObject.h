//
// Created by sigsegv on 12/8/22.
//

#ifndef LEGEMFEST_XMLOBJECT_H
#define LEGEMFEST_XMLOBJECT_H

#include <string>

class XMLObject {
public:
    virtual ~XMLObject() = default;
    virtual std::string GetName() = 0;
    virtual bool AppendCharacterData(const std::string &charData) {
        return false;
    }
};

#endif //LEGEMFEST_XMLOBJECT_H
