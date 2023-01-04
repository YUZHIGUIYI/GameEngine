# glad
add_subdirectory(external/glad)

# glfw
add_subdirectory(external/glfw)

# imgui
add_subdirectory(external/imgui)

# spdlog
add_subdirectory(external/spdlog)

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
target_link_libraries(Hazel PUBLIC spdlog_header_only)

target_compile_definitions(Hazel PUBLIC HZ_PLATFORM_WINDOWS)
# Debug only
target_compile_definitions(Hazel PUBLIC HZ_DEBUG)