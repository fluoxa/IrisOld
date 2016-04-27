#ifndef IRIS_APPMANAGER_HPP
#define IRIS_APPMANAGER_HPP

class AppStart
{
    public:

        AppStart(int args = 0, char** argv = nullptr)
        {
            _args = args;
            _argv = argv;
        }

        void loadConfig();

    private:

        int _args;
        char** _argv;

        void registerIocContainer();
        void registerCrudWorker();
};

#endif
