cmake_minimum_required (VERSION 3.8)

if(USE_64BIT_BUILD)
    set(UKSF_EXTENSION_NAME "uksf_x64")
    link_directories("P:/z/intercept_cba/intercept/rv/intercept_client_x64")
    link_directories("../../../poco/lib64")
else()
    set(UKSF_EXTENSION_NAME "uksf")
    link_directories("P:/z/intercept_cba/intercept/rv/intercept_client")
    link_directories("../../../poco/lib")
endif()

file(GLOB_RECURSE UKSF_SOURCES *.h *.hpp *.c *.cpp)
uksf_set_linker_options()

set(UKSF_NAME "uksf")

file(GLOB_RECURSE UKSF_SOURCES *.h *.hpp *.c *.cpp)

SOURCE_GROUP("uksf" FILES ${UKSF_SOURCES})

add_library( ${UKSF_EXTENSION_NAME} SHARED ${UKSF_SOURCES})
add_library( ${UKSF_EXTENSION_NAME}_static ${UKSF_SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${UKSF_EXTENSION_NAME} intercept_client.lib PocoFoundationmt.lib PocoNetmt.lib PocoJSONmt.lib PocoXMLmt.lib PocoUtilmt.lib ${LINK_LIBS})
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES PREFIX "")
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES FOLDER uksf)

set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/../intercept")
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${PROJECT_SOURCE_DIR}/../intercept")
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE "${PROJECT_SOURCE_DIR}/../intercept")
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${PROJECT_SOURCE_DIR}/../intercept")
set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${PROJECT_SOURCE_DIR}/../intercept")

if(CMAKE_COMPILER_IS_GNUCXX)
    set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties(${UKSF_EXTENSION_NAME} PROPERTIES LINK_SEARCH_END_STATIC 1)
    set_target_properties(${UKSF_EXTENSION_NAME}_static PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties(${UKSF_EXTENSION_NAME}_static PROPERTIES LINK_SEARCH_END_STATIC 1)
endif()
