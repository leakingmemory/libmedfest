cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)

add_executable(pstringtest PStingTest.cpp)
target_include_directories(pstringtest PRIVATE ../../../include)
target_link_libraries(pstringtest PRIVATE medfest)

add_executable(pfestidtest PFestIdTest.cpp)
target_include_directories(pfestidtest PRIVATE ../../../include)
target_link_libraries(pfestidtest PRIVATE medfest)
target_include_directories(pfestidtest PRIVATE ../../../include)

add_executable(festuuidlisttest FestUuidListTest.cpp)
target_include_directories(festuuidlisttest PRIVATE ../../../include)
target_link_libraries(festuuidlisttest PRIVATE medfest)

add_test(PStringTest pstringtest)
add_test(PFestIdTest pfestidtest)
add_test(FestUuidListTest festuuidlisttest)
