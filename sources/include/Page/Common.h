/**
 * @file        Common.h
 * @author      Dmytro Morochenets
 * @brief       This file containse common constants and enums for HTML page
 * @version     0.0.1
 * @date        2023-02-26
 * 
 * @copyright   Copyright (c) 2023
 */

#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <sstream>
#include <map>

namespace HTML
{
    inline constexpr auto g_docSpecifier = "<!DOCTYPE html>";       /// First line in any HTML document

    /**
     * @brief   GlobalAttributes - is global static variable, 
     *          that store global attributes of HTML document
     */
    static struct Attributes {
        
        /**
         * @brief Parse line with global attributes and store those in public member
         * 
         * @param htmlHeader - html header <html ... >
         */
        void init(std::string htmlHeader) noexcept {
            auto addAttribute = [this](const std::string data) {
                std::string key;
                std::string value;
                int splitIndex = data.find_first_of('=');

                key = data.substr(0, splitIndex);
                value = data.substr(splitIndex + 2, data.find_last_of('"') - splitIndex - 2);

                this->attributes.insert_or_assign(key, value);
            };

            if (htmlHeader.find("html") == std::string::npos)
                return;

            std::stringstream stream;
            stream << htmlHeader;

            std::string attribute;
            stream >> attribute; // skip keyword "html"

            while (stream >> attribute) 
                addAttribute(attribute);
        }

        /**
         * @brief   Check if specified attributes is exist
         * 
         * @param   key - name of attribute
         * @retval  true if attribute is exist 
         */
        bool isAttributeExist(const std::string key) {
            return attributes.find(key) == attributes.end() ? false : true;
        }

        /**
         * @brief   Get the Attribute Value by key
         * 
         * @param   key - name of attribute
         * @return  attribute value 
         */
        std::string getAttributeValue(const std::string key) {
            return isAttributeExist(key) ? attributes[key] : "";
        }

        /**
         * @brief   Clear list of attributes
         */
        void reset() {
            attributes.clear();
        }

        private:
            std::map<std::string, std::string> attributes;              /// All gloabl attributes
    } GlobalAttributes;

} // namespace HTML

#endif