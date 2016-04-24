#ifndef IRIS_CRUDWORKER_HPP
#define IRIS_CRUDWORKER_HPP

#include "../contract/ICrudWorker.hpp"
#include "../../repository/contract/IRepository.hpp"

template <typename TEntity> class CrudWorker : public virtual ICrudWorker<TEntity>
{
    public:

        CrudWorker(IRepository_sPtr<TEntity> repo)
        {
            _repo = repo;
        }

        void setRepository(IRepository_sPtr<TEntity>& repo)
        {
            _repo = repo;
        }

        void save(std::shared_ptr<TEntity> obj)
        {
            _repo->save(obj);
        }

        void save(const std::unique_ptr<TEntity>& obj)
        {
            _repo->save(*obj);
        }

        std::unique_ptr<TEntity> read(unsigned long id)
        {
			//TODO: test, ob T pure abstract class oder concrete class ist, je nach dem IocFactory oder make_unique.... 
			
            auto returnPointer = IocFactory::getUniqueInstance<T>();

            _repo->read(id, *returnPointer);

            return returnPointer;
        }

    private:

        IRepository_sPtr<TEntity> _repo;
};

#endif //AIUNIT_ICRUDWORKER_HPP