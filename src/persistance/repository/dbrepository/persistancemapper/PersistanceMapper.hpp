#ifndef IRIS_PERSISTANCEMAPPER_HPP
#define IRIS_PERSISTANCEMAPPER_HPP

#include <memory>

namespace PersistenceMapper
{
	template <typename TEntity, typename TPersistenceEntity = TEntity> std::unique_ptr<TPersistenceEntity> static convert(TEntity& entity)
	{
		return std::make_unique<TEntity>(entity);
	}

	template <typename TPersistenceEntity, typename TEntity = TPersistenceEntity> std::unique_ptr<TEntity> static invert(TPersistenceEntity& entity)
	{
		return std::make_unique<TPersistenceEntity>(entity);
	}
}

#include <persistance/repository/dbrepository/persistancemapper/PersistanceMapper_imp.hpp>

#endif