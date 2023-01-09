cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)

add_executable(pstringtest PStingTest.cpp)
target_link_libraries(pstringtest PRIVATE packed)

add_executable(pfestidtest PFestIdTest.cpp)
target_link_libraries(pfestidtest PRIVATE packed)

add_executable(festuuidlisttest FestUuidListTest.cpp)
target_link_libraries(festuuidlisttest PRIVATE packed)

add_test(PStringTest COMMAND pstringtest)
add_test(PFestIdTest COMMAND pfestidtest)
add_test(FestUuidListTest COMMAND festuuidlisttest)
