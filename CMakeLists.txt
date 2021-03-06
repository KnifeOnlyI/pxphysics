cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME pxphysics)
set(PROJECT_DESCRIPTION "${PROJECT_NAME}")
set(PROJECT_VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION})

file(
    GLOB_RECURSE
    SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/core/source/*.c
    ${CMAKE_CURRENT_LIST_DIR}/core/source/*.cpp
)

file(
    GLOB_RECURSE
    HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/core/header/*.h
    ${CMAKE_CURRENT_LIST_DIR}/core/header/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/core/header/*.inl
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    file(
        GLOB_RECURSE
        SOURCES_TEST
        ${CMAKE_CURRENT_LIST_DIR}/test/source/*.c
        ${CMAKE_CURRENT_LIST_DIR}/test/source/*.cpp
    )

    file(
        GLOB_RECURSE
        HEADERS_TEST
        ${CMAKE_CURRENT_LIST_DIR}/test/header/*.h
        ${CMAKE_CURRENT_LIST_DIR}/test/header/*.hpp
        ${CMAKE_CURRENT_LIST_DIR}/test/header/*.inl
    )

    add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES_TEST} ${HEADERS} ${HEADERS_TEST})
else ()
    add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
endif ()

include_directories(${CMAKE_CURRENT_LIST_DIR}/core/header)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})