#include <app/App.hpp>
#include <app/appconfig/AppConfig.hpp>
#include <common/definitions/enums/repository/Repository.hpp>
#include <utils/helper/enumhelper/EnumHelper.hpp>
#include <iostream>

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
