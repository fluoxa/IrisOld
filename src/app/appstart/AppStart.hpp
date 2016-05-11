#ifndef IRIS_APPMANAGER_HPP
#define IRIS_APPMANAGER_HPP

#include <memory>
#include <odb/database.hxx>
#include <odb/sqlite/database.hxx> 

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

		static std::shared_ptr<odb::database> _db;

		void loadDataBase();
        void registerIocContainer();
        void registerCrudWorker();
};

#endif
