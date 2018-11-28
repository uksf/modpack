cmake_minimum_required (VERSION 3.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (NOT CMAKE_BUILD_TYPE AND CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

option(DEVEL "DEVEL" ON)
option(USE_STATIC_LINKING "USE_STATIC_LINKING" ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    #remove -s to enable debug symbols. Also maybe add -g or -g3
    SET(CMAKE_CXX_FLAGS "-std=c++1z -march=i686 -m32 -O2 -s -fPIC -fpermissive -pthread")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(CMAKE_SHARED_LINKER_FLAGS "-static -static-libgcc -static-libstdc++ -Wl,-rpath,$ORIGIN")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MTd /Zi /Ob0 /Od /RTC1 /EHsc")
    set(CMAKE_CXX_FLAGS_MINSIZEREL     "/MT /Ox /Ob1 /D /EHsc NDEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE       "/MT /Ox /Ob2 /D /EHsc NDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /Ox /Ob2 /D /EHsc NDEBUG")
    set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "/OPT:REF /LTCG") 
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/OPT:REF") 
    set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "/OPT:REF /DEBUG:FULL") 
endif()
include_directories(P:/z/intercept_cba/intercept/src/client/headers)
include_directories(../../poco/Net/include)
include_directories(../../poco/Util/include)
include_directories(../../poco/XML/include)
include_directories(../../poco/JSON/include)
include_directories(../../poco/Foundation/include)
include_directories("uksf")

if(DEVEL)
    add_definitions(-DDEVEL)
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR}/uksf)

set(GLOBAL_SOURCES ${GLOBAL_RC})

add_subdirectory(uksf)

message("Build Type: ${CMAKE_BUILD_TYPE}")
