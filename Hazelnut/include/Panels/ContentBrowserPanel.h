//
// Created by ZZK on 2023/1/29.
//

#pragma once

#include <filesystem>

namespace Hazel
{

    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();

        void OnImGuiRender();

    private:
        std::filesystem::path m_CurrentDirectory;
    };
}


