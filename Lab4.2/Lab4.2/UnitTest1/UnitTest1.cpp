#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.2/Lab4.2.cpp"
#include <fstream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            string ex = "RTYERdwssww";
			process();

			ifstream f("t.txt");
			string x;
			while (f >> x)
			Assert::AreEqual(ex,x);

		}
	};
}
