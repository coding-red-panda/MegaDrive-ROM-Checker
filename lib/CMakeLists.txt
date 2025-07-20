project(MegaDrive_ROM_Checker_lib)

set(HEADER_FILES
        Rom.h
        support/Copyright.cpp
        support/Copyright.h
        support/Util.cpp
        support/Util.h
        support/serial_number.cpp
        support/serial_number.h
        addresses.h
)

set(SOURCE_FILES
        Rom.cpp
        support/Copyright.cpp
        support/Copyright.h
        support/Util.cpp
        support/Util.h
        support/serial_number.cpp
        support/serial_number.h
)

add_library(MegaDrive_ROM_Checker_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})
