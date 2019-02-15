message(STATUS "Building Unit Testing")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS}
                    ${CMAKE_SOURCE_DIR})

# Create an executable binary
add_executable(VectorTests
               VectorTests.cpp)

target_link_libraries(VectorTests 
                        ${GTEST_LIBRARIES}
                        pthread)

