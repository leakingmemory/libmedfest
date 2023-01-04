//
// Created by sigsegv on 1/3/23.
//

#include "FestUuid.h"
#include "PackException.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <cctype>

FestUuid::FestUuid(const std::string &id) {
    if (!id.starts_with("ID_")) {
        throw PackException("Id expected to start with ID_");
    }
    std::string str{id};
    str.erase(0, 3);
    boost::uuids::string_generator gen{};
    boost::uuids::uuid uuid = gen(str);
    if constexpr(uuid.size() != sizeof(this->id)) {
        throw PackException("Incorrect uuid size");
    }
    std::copy(uuid.begin(), uuid.end(), &(this->id[0]));
}

std::string FestUuid::ToString() const {
    boost::uuids::uuid uuid{};
    std::copy(&(id[0]), &(id[uuid_size]), uuid.begin());
    std::string str{"ID_"};
    str.append(boost::lexical_cast<std::string>(uuid));
    std::transform(str.begin(), str.end(), str.begin(), [] (char ch) {return std::toupper(ch);});
    return str;
}
