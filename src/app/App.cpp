#include <app/App.hpp>
#include <iostream>

#include <persistance/data/person/person.hxx>
#include <common/iocfactory/IocFactory.hpp>
#include <definitions/persistance/crudworker/ICrudWorker.hpp>

#include <persistance/repository/dbrepository/DbRepository.hpp>

void
App::run()
{
    // hier Programmausführung rein

    auto worker = IocFactory::getUniqueInstance<ICrudWorker<Person>>();
    auto result = worker->read(3);

    if(result != nullptr)
        std::cout << result->getGreetings() << std::endl;
}

void 
App::init()
{
	appStart.loadConfig();
}
