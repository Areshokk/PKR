#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.5/Lab6.5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* top = NULL;
			readTXT(top);
			Assert::AreEqual(count(top), 15);
		}
	};
}
