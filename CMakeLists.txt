cmake_minimum_required(VERSION 3.9)


project(ngine VERSION 0.0.1 DESCRIPTION "For now it is nothing more than opengl playground xD")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../build)
include(${PROJECT_BINARY_DIR}/CPM.cmake)

add_executable(${PROJECT_NAME} ${PROJECT_BINARY_DIR}/../src/main.cpp)
find_package(OpenGL REQUIRED)
CPMAddPackage(
  NAME GLFW
  GITHUB_REPOSITORY glfw/glfw
  GIT_TAG 3.3.2
  OPTIONS
    "CXXOPTS_BUILD_EXAMPLES OFF"
    "CXXOPTS_BUILD_TESTS OFF"
    "GLFW_BULID_DOCS OFF"
    "GLFW_INSTALL OFF"
    "GLFW_BUILD_EXAMPLES OFF"
    "GLFW_BUILD_TESTS OFF"
)


target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)