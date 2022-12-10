//
// Created by sigsegv on 12/10/22.
//

#ifndef LEGEMFEST_XMLSORTERING_H
#define LEGEMFEST_XMLSORTERING_H

#include "XmlContentElement.h"

template <typename T> concept XmlSorterbarIterator = requires (T iter) {
    { iter->GetSortering() } -> std::convertible_to<int>;
    { ++iter } -> std::convertible_to<typeof(iter)>;
};

template <typename T> concept PointerXmlSorterbarIterator = requires (T iter) {
    { (*iter)->GetSortering() } -> std::convertible_to<int>;
    { ++iter } -> std::convertible_to<typeof(iter)>;
};

class XmlSortering {
private:
    int sortering{0};
public:
    virtual ~XmlSortering() = default;
    int GetSortering() const;
    void SetSortering(int sortering);

    template <XmlSorterbarIterator IterableType> static void Sort(IterableType start, IterableType end) {
        std::sort(start, end, [] (auto a, auto b) {
            return a.GetSortering() < b.GetSortering();
        });
    }
    template <PointerXmlSorterbarIterator IterableType> static void Sort(IterableType start, IterableType end) {
        std::sort(start, end, [] (const auto &a, const auto &b) {
            return a->GetSortering() < b->GetSortering();
        });
    }
};

class XmlSorteringHandler : public XmlContentElementHandler<XmlSortering> {
public:
    XmlSorteringHandler() : XmlContentElementHandler<XmlSortering>("Sortering") {}
    bool Merge(std::shared_ptr<XmlSortering> parent, const std::string &content) override;
};

#endif //LEGEMFEST_XMLSORTERING_H
