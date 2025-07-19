project(Tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define the source files for the tests
add_executable(Tests_run_all RomTests.cpp
        Support_UtilTests.cpp
        Support_SerialNumberTests.cpp)

# Copy resources needed for tests
# This is a custom target that copies the resources directory to the build output directory
# so that the tests can access the necessary files.
add_custom_target(copy_data
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/resources/"
        "$<TARGET_FILE_DIR:Tests_run_all>/resources/"
        COMMENT "Copying testing data"
)
add_dependencies(Tests_run_all copy_data)

# Invoke the linker to create the final executable
# Link against the Google Test libraries and the MegaDrive ROM Checker library
target_link_libraries(Tests_run_all MegaDrive_ROM_Checker_lib)
target_link_libraries(Tests_run_all gtest gtest_main)
