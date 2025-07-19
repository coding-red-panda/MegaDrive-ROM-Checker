project(MegaDrive_ROM_Checker_lib)

set(HEADER_FILES
        rom.h
        support/Copyright.cpp
        support/Copyright.h
        support/Util.cpp
        support/Util.h
        support/SerialNumber.cpp
        support/SerialNumber.h
)

set(SOURCE_FILES
        rom.cpp
        support/Copyright.cpp
        support/Copyright.h
        support/Util.cpp
        support/Util.h
        support/SerialNumber.cpp
        support/SerialNumber.h
)

add_library(MegaDrive_ROM_Checker_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})
