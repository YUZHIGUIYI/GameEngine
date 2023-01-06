# Sandbox
file(GLOB_RECURSE SandboxFiles CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(Sandbox ${SandboxFiles})

target_link_libraries(Sandbox PRIVATE Hazel)

add_custom_command(TARGET Sandbox
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${PROJECT_SOURCE_DIR}/bin/assets)