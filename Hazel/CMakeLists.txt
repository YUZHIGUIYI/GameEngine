# glad
add_subdirectory(external/glad)

# glfw
add_subdirectory(external/glfw)

# imgui
add_subdirectory(external/imgui)

# imguizmo
add_subdirectory(external/ImGuizmo)

# spdlog
add_subdirectory(external/spdlog)

# entt
add_subdirectory(external/entt)

# yaml-cpp
add_subdirectory(external/yaml-cpp)

# Box2D
add_subdirectory(external/Box2D)

# Hazel
file(GLOB_RECURSE HazelFiles CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_library(Hazel STATIC ${HazelFiles})

target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/glm)
target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/stb)
target_include_directories(Hazel PUBLIC ${Vulkan_INCLUDE_DIRS})

target_link_libraries(Hazel PUBLIC OpenGL::GL)
target_link_libraries(Hazel PUBLIC Glad)
target_link_libraries(Hazel PUBLIC glfw)
target_link_libraries(Hazel PUBLIC ImGuiDocking)
target_link_libraries(Hazel PUBLIC ImGuizmo)
target_link_libraries(Hazel PUBLIC spdlog_header_only)
target_link_libraries(Hazel PUBLIC EnTT)
target_link_libraries(Hazel PUBLIC yaml-cpp)
target_link_libraries(Hazel PUBLIC box2d)

target_link_libraries(Hazel PUBLIC Vulkan::Vulkan)
target_link_libraries(Hazel PUBLIC Vulkan::shaderc_combined)
target_link_libraries(Hazel PUBLIC Vulkan::SPIRV-Tools)
if(${HAZEL_ENGINE_DEBUG})
    message(STATUS "Hazel build type: Debug")
    target_link_libraries(Hazel PUBLIC "$ENV{VULKAN_SDK}/Lib/spirv-cross-cored.lib")
    target_link_libraries(Hazel PUBLIC "$ENV{VULKAN_SDK}/Lib/spirv-cross-glsld.lib")
else()
    message(STATUS "Hazel build type: Release")
    target_link_libraries(Hazel PUBLIC "$ENV{VULKAN_SDK}/Lib/spirv-cross-core.lib")
    target_link_libraries(Hazel PUBLIC "$ENV{VULKAN_SDK}/Lib/spirv-cross-glsl.lib")
endif()
#target_link_libraries(Hazel PUBLIC "$ENV{VULKAN_SDK}/Lib/VkLayer_utils.lib")

target_compile_definitions(Hazel PUBLIC _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(Hazel PUBLIC GLFW_INCLUDE_NONE)
