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
TEST(PasswordTest, Mix_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAAaAaAAaA");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, all_uppercase_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_lowercase_letters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, single_uppercase_and_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aB");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, no_letters_only_digits_and_symbols)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("123456!@#");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}


TEST(PasswordTest, lowercase_then_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcXYZ");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, uppercase_then_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("XYZabc");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, interleaved_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aAaAaA");
	ASSERT_EQ(true, actual);
}

// Tests for practicing TDD
/* Receives a string and returns a count of how many case-sensitive unique characters there are.
If there are duplicate instances of the same character it should only count as a single character. 
Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters. */
TEST(PasswordTest, unique_characters)
{
	Password my_password;
	int actual = my_password.unique_characters("aAbBcC123!@#aA1");
	ASSERT_EQ(12,actual);
}
TEST(PasswordTest, All_caps )
{
	Password my_password;
	int actual = my_password.unique_characters("ZZZZZ");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, Empty_input )
{
	Password my_password;
	int actual = my_password.unique_characters("");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, Uppercase_lowercase )
{
	Password my_password;
	int actual = my_password.unique_characters("Zz");
	ASSERT_EQ(2,actual);
}
TEST(PasswordTest, space_numbers_letters)
{
	Password my_password;
	int actual = my_password.unique_characters(" 123 abc");
	ASSERT_EQ(7,actual);
}