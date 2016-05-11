#include <app/appstart/AppStart.hpp>

#include <iostream>
#include <app/appconfig/AppConfig.hpp>
#include <common/exception/baseexception/BaseException.hpp>

#include <persistance/repository/dbrepository/DbRepository.hpp>
#include <definitions/persistance/crudworker/ICrudWorker.hpp>
#include <persistance/crudworker/CrudWorker.hpp>

std::shared_ptr<odb::database> AppStart::_db = nullptr;

void
AppStart::loadConfig()
{
    try
    {
        AppConfig::loadParameters();
    }
    catch(BaseException& exc)
    {
		//TODO: Exception hier umarbeiten
        std::cerr << "Called by loadParameters():" << std::endl;
        std::cerr << exc.errorMessage() << std::endl;
        throw BaseException("Fatal");
    }

	try
	{
		loadDataBase();
	}
	catch(odb::exception& e)
	{
		//TODO: Exception hier umarbeiten
        std::cerr << "Called by loadDatabases():" << std::endl;
        throw BaseException("Fatal");
	}
		
    registerIocContainer();
	registerCrudWorker();
}

void
AppStart::loadDataBase()
{
  _db = std::make_shared<odb::sqlite::database>(AppConfig::sqliteDb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);
}

void
AppStart::registerIocContainer()
{
 // use as follows	
 // IocFactory::registerIocContainer(IocContainer().forService<INeuralNet>().implementedBy<NeuralNet>());
}

void
AppStart::registerCrudWorker()
{
	auto nnCrudWorker = []() -> CrudWorker<Person>*
	{
		auto repo = std::make_shared<DbRepository<Person>>(AppStart::_db);

		return new CrudWorker<Person>(repo);
	};

	IocFactory::registerIocContainer(IocContainer().forService<ICrudWorker<Person>>().implementedBy<CrudWorker<Person>>(std::cref(nnCrudWorker)));
}