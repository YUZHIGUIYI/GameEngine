file(GLOB_RECURSE GladFiles CONFIGURE_DEPENDS include/*.h src/*.c)

add_library(Glad STATIC ${GladFiles})

target_include_directories(Glad PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)