cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GameEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

# Build Type
set(HAZEL_ENGINE_DEBUG OFF)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    set(HAZEL_ENGINE_DEBUG OFF)
else()
    set(HAZEL_ENGINE_DEBUG ON)
endif()

# CMAKE_EXPORT_COMPILE_COMMANDS
if(NOT CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# Test
include(CMakeDependentOption)
cmake_dependent_option(HAZEL_BUILD_WIN32 "Build support for Win32" ON "WIN32" OFF)
if(HAZEL_BUILD_WIN32)
    message(STATUS "Build for Windows platform")
endif()

# OpenGL
find_package(OpenGL REQUIRED)

# Vulkan
find_package(Vulkan REQUIRED COMPONENTS glslc glslangValidator glslang shaderc_combined SPIRV-Tools)
message(STATUS "Vulkan environment: $ENV{VULKAN_SDK}")
message(STATUS "Vulkan include directory: ${Vulkan_INCLUDE_DIRS}")
message(STATUS "Vulkan library: ${Vulkan_LIBRARIES}")
message(STATUS "GLSLC executable: ${Vulkan_GLSLC_EXECUTABLE}")
message(STATUS "Shaderc combined library: ${Vulkan_shaderc_combined_LIBRARY}")
message(STATUS "Vulkan SPIRV-Tools library: ${Vulkan_SPIRV-Tools_LIBRARY}")

# Hazel
add_subdirectory(Hazel)

# Hazel editor
add_subdirectory(Hazelnut)

# Sandbox Application
add_subdirectory(Sandbox)
