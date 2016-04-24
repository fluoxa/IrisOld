#include "ConfigDom.hpp"
#include "../../../utils/parser/pugixmlparser/PugiXmlParser.hpp"
#include "../../../common/exception/baseexception/BaseException.hpp"

#include <fstream>

std::string ConfigDom::_configPath = "ResourceFiles/AppConfig/AppConfig.xml";

pugi::xml_document *ConfigDom::_doc = nullptr;

std::regex  ConfigDom::_removeSpacesRegex = std::regex("^( |\n|\t|\r)+|( |\n|\t|\r)+$");

std::string 
ConfigDom::getParameterValue(std::string attributeName)
{
	if(_configPath.empty())
		_configPath  = "AppConfig/AppConfig.xml";

	pugi::xml_parse_result result;

	if(_doc == nullptr)
	{
		_doc = new pugi::xml_document();
		std::ifstream ifs(_configPath);
		result = _doc->load(ifs);
	}

	//TODO: file not found exception werfen und ausgeben, wo appconfig zu definieren

	auto appConfigNode = _doc->child("appConfig");

	for(auto node : appConfigNode.children("parameter"))
	{
		auto nameAttr = node.attribute("name");

		if( std::strcmp(nameAttr.value(), attributeName.c_str()) != 0)
			continue;

		auto value = node.text();

		if(!value.empty())
			return std::string( std::regex_replace(value.get(), _removeSpacesRegex, "") );
		else 	//TODO: Exception ueberarbeiten
			throw BaseException("Missing value for Parameter " + std::string(nameAttr.value()));
	}

	//TODO: Exception ueberarbeiten
	throw BaseException(attributeName);
}