#ifndef IRIS_MOCKIREPOSITORY_HPP
#define IRIS_MOCKIREPOSITORY_HPP

#include <definitions/persistance/repository/IRepository.hpp>
#include <gmock/gmock.h>

template <typename TEntity> class IRepository_Mock : public IRepository<TEntity>
{
    public:

        MOCK_METHOD1_T(save, void(TEntity&));
        MOCK_METHOD1_T(save, void(std::shared_ptr<TEntity>));

        MOCK_METHOD1_T(read, std::unique_ptr<TEntity> (unsigned long id));
};

#endif //IRIS_MOCKIREPOSITORY_HPP
