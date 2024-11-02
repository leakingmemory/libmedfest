cmake_minimum_required(VERSION 3.24)
project(Libmedfest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-fPIC)

find_package(PkgConfig)

pkg_check_modules(libzip REQUIRED libzip)

find_package(expat REQUIRED)

find_package(Boost REQUIRED)

INCLUDE_DIRECTORIES ( ${EXPAT_INCLUDE_DIRS} )

enable_testing()

add_subdirectory(Fest)
add_subdirectory(Struct/Decoded)
add_subdirectory(Struct/Packed)
add_subdirectory(Test)

add_library(medfest SHARED FestZip.cpp libzip_zip.cpp libzip_file.cpp FestObjectStream.cpp XMLParser.cpp
        FestSerializer.cpp FestDeserializer.cpp FestVectors.cpp FestDeserializer_Preload.cpp)
set_target_properties(medfest PROPERTIES SOVERSION 8 VERSION 8.0.0)
include_directories(medfest include)
include_directories(medfest ${libzip_INCLUDE_DIRS} )

IF(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
   target_link_libraries(medfest -L/usr/local/lib)
ENDIF(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")

target_link_libraries(medfest fest)
target_link_libraries(medfest decoded)
target_link_libraries(medfest packed)
target_link_libraries(medfest -lexpat)
target_link_libraries(medfest ${libzip_LIBRARIES})

install(TARGETS medfest
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include/medfest)

