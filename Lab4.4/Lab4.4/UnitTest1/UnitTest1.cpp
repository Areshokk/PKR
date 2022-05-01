#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.4/Lab4.4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int ex = 0;
			char fname[100] = "f.txt";

			int l = ProcessTXT(fname);

			Assert::AreEqual(ex, l);
		}
	};
}
