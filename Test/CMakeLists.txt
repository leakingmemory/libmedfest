cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Struct/Packed)

add_executable(serializedeserializetests SerializeDeserializeTests.cpp)
target_include_directories(serializedeserializetests PRIVATE ../include)
target_link_libraries(serializedeserializetests PRIVATE medfest)

add_test(SerializeDeserializeTests serializedeserializetests)
