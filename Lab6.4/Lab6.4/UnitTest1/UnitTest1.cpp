#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab6.4\Lab6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;
			for (int i = 0; i < 15; i++)
				Insert(L, i);
			int x = Count(L);

			Assert::AreEqual(15, x);
		}
	};
}
