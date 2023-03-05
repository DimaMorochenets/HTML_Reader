/**
 * @file        Head.cpp
 * @author      Dmytro Morochenets
 * @brief       Source file of Head class
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#include "Head.h"

#include <iostream>

namespace HTML
{
    Head::Head(std::stringstream& data) noexcept
    {
        std::string block;
        std::getline(data, block);
        if (block != HTML::g_docSpecifier) return;

        block.clear();
        while (block.empty()) std::getline(data, block);
        GlobalAttributes.reset();
        GlobalAttributes.init(block);

        std::string line;
        bool skipTag = false;
        block.clear();
        while (line.find("/head>") == std::string::npos) {
            line.clear();
            std::getline(data, line);

            if (line.empty()) continue;

            // skip one-line sripts
            if (line.find("<script") != std::string::npos && line.find("</script>") != std::string::npos)
                continue;

            if (skipTag) {
                skipTag = line.find("</script>") == std::string::npos;
                continue;
            } else {
                if (line.find("<script") != std::string::npos) {
                    skipTag = true;
                    continue;
                }

                block.append(line);
                block.push_back('\n');
            }
        }

        std::cout << block << std::endl;
    }

} // namespace HTML
