#ifndef AIUNIT_IREPOSITORY_HPP
#define AIUNIT_IREPOSITORY_HPP

#include <memory>

template <typename TEntity> class IRepository
{
    public:

        virtual ~IRepository(){}
        
        virtual void save(const TEntity& entity) = 0;
        virtual void save(std::shared_ptr<TEntity> entity) = 0;
                
        virtual void read(unsigned long id, TEntity& entity) = 0;
        virtual void read(unsigned long id, std::shared_ptr<TEntity> entity) = 0;
};

template<typename TEntity> using IRepository_Ptr = std::unique_ptr<IRepository<TEntity>>;
template<typename TEntity> using IRepository_sPtr = std::shared_ptr<IRepository<TEntity>>;

#endif //AIUNIT_IREPOSITORY_HPP
