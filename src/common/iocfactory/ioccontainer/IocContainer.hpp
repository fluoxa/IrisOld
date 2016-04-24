#ifndef AIUNIT_IOCCONTAINER_HPP
#define AIUNIT_IOCCONTAINER_HPP

#include <common/exception/baseexception/BaseException.hpp>
#include <typeindex>
#include <functional>
#include <vector>

class IocFactory;

class IocContainer
{
        friend class IocFactory;

    public:

        IocContainer() : _service(typeid(nullptr))
        {
            _factory = nullptr;
            _refcount = new unsigned int(1);
        }

        IocContainer( const IocContainer &obj) : _service(typeid(nullptr))
        {
            this->_service = obj._service;
            this->_factory = obj._factory;
            this->_refcount = obj._refcount;

            this->_refcount++;
        }

        ~IocContainer()
        {
            (*_refcount)--;

            if(_refcount == 0)
            {
                ::operator delete(_factory);
                _factory = nullptr;
                delete _refcount;
            }
        }

        template <class T> IocContainer& forService()
        {
            _service = std::type_index(typeid(T));

            return *this;
        }

        template <class T> IocContainer& implementedBy(std::function<T*(void)> func)
        {
            _factory = reinterpret_cast<void*>(new std::function<T*(void)> (func) );

            return *this;
        }

        template <class T> IocContainer& implementedBy()
        {
            auto create = [] () -> T* { return new T(); };

            return this->implementedBy<T>(std::cref(create));
        }

        template <class T> std::function<T*(void)>& getFactory()
        {
            if(_factory != nullptr)
                return *(reinterpret_cast<std::function<T*(void)>*>(_factory));

            throw BaseException("Factory no registered yet");
        }

    private:

        std::type_index _service;
        void* _factory;
        unsigned int* _refcount;
};

#endif //AIUNIT_IOCCONTAINER_HPP
