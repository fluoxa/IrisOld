#ifndef AIUNIT_APP_HPP
#define AIUNIT_APP_HPP

#include <app/appstart/AppStart.hpp>

class App
{
    public:

        App(int args, char** argv) : appStart(args, argv)
        { }

        void init();
        void run();

    private:

        AppStart appStart;
};

#endif