//
// Created by sigsegv on 2/20/26.
//

#ifndef LIBMEDFEST_FESTDESERIALIZERMAPPING_H
#define LIBMEDFEST_FESTDESERIALIZERMAPPING_H

class FestDeserializer;
class FestDeserializer_0;
class FestDeserializer_1;

class FestDeserializerMapping {
    friend FestDeserializer;
    friend FestDeserializer_0;
    friend FestDeserializer_1;
private:
    void *mapping;
    size_t mapsize;
public:
    FestDeserializerMapping(const std::string &filename);
    FestDeserializerMapping(const void *data, size_t size);
    ~FestDeserializerMapping();
};

#endif //LIBMEDFEST_FESTDESERIALIZERMAPPING_H