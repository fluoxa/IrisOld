#include <mocks/persistance/repository/IRepository_Mock.hpp>
#include <persistance/crudworker/impl/CrudWorker.hpp>
#include <mocks/helper/MockingHelper.hpp>

using ::testing::Return;
using ::testing::A;
using ::testing::An;
using ::testing::Invoke;

namespace CWTest
{
    class TestClass
    {
        public:

            int testId = 2;
    };
};

class CrudWorkerTest : public ::testing::Test
{
    protected:

        CrudWorkerTest()
        {
            repo = std::make_shared<IRepository_Mock<CWTest::TestClass>>();
        }

        std::shared_ptr<IRepository_Mock<CWTest::TestClass>> repo;
};


TEST_F(CrudWorkerTest, save_sPtr)
{
    auto obj = std::make_shared<CWTest::TestClass>();

    EXPECT_CALL(*repo, save(A<std::shared_ptr<CWTest::TestClass>>()))
        .Times(1);

    CrudWorker<CWTest::TestClass> worker(repo);

    worker.save(obj);
}

TEST_F(CrudWorkerTest, save_uPtr)
{
    auto obj = std::make_unique<CWTest::TestClass>();

    EXPECT_CALL(*repo, save(A<const CWTest::TestClass &>()))
        .Times(1);

    CrudWorker<CWTest::TestClass> worker(repo);

    worker.save(obj);
}

TEST_F(CrudWorkerTest, read)
{
    auto obj = std::make_unique<CWTest::TestClass>();
    obj->testId = 1;

    MockingHelper<CWTest::TestClass> helper;
    helper.storeUniquePointer(obj);

    EXPECT_CALL(*repo, read(An<unsigned long>()))
        .WillOnce(Invoke(&helper, &MockingHelper<CWTest::TestClass>::getStoredPointer<unsigned long>));

    CrudWorker<CWTest::TestClass> worker(repo);

    auto result = worker.read(3);

    ASSERT_FALSE(nullptr == result);
    EXPECT_EQ(1, result->testId);
}
