#include <common/definitions/enums/repository/Repository.hpp>
#include <app/appconfig/AppConfig.hpp>
#include <utils/helper/enumhelper/EnumHelper.hpp>
#include <app/appconfig/configdom/ConfigDom.hpp>

Repository AppConfig::repo = Repository::Default;
double AppConfig::backpropStepsize = 0.01;

void
AppConfig::loadParameters()
{
    repo = EnumHelper<Repository>().toEnum(ConfigDom::getParameterValue("repo"));

    backpropStepsize = std::atof(ConfigDom::getParameterValue("backpropStepsize").c_str());
}
