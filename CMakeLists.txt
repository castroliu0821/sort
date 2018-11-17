################################################################################
#                          project attribution setting                         #
#[Project / Moudle_type]
#   BINARY      :    execute binary                                            #
#   STATIC      :    static library                                            #
#   SHARED      :    shared library                                            #
################################################################################

SET(PRIVATE_MODULE_NAME  sort-gtest)
SET(PRIVATE_MODULE_TYPE  "BINARY")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "bin")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib")

cmake_minimum_required(VERSION 2.8)

################################################################################
#                   dependent linked third library setting                     #
#CMAKE_CURRENT_SOURCE_DIR   CMakeList.txt's directory                          #
#CMAKE_CURRENT_BINARY_DIR   CMake target directory                             #
################################################################################

SET(PRIVATE_STATIC_LIBRARY
    "pthread"
    "${CMAKE_CURRENT_SOURCE_DIR}/google/lib/libgtest.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/google/lib/libgtest_main.a"
)

LINK_DIRECTORIES(
    "${CMAKE_CURRENT_SOURCE_DIR}/google/lib"
)

# add library, directly add it
LINK_LIBRARIES(${PRIVATE_STATIC_LIBRARY})
# add library, but it's need depend project
#TARGET_LINK_LIBRARIES(${PRIVATE_MODULE_NAME} ${PRIVATE_STATIC_LIBRARY})

################################################################################
#                        complier options setting                              #
################################################################################
SET(CMAKE_CXX_FLAGS "-std=c++11 -pthread -DGTEST_HAS_PTHREAD=1 -std=c++11")
SET(CMAKE_C_FLAGS   "")

################################################################################
#                       header file configurer setting                         #
#  Refs:                                                                       #
#  PROJECT_SOURCE_DIR        : top level source directory                      #
#  CMAKE_CURRENT_BINARY_DIR  : target complie directory                        #
################################################################################
SET(PRIVATE_MODULE_INC_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/google/include/"
    "${CMAKE_CURRENT_SOURCE_DIR}/google/include/gtest"
)

INCLUDE_DIRECTORIES(
    ${PRIVATE_MODULE_INC_PATH}
)

################################################################################
#                       source file configurer setting                         #
#  Refs:                                                                       #
#  PROJECT_SOURCE_DIR      : top level source directory of current project     #
################################################################################
SET(PRIVATE_STATIC_SOURCE
    "${CMAKE_CURRENT_SOURCE_DIR}/quicksort.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/heapsort.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/mergesort.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)

################################################################################
#                           generate project target                            #
################################################################################

project(${PRIVATE_MODULE_NAME})

IF (${PRIVATE_MODULE_TYPE} MATCHES "BINARY")
    ADD_EXECUTABLE(${PRIVATE_MODULE_NAME} ${PRIVATE_STATIC_SOURCE})
ELSEIF (${PRIVATE_MODULE_TYPE} MATCHES "STATIC")
    ADD_LIBRARY(${PRIVATE_MODULE_NAME} STATIC ${PRIVATE_STATIC_SOURCE})
ELSEIF (${PRIVATE_MODULE_TYPE} MATCHES "SHARED")
    ADD_LIBRARY(${PRIVATE_MODULE_NAME} SHARED ${PRIVATE_STATIC_SOURCE})
ELSEIF ()
    MESSAGE (FATAL_ERROR "Sorry target type do not support")
ENDIF ()
