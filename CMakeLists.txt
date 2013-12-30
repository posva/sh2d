cmake_minimum_required(VERSION 2.6)
project(sh2d)

# set soem options
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -std=c99 -g")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -Wextra -O2 -std=c99")
set(CMAKE_BUILD_TYPE Release)

set(SRC ${PROJECT_SOURCE_DIR}/src)
set(EXC ${PROJECT_SOURCE_DIR}/exc)

# Include dir for the exc
include_directories(${SRC})

set(EXECUTABLE_OUTPUT_PATH bin)

# find files
file(GLOB_RECURSE source_files ${SRC}/*)

# catimg executable
add_executable(
  catimg
  ${EXC}/catimg.c
  ${SRC}/sh_color.c
  ${SRC}/sh_color.h
  ${SRC}/sh_image.c
  ${SRC}/sh_image.h
  ${SRC}/sh_utils.c
  ${SRC}/sh_utils.h
  ${SRC}/stb_image.c
  ${SRC}/stb_image.h
  )

# Testing executable
add_executable(
  sh2d
  ${EXC}/main.c
  ${source_files}
  )

# libs
target_link_libraries(catimg m)

# tests
enable_testing()
add_test(tcatimg ${PROJECT_SOURCE_DIR}/tests/tcatimg.sh)

# Doc

find_package(Doxygen)
if(DOXYGEN_FOUND)
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
