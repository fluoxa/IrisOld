#ifndef IRIS_DBREPOSITORY_HPP
#define IRIS_DBREPOSITORY_HPP

#include <definitions/persistance/repository/IRepository.hpp>
#include <odb/database.hxx>

#include <persistance/data/person/person.hxx>
#include <persistance/data/person/person-odb.hxx>

template <typename TEntity> class DbRepository : public virtual IRepository<TEntity>
{
    public:
        
        DbRepository(std::shared_ptr<odb::database> db)
        {
			_db = db;
		}
        
        virtual void save(TEntity& entity);

        virtual std::unique_ptr<TEntity> read(unsigned long id);

	private:

		std::shared_ptr<odb::database> _db;

        template <typename TPersistanceEntity> std::unique_ptr<TEntity> readImp(unsigned long id);
};

#include <persistance/repository/dbrepository/DbRepository_imp.hpp>

#endif
