//
// Created by jeo on 12/8/22.
//

#ifndef LEGEMFEST_FESTOBJECTSTREAM_H
#define LEGEMFEST_FESTOBJECTSTREAM_H

#include "libzip_file.h"
#include <memory>
#include <vector>

template <typename T> concept FestSourceStream = requires (T source) {
    { source.read(std::declval<void *>(), std::declval<int>()) } -> std::convertible_to<int>;
};

class FestObjectStream;

class FestObjectStreamSource {
    friend FestObjectStream;
public:
    virtual ~FestObjectStreamSource() = default;
    virtual int read(void *, int) = 0;
};

template <FestSourceStream T> class FestObjectStreamSourceImpl : public FestObjectStreamSource {
private:
    std::shared_ptr<T> source;
public:
    FestObjectStreamSourceImpl(std::shared_ptr<T> source) : source(source) {
    }
    int read(void *buf, int nbytes) override {
        return source->read(buf, nbytes);
    }
};

class Fest;

class FestObjectStream {
private:
    std::unique_ptr<FestObjectStreamSource> source;
    int8_t buf[4096];
public:
    template <FestSourceStream Source> FestObjectStream(std::shared_ptr<Source> source) {
        this->source = std::make_unique<FestObjectStreamSourceImpl<Source>>(source);
    }
    std::shared_ptr<Fest> read();
};


#endif //LEGEMFEST_FESTOBJECTSTREAM_H
