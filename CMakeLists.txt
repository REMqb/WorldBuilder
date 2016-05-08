project(WorldBuilder)
cmake_minimum_required(VERSION 3.1)

# set compiler / linker conf
#set (CMAKE_CXX_STANDARD 17) #17 not supported by cmake yet
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++1z")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto")

Message("${CMAKE_BUILD_TYPE}")
Message(${WorldBuilder_SOURCE_DIR})

set(Boost_USE_MULTITHREADED ON)

#find libs
set(CMAKE_MODULE_PATH ${WorldBuilder_SOURCE_DIR}/cmake/Modules/ ${CMAKE_MODULE_PATH})

#find_package(SFML 2.3 REQUIRED system window graphics network audio)
find_package(SFML 2.3 REQUIRED system window audio)
find_package(protobuf CONFIG REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL 3.3 REQUIRED)
find_package(glbinding REQUIRED)
find_package(Boost 1.60 REQUIRED system log)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# find files
file(GLOB PROTO_FILES "${WorldBuilder_SOURCE_DIR}/src/worldbuilder/core/protocol/*.proto")
file(GLOB_RECURSE SRC_LIST src/*.cpp)
file(GLOB_RECURSE HEADERS_LIST src/*.hpp)

# generate protocol files
protobuf_generate_cpp(PROTO_GENERATED_CXX PROTO_GENERATED_H ${PROTO_FILES})

set(SRC_LIST ${SRC_LIST} ${PROTO_GENERATED_CXX})
set_source_files_properties(${PROTO_GENERATED_CXX} PROPERTIES COMPILE_FLAGS "-Wno-switch-default -Wno-unused-parameter")

message("Generated: ${PROTO_GENERATED_CXX}")

#executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

#set(CMAKE_VERBOSE_MAKEFILE true)

# link libraries
target_link_libraries(WorldBuilder ${PROTOBUF_LIBRARIES} glbinding::glbinding ${SFML_LIBRARIES} ${Boost_LIBRARIES} )

# This line permit some IDE to show files (ex: qt creator)
add_custom_target(source SOURCES ${PROTO_FILES} ${SRC_LIST} ${PROTO_GENERATED_CXX} ${PROTO_GENERATED_H})
