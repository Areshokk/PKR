
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.1c/Lab4.1c.cpp"

#define N 512

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			bool functionResult = find();

			Assert::AreEqual(true, functionResult);
		}
	};
}