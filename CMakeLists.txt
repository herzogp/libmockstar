cmake_minimum_required(VERSION 3.25)
project(adk-mock VERSION $ENV{version} LANGUAGES C)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in" 
  "${PROJECT_BINARY_DIR}/include/config.h"
  )

# ----------------------------------------
# libmockstar library
#
# Specify -DBUILD_SHARED_LIBS=YES 
# on the cmake command line to create a
# SHARED (.so) library
# ----------------------------------------
add_library(mockstar
  src/version.c
  src/fuzzer.c
  src/coverage.c
  src/utility.c
)

target_include_directories(mockstar 
  PUBLIC 
    include
  PRIVATE 
    "${PROJECT_BINARY_DIR}/include"
)

target_sources(mockstar
  PUBLIC
    FILE_SET mockstar
    TYPE HEADERS
    BASE_DIRS include
    FILES
      include/mockstar/version.h
      include/mockstar/fuzzer.h
      include/mockstar/coverage.h
)

install(TARGETS mockstar FILE_SET mockstar)
