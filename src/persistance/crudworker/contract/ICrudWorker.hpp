#ifndef IRIS_ICRUDWORKER_HPP
#define IRIS_ICRUDWORKER_HPP

#include <persistance/repository/contract/IRepository.hpp>

#include <memory>

template <typename TEntity> class ICrudWorker
{
    public:

        virtual ~ICrudWorker(){}

        virtual void setRepository(IRepository_sPtr<TEntity>&) = 0;

        virtual void save(std::shared_ptr<TEntity> obj) = 0;
        virtual void save(const std::unique_ptr<TEntity>& obj) = 0;

        virtual std::unique_ptr<TEntity> read(unsigned long id) = 0;
};

#endif
