#include <persistance/crudworker/impl/CrudWorker.hpp>

template <typename TEntity> void 
CrudWorker<TEntity>::setRepository(IRepository_sPtr<TEntity>& repo)
{
	_repo = repo;
}

template <typename TEntity> void 
CrudWorker<TEntity>::save(std::shared_ptr<TEntity> obj)
{
	_repo->save(obj);
}

template <typename TEntity> void 
CrudWorker<TEntity>::save(const std::unique_ptr<TEntity>& obj)
{
	_repo->save(*obj);
}

template <typename TEntity> std::unique_ptr<TEntity> 
CrudWorker<TEntity>::read(unsigned long id)
{
	return _repo->read(id);
}
