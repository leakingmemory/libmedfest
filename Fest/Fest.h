//
// Created by sigsegv on 12/8/22.
//

#ifndef LEGEMFEST_FEST_H
#define LEGEMFEST_FEST_H

#include "XMLObject.h"
#include <memory>
#include <vector>

class Fest;

class HentetDato : public XMLObject {
private:
    std::shared_ptr<Fest> fest;
    std::string date;
public:
    HentetDato(std::shared_ptr<Fest> fest) : fest(fest) {}
    std::string GetName() override;
    bool AppendCharacterData(const std::string &charData) override;
    void Merge();
};

class Fest : public XMLObject {
private:
    std::string hentetDato;
public:
    std::string GetName() override;
    void SetHentetDato(const std::string &hentetDato) {
        this->hentetDato = hentetDato;
    }
    std::string GetHentetDato() {
        return hentetDato;
    }
};

class FestHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

class HentetDatoHandler {
public:
    std::shared_ptr<XMLObject> StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes);
    bool EndElement(const std::shared_ptr<XMLObject> &obj);
};

#endif //LEGEMFEST_FEST_H
