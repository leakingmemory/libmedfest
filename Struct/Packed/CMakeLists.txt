set(CMAKE_CXX_STANDARD 20)

add_library(packed OBJECT PackException.cpp PackException.h PFestId.cpp PFestId.h PString.cpp PString.h
        FestUuid.cpp FestUuid.h FestUuidList.cpp FestUuidList.h GenericListStorage.h)