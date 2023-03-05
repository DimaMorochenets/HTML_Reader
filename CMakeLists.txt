cmake_minimum_required(VERSION 3.24)

project(HTML_Reader VERSION 0.0.1 LANGUAGES CXX)

set(EXECUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES_DIR ${PROJECT_SOURCE_DIR}/sources)
set(SRC_DIR     ${SOURCES_DIR}/src)
set(INCLUDE_DIR ${SOURCES_DIR}/include)

set(SOURCE_FILES 
    ${SRC_DIR}/Page/Head.cpp
    ${SRC_DIR}/Page/Page.cpp
    ${SRC_DIR}/Reader.cpp
    ${SRC_DIR}/main.cpp)

set(HEADER_FILES
    ${INCLUDE_DIR}/Page/Common.h
    ${INCLUDE_DIR}/Page/Head.h
    ${INCLUDE_DIR}/Page/Page.h
    ${INCLUDE_DIR}/Reader.h)

add_executable(${EXECUT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(${EXECUT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${EXECUT_NAME} PRIVATE ${INCLUDE_DIR} ${INCLUDE_DIR}/Page)
