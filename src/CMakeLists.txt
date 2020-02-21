cmake_minimum_required(VERSION 3.0)

include (FindPkgConfig)

pkg_check_modules (GLIB REQUIRED glib-2.0>=2.42)

option (ENABLE_TESTS "Build tests along with the library" ON)
enable_testing()

include_directories (${GLIB_INCLUDE_DIRS})

set (MAJOR_VERSION 0)
set (MINOR_VERSION 9)
set (VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION})

set (LIBYENILMEZ_VERSION ${VERSION_STRING})
set(YENILMEZ_FILES collector.c assertion.c colors.c yenilmez.c sighands.c counters.c)
set(YENILMEZ_HEADERS assertion.h counters.h yenilmez.h)

add_library(yenilmez_shared SHARED ${YENILMEZ_FILES} ${YENILMEZ_HEADERS})

set_target_properties (yenilmez_shared PROPERTIES OUTPUT_NAME "yenilmez")
set_target_properties (yenilmez_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties (yenilmez_shared PROPERTIES SOVERSION "${VERSION_STRING}")
set_target_properties (yenilmez_shared PROPERTIES VERSION "${VERSION_STRING}")
set_target_properties (yenilmez_shared PROPERTIES PUBLIC_HEADER "${YENILMEZ_HEADERS}")

target_link_libraries (yenilmez_shared
        ${GLIB_LDFLAGS} ${GCRYPT_LDFLAGS}
        ${EXECINFO_LDFLAGS}
        ${LINKER_HARDENING_FLAGS} ${CMAKE_DL_LIBS}
        )

install (TARGETS yenilmez_shared
        RUNTIME DESTINATION ${BINDIR}
        LIBRARY DESTINATION ${LIBDIR}
        ARCHIVE DESTINATION ${LIBDIR}
        PUBLIC_HEADER DESTINATION ${INCLUDEDIR}/yenilmez
        )

configure_file (libyenilmez.pc.in ${CMAKE_BINARY_DIR}/libyenilmez.pc @ONLY)
install (FILES ${CMAKE_BINARY_DIR}/libyenilmez.pc
        DESTINATION ${LIBDIR}/pkgconfig)
