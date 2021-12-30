cmake_minimum_required(VERSION 3.9)

project(ngine VERSION 0.0.1 DESCRIPTION "For now it is nothing more than opengl playground xD")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
include(${PROJECT_BINARY_DIR}/CPM.cmake)
include_directories(${PROJECT_SOURCE_DIR}/src)
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/include)

add_executable( ${PROJECT_NAME} 
                ${PROJECT_SOURCE_DIR}/src/main.cpp 
                ${PROJECT_SOURCE_DIR}/src/Window.cpp  
                ${PROJECT_SOURCE_DIR}/src/Application.cpp 
                ${PROJECT_SOURCE_DIR}/src/Render/Renderer.cpp
                ${PROJECT_SOURCE_DIR}/src/Render/VertexBuffer.cpp
              )

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
CPMAddPackage(
  NAME GLAD
  GITHUB_REPOSITORY Dav1dde/glad 
  GIT_TAG v0.1.34
)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLAD_SOURCE_DIR}/include)
CPMAddPackage(
  NAME SPDLOG
  GITHUB_REPOSITORY gabime/spdlog 
  GIT_TAG v1.9.2
)
target_include_directories(${PROJECT_NAME} PUBLIC ${SPDLOG_SOURCE_DIR}/include)
CPMAddPackage(
  NAME GLM
  GITHUB_REPOSITORY g-truc/glm
  GIT_TAG 0.9.9.8
)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLM_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} glfw glad)