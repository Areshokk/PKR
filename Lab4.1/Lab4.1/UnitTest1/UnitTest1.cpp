#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4.1/Lab4.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
		public:		
		TEST_METHOD(TestMethod1)
		{


			bool functionResult = search();

			Assert::AreEqual(false, functionResult);
		}
	};
}