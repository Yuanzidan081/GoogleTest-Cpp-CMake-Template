cmake_minimum_required(VERSION 3.20)
project(googleTest-Cpp-Template)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL "${PROJECT_SOURCE_DIR}/dep/googletest-5376968f6948923e2411081fd9372e71a59d8e77.zip"
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


# add include directories
include_directories("${PROJECT_SOURCE_DIR}")

# add test function sorce files
file(GLOB TEST_FUNCTION_SOURCES
    "${PROJECT_SOURCE_DIR}/function/*.cpp"
)

# add test function header files
file(GLOB TEST_FUNCTION_HEADERS
    "${PROJECT_SOURCE_DIR}/function/*.h"
)

# add a static library
set(FUNCTION_LIB_NAME function)
add_library(${FUNCTION_LIB_NAME} STATIC 
    ${TEST_FUNCTION_SOURCES}
    ${TEST_FUNCTION_HEADERS})
target_include_directories(${FUNCTION_LIB_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/function/")

add_subdirectory(test)
include(GoogleTest)