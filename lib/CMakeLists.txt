project(MegaDrive_ROM_Checker_lib)

set(HEADER_FILES
        Rom.h
        support/copyright.cpp
        support/copyright.h
        support/util.cpp
        support/util.h
        support/serial_number.cpp
        support/serial_number.h
        support/addresses.h
        support/device_support.cpp
        support/device_support.h
        support/devices.h
)

set(SOURCE_FILES
        Rom.cpp
        support/copyright.cpp
        support/copyright.h
        support/util.cpp
        support/util.h
        support/serial_number.cpp
        support/serial_number.h
        support/device_support.cpp
        support/device_support.h
)

add_library(MegaDrive_ROM_Checker_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})
