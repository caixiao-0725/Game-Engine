cmake_minimum_required(VERSION 3.0)
project(CxEngine C CXX CUDA)

# set C++20 standard supported
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CUDA_ARCHITECTURES 75 80 86 CACHE STRING "CUDA architectures" FORCE)
set(CMAKE_CUDA_ARCHITECTURES ${CUDA_ARCHITECTURES} CACHE STRING "CUDA architectures" FORCE)

# set at least CUDA 11.0 standard supported, this will overwriting CUDA compiler flags
set(CMAKE_CUDA_STANDARD 17)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} --extended-lambda --expt-relaxed-constexpr ${CUDA_ARCHS}")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/"  ${CMAKE_MODULE_PATH} CACHE PATH "cache module path")

#set build directory structure
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}" CACHE PATH "" FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}" CACHE PATH "" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}" CACHE PATH "" FORCE)

set(THIRD_PARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cngine/thirdparty")


# add cuda
find_package(CUDA REQUIRED)
if(CUDA_FOUND)
    include_directories(${CUDA_INCLUDE_DIRS})
    link_directories(${CUDA_TOOLKIT_ROOT_DIR}/lib64)
    link_libraries(${CUDA_LIBRARIES})
else()
    message("ERROR: Cuda Not Found! [Required]")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("${THIRD_PARTY_DIR}/spdlog")
add_subdirectory("${THIRD_PARTY_DIR}/glm")
add_subdirectory("${THIRD_PARTY_DIR}/imgui")
add_subdirectory("${THIRD_PARTY_DIR}/glfw")
add_subdirectory("${THIRD_PARTY_DIR}/glad")
add_subdirectory("${THIRD_PARTY_DIR}/yaml-cpp")


#
# Cngine
#

# Define the cngine static library
file(GLOB_RECURSE cngine_sources RELATIVE ${PROJECT_SOURCE_DIR} cngine/src/*.cpp)
add_library(cngine STATIC
  ${cngine_sources}

  cngine/thirdparty/stb_image/stb_image.cpp
)

target_compile_definitions(cngine PRIVATE _CRT_SECURE_NO_WARNINGS
GLFW_INCLUDE_NONE
)

# Set defines for build type
set(CMAKE_CXX_FLAGS_DEBUG -CG_DEBUG)
set(CMAKE_CXX_FLAGS_RELEASE -CG_RELEASE)
set(CMAKE_CXX_FLAGS_DIST -CG_DIST)

# Include directories for cngine
target_include_directories(cngine PUBLIC
  "${PROJECT_SOURCE_DIR}/cngine/src"
  "${THIRD_PARTY_DIR}/entt/include"
  "${THIRD_PARTY_DIR}/glad/include"
  "${THIRD_PARTY_DIR}/glm"
  "${THIRD_PARTY_DIR}/imgui"
  "${THIRD_PARTY_DIR}/spdlog/include"
  "${THIRD_PARTY_DIR}/stb_image"
  "${THIRD_PARTY_DIR}/yaml-cpp/include"
)


# glfw
target_link_libraries(cngine PRIVATE glfw)

# glad
target_link_libraries(cngine PRIVATE glad)

# imgui
target_link_libraries(cngine PUBLIC imgui)

target_link_libraries(cngine PRIVATE opengl32.lib)

# yaml-cpp
target_link_libraries(cngine PRIVATE yaml-cpp)


#
# Cngine-Editor
#

# Define Cngine-Editor application
file(GLOB Cngine_Editor_sources cngine-Editor/src/*.cpp cngine-Editor/src/Panels/*.cpp)
add_executable(Cngine-Editor ${Cngine_Editor_sources})

# Include directories for the Cngine-Editor application
target_include_directories(Cngine-Editor PUBLIC "${PROJECT_SOURCE_DIR}/cngine-Editor/src"
    "${THIRD_PARTY_DIR}"
)

# Link Cngine-Editor with the hazel library
target_link_libraries(Cngine-Editor PUBLIC imgui)
target_link_libraries(Cngine-Editor PUBLIC cngine)