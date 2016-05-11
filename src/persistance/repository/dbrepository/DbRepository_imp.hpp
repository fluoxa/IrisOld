#ifndef IRIS_DBREPOSITORYIMP_HPP
#define IRIS_DBREPOSITORYIMP_HPP

#include <persistance/repository/dbrepository/DbRepository.hpp>
#include <persistance/repository/dbrepository/persistancemapper/PersistanceMapper.hpp>
#include <odb/transaction.hxx>
#include <odb/core.hxx>

template <typename TEntity> void 
DbRepository<TEntity>::save(TEntity& entity)
{
    odb::transaction t(_db->begin());

    _db->persist(*PersistenceMapper::convert(entity));

    t.commit ();
}

template <> inline void
DbRepository<Person>::save(Person& entity)
{
    odb::transaction t(_db->begin());

    _db->persist(*PersistenceMapper::convert<Person, person>(entity));

    t.commit ();
}

template <typename TEntity> std::unique_ptr<TEntity> 
DbRepository<TEntity>::read(unsigned long id)
{
    return readImp<TEntity>(id);
}

template <> inline std::unique_ptr<Person>
DbRepository<Person>::read(unsigned long id)
{
    return readImp<person>(id);
}

template <typename TEntity> template <typename TPersistenceEntity> std::unique_ptr<TEntity>
DbRepository<TEntity>::readImp(unsigned long id)
{
    odb::transaction t (_db->begin());

    odb::result<TPersistenceEntity> r (_db->query<TPersistenceEntity>(odb::query<TPersistenceEntity>::id == id));

    std::unique_ptr<TEntity> entity = nullptr;

    if (!r.empty())
    {
        TPersistenceEntity persistenceEntity = *r.begin();
        entity = PersistenceMapper::invert<person, Person>(persistenceEntity);
    }

    t.commit();

    return entity;
}

#endif