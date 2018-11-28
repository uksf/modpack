cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project (uksf)

option(USE_64BIT_BUILD "USE_64BIT_BUILD" OFF)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /std:c++latest" )
set(CMAKE_BUILD_TYPE "Release")
set(PROJECT_NAME uksf)
if(CMAKE_GENERATOR MATCHES "Win64")
    set(USE_64BIT_BUILD ON)
endif()

set(CMAKE_CL_64 ${USE_64BIT_BUILD})

############## Artefacts Output #################
# Defines outputs , depending Debug or Release. #
#################################################

# Include directories 
include_directories(P:/z/intercept_cba/intercept/src/client/headers)
include_directories(../poco/Net/include)
include_directories(../poco/Util/include)
include_directories(../poco/XML/include)
include_directories(../poco/JSON/include)
include_directories(../poco/Foundation/include)
include_directories(%(AdditionalIncludeDirectories))

if(USE_64BIT_BUILD)
    message("WARNING: Building 64-bit projects")
    set(ARCH "x64")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build64/")
    link_directories("P:/z/intercept_cba/intercept/rv/intercept_client_x64")
    link_directories("../poco/lib64")
else()
    message("WARNING: Building 32-bit projects")
    set(ARCH "x86")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build32/")
    link_directories("P:/z/intercept_cba/intercept/rv/intercept_client")
    link_directories("../poco/lib")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################# Flags ################
# Defines Flags for Windows and Linux. #
########################################

set(CMAKE_CXX_FLAGS_DEBUG "/D _DEBUG /MTd /Zi /Ob0 /Od /RTC1 /EHsc")
set(CMAKE_CXX_FLAGS_MINSIZEREL "/MT /Ox /Ob1 /D NDEBUG /EHsc")
set(CMAKE_CXX_FLAGS_RELEASE "/MT /Ox /Ob2 /D NDEBUG /EHsc")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MT /Zi /Ox /Ob2 /D NDEBUG /EHsc")
set(CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL "/OPT:REF /LTCG")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/OPT:REF")
set(CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO "/OPT:REF /DEBUG:FULL")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /NODEFAULTLIB:libcmt.lib")
set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} /NODEFAULTLIB:libcmt.lib")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /NODEFAULTLIB:libcmt.lib")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /NODEFAULTLIB:libcmt.lib")

################ Files ################
#   --   Add files to project.   --   #
#######################################

file(GLOB_RECURSE SOURCES src/*.h src/*.hpp src/*.c src/*.cpp)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(LIBRARY_OUTPUT_PATH  "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

add_library(${PROJECT_NAME} MODULE ${SOURCES})
target_link_libraries(${PROJECT_NAME} intercept_client.lib PocoFoundationmt.lib PocoNetmt.lib PocoJSONmt.lib PocoXMLmt.lib PocoUtilmt.lib )

# Copy and rename
if(USE_64BIT_BUILD)
    set(FINAL_DLL_NAME uksf_x64.dll)
else()
    set(FINAL_DLL_NAME uksf.dll)
endif()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    # Copy DLL to plugins
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ../../intercept/${FINAL_DLL_NAME}
    # Copy PDB to symbols
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb ../../intercept/${ARCH}/${PROJECT_NAME}.pdb
)


