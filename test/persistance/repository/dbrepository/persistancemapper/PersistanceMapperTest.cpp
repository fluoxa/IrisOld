#include <gtest/gtest.h>
#include <persistance/repository/dbrepository/persistancemapper/PersistanceMapper.hpp>

#include <iostream>

TEST(PersistanceMapper, convert_without_template_parameter)
{
	double test = 2.0;
	
	auto result = PersistenceMapper::convert(test);
	
	EXPECT_FALSE(nullptr == result);
	EXPECT_STREQ(typeid(std::unique_ptr<double>).name(), typeid(result).name());
	EXPECT_TRUE((*result-2.)*(*result-2.) < 1e-14);
}
