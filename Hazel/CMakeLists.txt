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

# Hazel
file(GLOB_RECURSE HazelFiles CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_library(Hazel STATIC ${HazelFiles})

target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/glm)
target_include_directories(Hazel PUBLIC ${CMAKE_CURRENT_LIST_DIR}/external/stb)

target_link_libraries(Hazel PUBLIC OpenGL::GL)
target_link_libraries(Hazel PUBLIC Glad)
target_link_libraries(Hazel PUBLIC glfw)
target_link_libraries(Hazel PUBLIC ImGuiDocking)
target_link_libraries(Hazel PUBLIC ImGuizmo)
target_link_libraries(Hazel PUBLIC spdlog_header_only)
target_link_libraries(Hazel PUBLIC EnTT)
target_link_libraries(Hazel PUBLIC yaml-cpp)

target_compile_definitions(Hazel PUBLIC _CRT_SECURE_NO_WARNINGS)
target_compile_definitions(Hazel PUBLIC GLFW_INCLUDE_NONE)
