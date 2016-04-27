#ifndef IRIS_APPCONFIG_HPP
#define IRIS_APPCONFIG_HPP

#include <string>
#include <common/definitions/enums/repository/Repository.hpp>
class AppConfig
{
    public:

        static Repository repo;
        static double backpropStepsize;

        static void loadParameters();
};

#endif
