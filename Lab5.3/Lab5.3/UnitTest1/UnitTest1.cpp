#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.3/Lab5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab53A
{
	TEST_CLASS(UnitTestLab53A)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			char g[6] = "g.dat";
			int t = BinSearch(g, "t", 5, 5);
			Assert::AreEqual(t, -1);
		}
	};
}