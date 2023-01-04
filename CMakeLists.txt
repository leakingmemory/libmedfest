cmake_minimum_required(VERSION 3.24)
project(Legemfest)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(libzip REQUIRED libzip)

find_package(expat REQUIRED)

INCLUDE_DIRECTORIES ( ${EXPAT_INCLUDE_DIRS} )

add_subdirectory(Fest)
add_subdirectory(Struct/Decoded)
add_subdirectory(Struct/Packed)
add_subdirectory(Test/Struct/Packed)

add_executable(decodefest cppmain.cpp cppmain.h decodefest.cpp FestZip.cpp FestZip.h libzip_zip.cpp libzip_zip.h libzip_file.cpp libzip_file.h exttype_zip_file.h FestObjectStream.cpp FestObjectStream.h XMLParser.cpp XMLParser.h)

target_link_libraries(decodefest fest)
target_link_libraries(decodefest decoded)
target_link_libraries(decodefest -lexpat)
target_link_libraries(decodefest ${libzip_LIBRARIES})
