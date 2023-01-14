# Sandbox
file(GLOB_RECURSE HazelEditorFiles CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(HazelEditor ${HazelEditorFiles})

target_include_directories(HazelEditor PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(HazelEditor PRIVATE Hazel)