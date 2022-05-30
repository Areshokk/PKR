#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2A/Lab5.2A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1A
{
	TEST_CLASS(UnitTest1A)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char filename[15] = "f.dat";
			int t = LineSearch(filename);
			Assert::AreEqual(t, 0);
		}
	};
}