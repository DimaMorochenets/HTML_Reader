/**
 * @file        Page.h
 * @author      Dmytro Morochenets
 * @brief       Header of class Page
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef PAGE_H
#define PAGE_H

#include "Common.h"

#include <string>
#include <sstream>
#include <utility>
#include <filesystem>

namespace HTML
{
    /**
     * @brief Class for reading and storing HTML page as a internal variable 
     */
    class Page
    {
    private:
        std::filesystem::path path;     // Path to provided HTML page (if is empty, then page stored as internal)
        std::stringstream data;         // Store all data of provided HTML page

        /**
         * @brief Function for loading HTML page by path
         * This function attempts to copy all text of page to local variable "data"
         * @return true  - if loading success
         * @return false - if loading failed
         */
        bool loadPage();

    public:
        /**
         * @brief Default constuctor of class
         * Creates an instance of class and initializes all members to default value
         */
        Page() noexcept;

        /**
         * @brief Classic constructor of class
         * Creates an instance and load HTML page by provided path
         * 
         * @param path - path to HTML page
         */
        Page(const std::filesystem::path& path) noexcept;

        /**
         * @brief Classic constructor of class
         * Creates an instance and copy data from provided internal HTML page
         * 
         * @param data - internal HTML page
         */
        Page(const std::string& data) noexcept;

        /**
         * @brief Copy constuctor
         * Creates new instance of class and copies all values of members
         * from provided instance for copying
         * 
         * @param instance - instance of class for copying
         */
        Page(const Page& instance) noexcept;

        /**
         * @brief Move constructor
         * Uses move sematic for copying provided instance
         * 
         * @param instance - instance of class for moving (rvalue)
         */
        Page(Page&& instance) noexcept;

        /**
         * @brief Overloading assignment operator for copying
         * 
         * @param instance - instance of class for copying
         * 
         * @return Copied instance of class
         */
        Page& operator=(const Page& instance) noexcept;

        /**
         * @brief Overloading assignment operator for moving
         * 
         * @param instance - instance of class for moving
         * 
         * @return Moved instance of class 
         */
        Page& operator=(Page&& instance) noexcept;
    };  
} // namespace HTML

#endif