cmake_minimum_required(VERSION 3.31)
project(MegaDrive_ROM_Checker)

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)
add_executable(MegaDrive_ROM_Checker ${SOURCE_FILES})

include_directories(MegaDrive_ROM_Checker_lib)
add_subdirectory(MegaDrive_ROM_Checker_lib)
add_subdirectory(Tests)

target_link_libraries(MegaDrive_ROM_Checker MegaDrive_ROM_Checker_lib)
