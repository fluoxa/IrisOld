#include <gtest/gtest.h>
#include <common/iocfactory/IocFactory.hpp>

class IocFactoryTest : public ::testing::Test 
{
    protected:

        virtual void TearDown()
        {
            IocFactory::flushRegisters();
        }
};

class ITestClass
{
    public:

        ~ITestClass(){}
        virtual const char* success() {return "no success";};
};

class TestClass : public virtual ITestClass
{
    public:

        TestClass(int num = 0 )
        { _num = num; }

        virtual const char* success()
        {
            std::stringstream stream;
            stream << "success " << _num;

            return stream.str().c_str();
        }

    private:

        int _num;
};

TEST_F(IocFactoryTest, getSharedInstance)
{
    IocFactory::registerIocContainer(IocContainer().forService<ITestClass>().implementedBy<TestClass>());

    auto ioc = IocFactory::getSharedInstance<ITestClass>();

    EXPECT_STREQ(typeid(std::shared_ptr<ITestClass>).name(), typeid(ioc).name());
    EXPECT_STREQ(TestClass().success(), ioc->success());
}

TEST_F(IocFactoryTest, getUniqueInstance)
{
        auto container = IocContainer().forService<ITestClass>().implementedBy<TestClass>();
        IocFactory::registerIocContainer(container);

        auto ioc = IocFactory::getUniqueInstance<ITestClass>();

        EXPECT_STREQ(typeid(std::unique_ptr<ITestClass>).name(), typeid(ioc).name());
        EXPECT_STREQ("success 0", ioc->success());
}

TEST_F(IocFactoryTest, flushRegister)
{
    IocFactory::registerIocContainer(IocContainer().forService<ITestClass>().implementedBy<TestClass>());

    auto ioc = IocFactory::getSharedInstance<ITestClass>();

    EXPECT_STREQ(typeid(std::shared_ptr<ITestClass>).name(), typeid(ioc).name());

    IocFactory::flushRegisters();

    ASSERT_THROW( IocFactory::getSharedInstance<ITestClass>(), BaseException);
}

TEST_F(IocFactoryTest, getUniqueInstance_ByCustomFactory)
{
    auto factory = [&]() -> TestClass*
    {
        return new TestClass(2);
    };

    IocFactory::registerIocContainer(IocContainer().forService<ITestClass>().implementedBy<TestClass>(std::cref(factory)));

    auto ioc = IocFactory::getUniqueInstance<ITestClass>();

    EXPECT_STREQ(typeid(std::unique_ptr<ITestClass>).name(), typeid(ioc).name());
    EXPECT_STREQ("success 2", ioc->success());
}
