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
	};
}
