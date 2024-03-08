//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_XMLPARSER_H
#define LEGEMFEST_XMLPARSER_H

#include <expat.h>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <iostream>
#include <Fest/XMLObject.h>

template <typename T> concept XMLObjectHandler = requires (T handler) {
    { handler.StartElement(std::declval<std::shared_ptr<XMLObject>>(), std::declval<const std::map<std::string,std::string>>()) } -> std::convertible_to<std::shared_ptr<XMLObject>>;
    { handler.EndElement(std::declval<const std::shared_ptr<XMLObject>>()) } -> std::convertible_to<bool>;
};

class XMLObjectHandlerInterface {
public:
    virtual ~XMLObjectHandlerInterface() = default;
    virtual std::shared_ptr<XMLObject> StartElement(std::shared_ptr<XMLObject> parent, const std::map<std::string,std::string> &attributes) = 0;
    virtual bool EndElement(const std::shared_ptr<XMLObject> &obj) = 0;
};

template <XMLObjectHandler Handler> class XMLObjectHandlerGlue : public XMLObjectHandlerInterface{
private:
    std::shared_ptr<Handler> handler;
public:
    XMLObjectHandlerGlue(const std::shared_ptr<Handler> &handler) : handler(handler) {}
    std::shared_ptr<XMLObject> StartElement(std::shared_ptr<XMLObject> parent, const std::map<std::string,std::string> &attributes) override {
        return handler->StartElement(parent, attributes);
    }
    bool EndElement(const std::shared_ptr<XMLObject> &obj) override {
        return handler->EndElement(obj);
    }
};

class XMLParser {
private:
    XML_Parser parser;
    std::map<std::string,std::shared_ptr<XMLObjectHandlerInterface>> handlers;
    std::vector<std::shared_ptr<XMLObject>> trail;
    std::vector<std::shared_ptr<XMLObject>> roots;
    bool stop;
public:
    XMLParser();
    ~XMLParser();
    XMLParser(const XMLParser &) = delete;
    XMLParser(XMLParser &&) = delete;
    XMLParser &operator = (const XMLParser &) = delete;
    XMLParser &operator = (XMLParser &&) = delete;

    template <XMLObjectHandler Handler> void AddHandler(const std::string &name, const std::shared_ptr<Handler> &handler) {
        std::shared_ptr<XMLObjectHandlerInterface> interface = std::make_shared<XMLObjectHandlerGlue<Handler>>(handler);
        handlers.insert_or_assign(name, interface);
    }

    std::shared_ptr<XMLObjectHandlerInterface> GetHandler(const std::string &name);
    void StartElement(const std::string &name, const std::map<std::string,std::string> &attributes);
    void EndElement(const std::string &name);
    void CharacterData(const std::string &charData);

    bool ParseBuffer(const void *buf, int len, bool lastBuffer);

    template <class T> std::shared_ptr<T> GetRoot() {
        bool found = false;
        std::shared_ptr<T> root = {};
        for (auto potentialRoot : roots) {
            std::shared_ptr<T> typedRoot = std::dynamic_pointer_cast<T>(potentialRoot);
            if (typedRoot) {
                if (found) {
                    std::cerr << "Error: Duplicate roots\n";
                    return {};
                }
                found = true;
                root = typedRoot;
            }
        }
        return root;
    }
};


#endif //LEGEMFEST_XMLPARSER_H
