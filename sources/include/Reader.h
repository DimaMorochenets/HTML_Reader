/**
 * @file        Reader.h
 * @author      Dmytro Morochenets
 * @brief       Header of main class of project
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef READER_H
#define READER_H

#include <string>

#include "Page.h"

/**
 * @brief Main namespace of project
 *        All futures will be implemented in scope of this namespace
 */
namespace HTML
{
    /**
     * @brief Main class of project
     * Creates as a single instance of project 
     * to provide incapsulated methods in internal classes
     */
    class Reader
    {
    private:
        Page page;                      /// Store html-page
    public:
        /**
         * @brief Default constuctor of class
         * Creates an instance of class and initializes all members to default values
         */
        Reader() noexcept;

        /**
         * @brief Classic constructor of class
         * Creates an instance and initilizes all members by provided values
         * 
         * @param page - external html-page
         */
        Reader(const std::string& page) noexcept;

        /**
         * @brief Classic constructor of class
         * Creates an instance and initilizes all members by provided values
         * 
         * @param path - path to external html-page
         */
        Reader(const std::filesystem::path& path) noexcept;

        /**
         * @brief Copy constuctor
         * Creates new instance of class and copies all values of members
         * from provided instance for copying
         * 
         * @param instance - instance of class for copying
         */
        Reader(const Reader& instance) noexcept;

        /**
         * @brief Move constructor
         * Uses move sematic for copying provided instance
         * 
         * @param instance - instance of class for moving (rvalue)
         */
        Reader(Reader&& instance) noexcept;
    };
} // namesape HTML

#endif