#ifndef AIUNIT_IOCFACTORY_HPP
#define AIUNIT_IOCFACTORY_HPP

#include <common/iocfactory/ioccontainer/IocContainer.hpp>

#include <memory>
#include <map>
#include <typeindex>
#include <typeinfo>
#include <list>
#include <iostream>

class IocFactory
{
    public:

        static void registerIocContainer(IocContainer& container);

        template <class T> static std::shared_ptr<T> getSharedInstance()
        {
            for(auto& container : _containers)
                if(container._service == std::type_index(typeid(T)))
                    return std::shared_ptr<T>( container.getFactory<T>()() );

			//TODO: Exceptions ueberarbeiten
            throw BaseException("Not registered Ioc-Interface");
        };

        template <class T> static std::unique_ptr<T> getUniqueInstance()
        {
            for(auto& container : _containers)
                if(container._service == std::type_index(typeid(T)))
                    return std::unique_ptr<T>( container.getFactory<T>()() );

			//TODO: Exceptions ueberarbeiten
            throw BaseException("Not registered Ioc-Interface");
        };

        static void flushRegisters();

    private:

        static std::list<IocContainer> _containers;
};

#endif