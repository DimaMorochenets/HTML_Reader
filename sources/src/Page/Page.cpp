/**
 * @file        Page.cpp
 * @author      Dmytro Morochenets
 * @brief       Source file with implementation of class Page
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include <fstream>
#include <iostream>

#include "Head.h"
#include "Page.h"

namespace HTML
{
    Page::Page() noexcept
    {
        this->data.clear();
    }

    Page::Page(const std::filesystem::path& path) noexcept
    {
        if (path.empty()) return;
        if (path.filename().empty()) return;
        if (!std::filesystem::exists(path)) return;

        this->path = path;
        this->loadPage();

        Head head(this->data);
    }

    Page::Page(const std::string& data) noexcept
    {
        this->data.clear();
        if (data.empty()) return;

        this->data << data;
    }

    Page::Page(const Page& instance) noexcept
    {
        this->data << instance.data.str();
        this->path = instance.path;
    }

    Page::Page(Page&& instance) noexcept
    {
        *this = instance;
    }

    Page& Page::operator=(const Page& instance) noexcept
    {
        this->data << instance.data.str();
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

        if (extension != ".txt" && extension != ".html")
            return false;

        this->data.clear();
        this->data << std::fstream(this->path).rdbuf();

        return data.str().empty() ? false : true;
    }
} // namespace HTML