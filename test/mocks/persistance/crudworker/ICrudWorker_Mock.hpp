#ifndef IRIS_CRUDWORKER_MOCK_HPP
#define IRIS_CRUDWORKER_MOCK_HPP

#include <definitions/persistance/crudworker/ICrudWorker.hpp>
#include <gmock/gmock.h>

template <typename TEntity> class ICrudWorker_Mock : public ICrudWorker<TEntity>
{
    public:

        MOCK_METHOD1_T(setRepository, void(IRepository_sPtr<TEntity>&));

        MOCK_METHOD1_T(save, void (std::shared_ptr<TEntity> obj));
        MOCK_METHOD1_T(save, void (const std::unique_ptr<TEntity>& obj));

        MOCK_METHOD1_T(read, std::unique_ptr<TEntity> (unsigned long id));
};

#endif
