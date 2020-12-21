#include "pch.h"
#include "CppUnitTest.h"
#include "../laba8.1.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest814
{
	TEST_CLASS(UnitTest814)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char* c = new char(40);
			char q[] = "abc";
			char q1[] = "abc";
			char str[] = "fabck";
			char zamina[] = "***";
			c = change(str, q, q1, zamina);
			Assert::AreEqual(c, "f***k");
		}
	};
}
