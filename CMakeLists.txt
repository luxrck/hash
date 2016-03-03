project(libmule)
cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS system filesystem REQUIRED)

add_library(libevent SHARED IMPORTED)
#add_library(libevent_extra SHARED IMPORTED)
#add_library(libevent_pthread SHARED IMPORTED)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb -std=c11")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall -std=c11")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb -std=c++11 -levent")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall -std=c++11")


aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${IMPORTED_IMPLIB_RELEASE})
