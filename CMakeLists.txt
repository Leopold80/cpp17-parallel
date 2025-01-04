cmake_minimum_required(VERSION 2.8)

project(cpp-multithread)

# <execution>需要
find_package(TBB REQUIRED)

#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/inc)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)

add_executable(cpp-par ${SRCS})

target_link_libraries(cpp-par PUBLIC TBB::tbb)

set_target_properties(cpp-par PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
