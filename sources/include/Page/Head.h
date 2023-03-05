/**
 * @file        Head.h
 * @author      Dmytro Morochenets
 * @brief       Header file of Head class
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef HEAD_H
#define HEAD_H

#include <string>
#include <sstream>
#include <list>

#include "Common.h"

namespace HTML
{
    /**
     * @brief Used for string specify info from head block fo document
     * This class store title, charset and other main information of HTML
     */
    class Head
    {
    private:
        std::string title;                          /// Title of document
        std::map<std::string, std::string> meta;    /// Store all meta property specified in head block of HTML document
        std::map<std::string, std::string> links;   /// Store all external links specified in head block of HTML document

        /**
         * @brief Reading global documents atributes
         * inside html tag (lang, class, dir, etc.)
         * 
         * @param line - line of "html" tag (<html ... >)
         */
        void parseHTMLAtributes(const std::string line);
    public:
        /**
         * @brief Signle constructor of Head class
         *          
         * @param data - all external HTML page, stroed as internal stream
         */
        explicit Head(std::stringstream& data) noexcept;
    };
} // namespace HTML

#endif