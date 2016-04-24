#include "../../common/definitions/enums/repository/Repository.hpp"
#include "AppConfig.hpp"
#include "../../utils/helper/enumhelper/EnumHelper.hpp"
#include "ConfigDom/ConfigDom.hpp"

Repository AppConfig::repo = Repository::Default;
double AppConfig::backpropStepsize = 0.01;

void
AppConfig::loadParameters()
{
    repo = EnumHelper<Repository>().toEnum(ConfigDom::getParameterValue("repo"));

    backpropStepsize = std::atof(ConfigDom::getParameterValue("backpropStepsize").c_str());
}
