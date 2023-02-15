project(algorithm)
set(CMAKE_CXX_STANDARD 20)
add_executable(algorithm main.cpp)
target_include_directories(algorithm PUBLIC ${Gtest_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/utility/")