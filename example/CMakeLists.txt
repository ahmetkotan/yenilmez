cmake_minimum_required(VERSION 3.0)
project(yenexample C)

set(CMAKE_C_STANDARD 99)

include (FindPkgConfig)
pkg_check_modules (LIBYEN REQUIRED libyenilmez)

include_directories (${LIBYEN_INCLUDE_DIRS})
add_executable (yenexample yenexample.c)
target_link_libraries (yenexample ${LIBYEN_LDFLAGS})
