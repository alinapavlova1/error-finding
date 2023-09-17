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
			std::string expStr = "������������ ������������ ���������� ������������. ������ ����  �first�.";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(check_ordinal_and_cardinal_pronouns_cardinalNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("one");
			std::string expStr = "������������ ������������ ������������. ������ ����  �one�.";

			Assert::AreEqual(expStr, s);
		}

		TEST_METHOD(check_ordinal_and_cardinal_pronouns_ordinalComplexNumberError)
		{
			std::string s = check_ordinal_and_cardinal_pronouns("twenty-seventh");
			std::string expStr = "������������ ������������ ���������� ������������. ������ ���� �twenty-seventh�.";

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


	};
}
