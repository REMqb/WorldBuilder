project(WorldBuilder)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_LIST src/*.*pp)
#aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

Message(${CMAKE_BUILD_TYPE})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules/ ${CMAKE_MODULE_PATH})
#find_package(SFML 2.3 REQUIRED system window graphics network audio)
find_package(SFML 2.3 REQUIRED system window)
find_package(Protobuf 3 REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL 3.3 REQUIRED)

Message(${SFML_LIBRARIES})

target_link_libraries(WorldBuilder ${OPENGL_LIBRARIES} ${SFML_LIBRARIES} ${PROTOBUF_LIBRARIES})

