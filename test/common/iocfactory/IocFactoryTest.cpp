#include <gtest/gtest.h>
#include <common/iocfactory/IocFactory.hpp>

class IocFactoryTest : public ::testing::Test {

    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        IocFactoryTest()
        {
            // You can do set-up work for each test here.

        }

        virtual ~IocFactoryTest()
        {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        virtual void SetUp()
        {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        virtual void TearDown()
        {
            // Code here will be called immediately after each test (right
            // before the destructor).

            IocFactory::flushRegisters();
        }

        // Objects declared here can be used by all tests in the test case for Foo.

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