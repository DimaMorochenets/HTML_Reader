/**
 * @file        Reader.cpp
 * @author      Dmytro Morochenets
 * @brief       Source file with implementation of class Reader
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Reader.h"

#include <utility>
#include <iostream>

namespace HTML
{
    Reader::Reader() noexcept
    {
        this->page = Page();
    }

    Reader::Reader(const std::string& page) noexcept
    {
        this->page = Page(page);
    }

    Reader::Reader(const std::filesystem::path& path) noexcept
    {
        this->page = Page(path);
    }

    Reader::Reader(const Reader& instance) noexcept
    {
        this->page = Page(instance.page);
    }

    Reader::Reader(Reader&& instance) noexcept
    {
        this->page = std::move(instance.page);
    }
} // namespace HTML
