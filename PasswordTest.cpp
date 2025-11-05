/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, empty_pass)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, Special_Characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("$$ddd");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, Mix_of_same_lower_and_upper_letter)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAaAaAAaA");
	ASSERT_EQ(3, actual);
}