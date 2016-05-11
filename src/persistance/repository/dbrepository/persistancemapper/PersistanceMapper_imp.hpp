#ifndef IRIS_PERSISTANCEMAPPER_IMP_HPP
#define IRIS_PERSISTANCEMAPPER_IMP_HPP

#include <persistance/repository/dbrepository/persistancemapper/PersistanceMapper.hpp>
#include <persistance/data/person/person.hxx>
#include <neuralnet/data/person/Person.hpp>

namespace PersistenceMapper
{
    template <> std::unique_ptr<person> convert(Person& entity)
    {
        return std::make_unique<person>(entity.name, entity.age);
    }

    template <> std::unique_ptr<Person> invert(person& entity)
    {
        auto per = std::make_unique<Person>();

        per->name = entity.name();
        per->age = entity.age();

        return std::move(per);
    }
}

#endif //IRIS_PERSISTANCEMAPPER_IMP_HPP