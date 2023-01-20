cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)

add_executable(pstringtest PStingTest.cpp)
target_link_libraries(pstringtest PRIVATE packed)
target_link_libraries(pstringtest PRIVATE decoded)

add_executable(pfestidtest PFestIdTest.cpp)
target_link_libraries(pfestidtest PRIVATE packed)
target_link_libraries(pfestidtest PRIVATE decoded)

add_executable(festuuidlisttest FestUuidListTest.cpp)
target_link_libraries(festuuidlisttest PRIVATE packed)
target_link_libraries(festuuidlisttest PRIVATE decoded)

add_test(PStringTest pstringtest)
add_test(PFestIdTest pfestidtest)
add_test(FestUuidListTest festuuidlisttest)
