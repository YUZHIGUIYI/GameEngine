# Sandbox
file(GLOB_RECURSE HazelnutFiles CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(Hazelnut ${HazelnutFiles})

target_include_directories(Hazelnut PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(Hazelnut PRIVATE Hazel)

add_custom_command(TARGET Hazelnut
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/HazelnutAssets ${PROJECT_SOURCE_DIR}/bin/HazelnutAssets)