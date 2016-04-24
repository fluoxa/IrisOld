#include <common/definitions/enums/repository/Repository.hpp>
#include <utils/helper/enumhelper/EnumHelper.hpp>
#include <app/appconfig/AppConfig.hpp>
#include <iostream>
#include "App.hpp"

void
App::run()
{
    // hier Programmausführung rein

    std::cout << EnumHelper<Repository>().toString(AppConfig::repo) << std::endl;
}

void 
App::init()
{
	appStart.loadConfig();
}
