//
// Created by ZZK on 2023/1/10.
//

#include <Hazel/Core/Input.h>

#ifdef HZ_PLATFORM_WINDOWS
    #include <Platform/Windows/WindowsInput.h>
#endif

namespace Hazel
{

    Scope<Input> Input::s_Instance = Input::Create();

    // Add Input::Create function into one place
    Scope<Input> Input::Create()
    {
#ifdef HZ_PLATFORM_WINDOWS
        return CreateScope<WindowsInput>();
#else
        HZ_CORE_ASSERT(false, "Unknown platform!");
#endif
    }
}












