#include <fstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.3/Lab4.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		
			string d = "YuriiOven4.4.2002VladTa14.2.2002qwertOven2.4.2001erwe3.3.2001";
			
			ifstream f("f.txt");
			string x;
			while (f >> x)
			Assert::AreEqual(d, x);
			
		}
	};
}
