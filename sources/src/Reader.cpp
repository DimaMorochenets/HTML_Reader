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

namespace HTML
{
    Reader::Reader()
    {
        this->page = "";
    }

    Reader::Reader(const std::string& page)
    {
        this->page = page;
    }

    Reader::Reader(const Reader& instance)
    {
        this->page = instance.page;
    }

    Reader::Reader(Reader&& instance)
    {
        this->page = std::move(instance.page);
    }
} // namespace HTML
