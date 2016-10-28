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

if(APPLE)
find_library(M3API m3api)
endif(APPLE)

if(USE_CONAN)

if(APPLE)
target_link_libraries(ximea_importer PRIVATE ${CONAN_LIBS} ${M3API})
else()
target_link_libraries(ximea_importer PRIVATE ${CONAN_LIBS} m3api)
endif(APPLE)

else()

if(APPLE)
target_link_libraries(ximea_importer PRIVATE lmscore lms_imaging ${M3API})
else()
target_link_libraries(ximea_importer PRIVATE lmscore lms_imaging m3api)
endif(APPLE)

endif(USE_CONAN)
