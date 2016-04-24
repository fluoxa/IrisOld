#include <common/iocfactory/ioccontainer/IocContainer.hpp>
#include <list>
#include "IocFactory.hpp"

std::list<IocContainer> IocFactory::_containers = {};

void 
IocFactory::registerIocContainer(IocContainer& container)
{
	_containers.push_back(container);
}

void
IocFactory::flushRegisters()
{
        _containers.clear();
}