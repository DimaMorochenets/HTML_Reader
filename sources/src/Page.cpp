/**
 * @file        Page.cpp
 * @author      Dmytro Morochenets
 * @brief       Source file with implementation of class Page
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include <sstream>
#include <fstream>

#include "Page.h"

namespace HTML
{
    Page::Page() noexcept
    {
        this->data = "";
    }

    Page::Page(const std::filesystem::path& path) noexcept
    {
        this->data = "";

        if (path.empty()) return;
        if (path.filename().empty()) return;
        if (!std::filesystem::exists(path)) return;

        this->path = path;
    }

    Page::Page(const std::string& data) noexcept
    {
        this->data = "";
        if (data.empty()) return;

        this->data = data;
    }

    Page::Page(const Page& instance) noexcept
    {
        this->data = instance.data;
        this->path = instance.path;
    }

    Page::Page(Page&& instance) noexcept
    {
        *this = instance;
    }

    Page& Page::operator=(const Page& instance) noexcept
    {
        this->data = instance.data;
        this->path = instance.path;
        return *this;
    }

    Page& Page::operator=(Page&& instance) noexcept
    {
        this->data = std::move(instance.data);
        this->path = std::move(instance.path);

        return *this;
    }

    bool Page::loadPage()
    {
        std::string extension = this->path.extension().string();

        if (extension != ".txt" || extension != ".html")
            return false;

        std::stringstream stream;
        stream << std::ifstream(this->path).rdbuf();
        stream >> data;

        return data.empty() ? false : true;
    }
} // namespace HTML