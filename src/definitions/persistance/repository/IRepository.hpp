#ifndef IRIS_IREPOSITORY_HPP
#define IRIS_IREPOSITORY_HPP

#include <memory>

template <typename TEntity> class IRepository
{
    public:

        virtual ~IRepository(){}
        
        virtual void save(TEntity& entity) = 0;

        virtual std::unique_ptr<TEntity> read(unsigned long id) = 0;
};

template<typename TEntity> using IRepository_Ptr = std::unique_ptr<IRepository<TEntity>>;
template<typename TEntity> using IRepository_sPtr = std::shared_ptr<IRepository<TEntity>>;

#endif
