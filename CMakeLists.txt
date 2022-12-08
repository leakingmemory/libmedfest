cmake_minimum_required(VERSION 3.24)
project(Legemfest)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig)

pkg_check_modules(libzip REQUIRED libzip)

add_executable(decodefest cppmain.cpp cppmain.h decodefest.cpp FestZip.cpp FestZip.h libzip_zip.cpp libzip_zip.h)

target_link_libraries(decodefest ${libzip_LIBRARIES})
