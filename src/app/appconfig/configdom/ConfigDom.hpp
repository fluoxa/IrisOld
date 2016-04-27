#ifndef IRIS_CONFIGDOM_HPP
#define IRIS_CONFIGDOM_HPP

#include <utils/parser/pugixmlparser/PugiXmlParser.hpp>

#include <string>
#include <regex>

class ConfigDom
{
    public:

        static std::string getParameterValue(std::string attributeName);

    private:

        static std::string _configPath;
        static pugi::xml_document* _doc;
        static std::regex  _removeSpacesRegex;
};

#endif
