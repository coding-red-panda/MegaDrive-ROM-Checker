project(MegaDrive_ROM_Checker_lib)

set(HEADER_FILES
        rom.h
        support/Copyright.cpp
        support/Copyright.h
)

set(SOURCE_FILES
        rom.cpp
        support/Copyright.cpp
        support/Copyright.h
)

add_library(MegaDrive_ROM_Checker_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})
