CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Turn it on through: -Dtest=ON
OPTION(test "Include Tests." OFF)

# Project definition
SET(PROJECT_NAME hpos)
PROJECT(${PROJECT_NAME} C CXX)

INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
IF(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF(COMPILER_SUPPORTS_CXX0X)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ELSE()
    MESSAGE(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
    MESSAGE(STATUS "Please use a different C++ compiler.")
ENDIF()

SET(CMAKE_THREAD_PREFER_PTHREAD TRUE)
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/lib/modules/)
SET(${PROJECT_NAME}_VERSION_MAJOR 0)
SET(${PROJECT_NAME}_VERSION_MINOR 1)

# Linux Mint 17 seems to fail by only providing lpthread.
# See the difference between providing the lib only and
# pthread:
# http://stackoverflow.com/questions/875789/gcc-do-i-need-d-reentrant-with-pthreads
SET(CMAKE_LINKER_FLAGS "-pthread" CACHE STRING "Linker Flags" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_LINKER_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS}" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_LINKER_FLAGS}" CACHE STRING "" FORCE)

FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(GMP REQUIRED)
INCLUDE_DIRECTORIES(${GMP_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

ADD_SUBDIRECTORY(src/)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

# TESTING
IF (test)
    ADD_SUBDIRECTORY(lib/gtest-1.6.0)
    ENABLE_TESTING()
    INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    # Our test source
    ADD_SUBDIRECTORY(tests/)
ENDIF (test)

