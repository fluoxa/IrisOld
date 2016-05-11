#include <app/appconfig/AppConfig.hpp>
#include <utils/helper/enumhelper/EnumHelper.hpp>
#include <app/appconfig/configdom/ConfigDom.hpp>

Repository AppConfig::repo = Repository::Default;
double AppConfig::backpropStepsize = 0.01;
std::string AppConfig::sqliteDb;

void
AppConfig::loadParameters()
{
    repo = EnumHelper<Repository>().toEnum(ConfigDom::getParameterValue("repo"));

    backpropStepsize = std::atof(ConfigDom::getParameterValue("backpropStepsize").c_str());

	sqliteDb = ConfigDom::getParameterValue("sqliteDb");
}
