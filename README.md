# GameEngine

## Introduction
- This a game engine with reference to [Hazel](https://github.com/TheCherno/Hazel)
- Built with [CMake](https://cmake.org/)
- Tested on Windows platform
- For recording personal learning process only

## Details
- Hazel directory includes the source codes of Hazel engine, and it is built as a static library
- Hazelnut directory includes the source codes of interactive Hazel editor that can be used to create entities and components, needed to link Hazel static library firstly
- Sandbox, so far, it has not provided substantive functions

## Requirements
- [Vulkan SDK](https://vulkan.lunarg.com/), recommended to select [SPIRV-Tools](https://github.com/KhronosGroup/SPIRV-Tools) and [SPIRV-Cross](https://github.com/KhronosGroup/SPIRV-Cross) and [shaderc](https://github.com/google/shaderc) during installation
- [Visual Studio 2022](https://visualstudio.microsoft.com/zh-hant/vs/whatsnew/) or [Clion](https://www.jetbrains.com/clion/)
- [CMake](https://cmake.org/)

## Get started
```shell
## Windows platform only - Debug
cmake -B build
cmake --build build
./bin/Debug/Hazelnut
## Windows platform only - Release
cmake -B build
cmake --build build --config=Release
./bin/Release/Hazelnut
```

Third party libraries
- [GLFW](https://github.com/glfw/glfw)
- [GLM](https://github.com/g-truc/glm)
- [Dear ImGui](https://github.com/ocornut/imgui)
- [ImGuizmo](https://github.com/YUZHIGUIYI/ImGuizmo)
- [stb](https://github.com/nothings/stb)
- [spdlog](https://github.com/gabime/spdlog)
- [entt](https://github.com/skypjack/entt)
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)
