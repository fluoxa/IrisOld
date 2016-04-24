#include <iostream>
#include <app/appconfig/AppConfig.hpp>
#include <common/exception/baseexception/BaseException.hpp>
#include "AppStart.hpp"

void
AppStart::loadConfig()
{
    try
    {
        AppConfig::loadParameters();
    }
    catch(BaseException exc)
    {
		//TODO: Exception hier umarbeiten
        std::cerr << "Called by loadParameters():" << std::endl;
        std::cerr << exc.errorMessage() << std::endl;
        throw BaseException("Fatal");
    }

    registerIocContainer();
	registerCrudWorker();
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
 // use as follows	
 // auto nnCrudWorker = []() -> Crud<INeuralNet>*
 // {
 //     auto repo = RepoFactory::getRepo<ITrainingHiddenLevelWorker>();
 // 
 //     return new CrudWorker<INeuralNet>(repo);
 // };
 // 
 // IocFactory::registerIocContainer(IocContainer().forService<ICrudWorker<INeuralNet>>().implementedBy<CrudWorker<INeuralNet>(std::cref(nnCrudWorker)));
}