# Sandbox
file(GLOB_RECURSE SandboxFiles CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(Sandbox ${SandboxFiles})

target_link_libraries(Sandbox PRIVATE Hazel)