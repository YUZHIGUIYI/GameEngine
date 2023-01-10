//
// Created by ZZK on 2023/1/10.
//

#include <Hazel/Core/Window.h>

#ifdef HZ_PLATFORM_WINDOWS
    #include <Platform/Windows/WindowsWindow.h>
#endif

namespace Hazel
{

    // Add Window::Create function into one place
    Scope<Window> Window::Create(const WindowProps &props)
    {
#ifdef HZ_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        HZ_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }
}



















