cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SparkleDummyProject)

find_package(Sparkle REQUIRED)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/srcs)

file(GLOB_RECURSE HEADERS
    ${INCLUDE_DIR}/*.hpp
    ${INCLUDE_DIR}/*.h
)
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

add_executable(SparkleDummyProject ${SOURCES} ${HEADERS})

target_link_libraries(SparkleDummyProject PRIVATE Sparkle::Sparkle)

target_include_directories(SparkleDummyProject
    PRIVATE
        ${INCLUDE_DIR}
)

set_target_properties(SparkleDummyProject PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/${ARCH_FOLDER}
)
