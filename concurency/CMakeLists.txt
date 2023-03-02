project(concurency)
set(CMAKE_CXX_STANDARD 20)
add_executable(concurency main.cpp ExpirationCache.cpp thread_pull.cpp)
add_executable(test CheckSleep.cpp)