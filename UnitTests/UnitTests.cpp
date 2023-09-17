#include "pch.h"
#include "CppUnitTest.h"
#include "../e_p/e_p.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(check_ordinal_and_cardinal_pronouns_ordinalNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("first");
			std::string expStr = "Неправильное употребление порядковых числительных. Должно быть  “first”.";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(check_ordinal_and_cardinal_pronouns_cardinalNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("one");
			std::string expStr = "Неправильное употребление числительных. Должно быть  “one”.";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(check_ordinal_and_cardinal_pronouns_ordinalComplexNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("twenty-seventh");
			std::string expStr = "Неправильное употребление порядковых числительных. Должно быть “twenty-seventh”.";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(check_ordinal_and_cardinal_pronouns_noNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("boxes");
			std::string expStr = "";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(get_needed_chars_getZeroChars)
		{
			std::string s = get_needed_chars("abcd", 1, 0);
			std::string expStr = "";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(get_needed_chars_getSingleChar)
		{
			std::string s = get_needed_chars("abcd", 3, 1);
			std::string expStr = "d";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(get_needed_chars_getFewChars)
		{
			std::string s = get_needed_chars("abcd", 1, 2);
			std::string expStr = "bc";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(get_needed_chars_offsetZero)
		{
			std::string s = get_needed_chars("abcd", 0, 2);
			std::string expStr = "ab";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(to_lower_string_singleChar)
		{
			std::string s = "A";
			to_lower_string(s);
			std::string expStr = "a";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(to_lower_string_fewChars)
		{
			std::string s = "ABCD";
			to_lower_string(s);
			std::string expStr = "abcd";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(to_lower_string_spacedChars)
		{
			std::string s = "AB CD";
			to_lower_string(s);
			std::string expStr = "ab cd";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(to_lower_string_lowerStr)
		{
			std::string s = "abcd";
			to_lower_string(s);
			std::string expStr = "abcd";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(to_lower_string_lowerUpperStr)
		{
			std::string s = "AbCd";
			to_lower_string(s);
			std::string expStr = "abcd";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(split_spacedStr)
		{
			std::vector<std::string> s = split("hello world", ' ');
			std::vector<std::string> expVec = {"hello", "world"};

			for (int i = 0; i < expVec.size(); i++)
				Assert::AreEqual(expVec[i], s[i]);
		}

		TEST_METHOD(split_charDelimiter)
		{
			std::vector<std::string> s = split("hello-world", '-');
			std::vector<std::string> expVec = { "hello", "world" };

			for (int i = 0; i < expVec.size(); i++)
				Assert::AreEqual(expVec[i], s[i]);
		}

		TEST_METHOD(split_singleWord)
		{
			std::vector<std::string> s = split("hello", ' ');
			std::vector<std::string> expVec = { "hello" };

			for (int i = 0; i < expVec.size(); i++)
				Assert::AreEqual(expVec[i], s[i]);
		}

		TEST_METHOD(split_singleChar)
		{
			std::vector<std::string> s = split("h", ' ');
			std::vector<std::string> expVec = { "h" };

			for (int i = 0; i < expVec.size(); i++)
				Assert::AreEqual(expVec[i], s[i]);
		}
	};
}
