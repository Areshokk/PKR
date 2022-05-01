#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1/Lab5.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			char g[6] = "g.dat";
			ProcessBin(f, g);
		}
	};
}
