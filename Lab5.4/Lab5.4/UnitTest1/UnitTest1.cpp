#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.4/Lab5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char g[6] = "f.dat";
			int t = Search(g, "Gnom");
			Assert::AreEqual(t, -1);
		}
	};
}
