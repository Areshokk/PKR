#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.2/Lab5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			int q = LineSearch(f);
			Assert::AreEqual(0, q);
		}
	};
}
