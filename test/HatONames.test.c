#include "../include/unity.h"
#include "../src/HatONames.h"

void setUp(void){}
void tearDown(void){}

void HON_CanLoadNames(void)
{
  HON_hat hat;
  HatONames.InitializeHat(&hat, "./test/testData");

  TEST_ASSERT_EQUAL_INT(2, hat.name_count);
  TEST_ASSERT_EQUAL_STRING("Full Name test A", hat.Names[0].full_name);
  TEST_ASSERT_EQUAL_STRING("Full Name test B", hat.Names[1].full_name);
  TEST_ASSERT_EQUAL_STRING("nickA", hat.Names[0].nickname);
  TEST_ASSERT_EQUAL_STRING("nickB", hat.Names[1].nickname);
}

void HON_CanPullNames(void)
{
  HON_hat hat;
  HatONames.InitializeHat(&hat, "./test/testData");
  HON_name name = HatONames.PullName(hat);
  TEST_ASSERT_EQUAL_INT(2, 2);
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(HON_CanLoadNames);
  RUN_TEST(HON_CanPullNames);

  return UNITY_END();
}

