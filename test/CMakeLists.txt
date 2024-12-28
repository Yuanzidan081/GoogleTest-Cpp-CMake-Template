set(GTEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/gcheck.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/gtest.cpp")

add_executable(Test ${GTEST_FILES})
target_link_libraries(Test gtest ${FUNCTION_LIB_NAME})

