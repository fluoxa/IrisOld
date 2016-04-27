#ifndef IRIS_CRUDWORKER_HPP
#define IRIS_CRUDWORKER_HPP

#include <common/iocfactory/IocFactory.hpp>
#include <persistance/crudworker/contract/ICrudWorker.hpp>

template <typename TEntity> class CrudWorker : public virtual ICrudWorker<TEntity>
{
    public:

        CrudWorker(IRepository_sPtr<TEntity> repo)
        {
            _repo = repo;
        }

        void setRepository(IRepository_sPtr<TEntity>& repo);

        void save(std::shared_ptr<TEntity> obj);
        void save(const std::unique_ptr<TEntity>& obj);

        std::unique_ptr<TEntity> read(unsigned long id);

    private:

        IRepository_sPtr<TEntity> _repo;
};

#include <persistance/crudworker/impl/CrudWorker_imp.hpp>

#endif
