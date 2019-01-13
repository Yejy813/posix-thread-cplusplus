#include <gmock/gmock.h>
#include "lib/mail_service.h"
#include "lib/order.h"
#include "lib/warehouse.h"

using ::testing::Return;
using ::testing::_; // Matcher for parameters

class MockWarehouse : public Warehouse
{
public:
    
    // see https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
    MOCK_CONST_METHOD2(hasInventory, bool(int, std::string));
    MOCK_METHOD2(remove, void(int, std::string));
};

class MockMailService : public MailService
{
public:
    MockMailService()
    {
        
    }
    
    MOCK_METHOD1(send, void(std::string));
};

TEST(OrderTest, Fill)
{
    MockWarehouse warehouse;
    std::shared_ptr<MockMailService> mailService = std::make_shared<MockMailService>();
    
    Order order(50, "Talisker");
    order.setMailService(mailService);
    
    EXPECT_CALL(warehouse, hasInventory(50, "Talisker"))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(warehouse, remove(50, "Talisker"))
        .Times(1);
    
    EXPECT_CALL(*mailService, send(_)) // Not making assumptions on the message send ...
        .Times(1);
    
    ASSERT_TRUE(order.fill(warehouse));
}


int main(int argc, char **argv)
{
  testing::InitGoogleMock(&argc, argv);

  // Runs all tests using Google Test.
  return RUN_ALL_TESTS();
}
