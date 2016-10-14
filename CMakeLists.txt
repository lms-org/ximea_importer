if(USE_CONAN)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
endif(USE_CONAN)

set(SOURCES
    "src/ximea_importer.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/ximea_importer.h"
)

#set compiler flags
if((${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang") OR (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU"))
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wreturn-type -Wpedantic ")
endif()

include_directories(include)
add_library(ximea_importer MODULE ${SOURCES} ${HEADERS})
if(USE_CONAN)
target_link_libraries(ximea_importer PRIVATE ${CONAN_LIBS} m3api)
else()
target_link_libraries(ximea_importer PRIVATE imaging m3api)

endif(USE_CONAN)
