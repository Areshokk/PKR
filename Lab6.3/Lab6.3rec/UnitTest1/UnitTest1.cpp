#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab6.3rec\Lab6.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

			Create(first, last, 0);
			int q = 3, res = 0;
			Assert::AreEqual(count(first, last, first, res, q), 1);
		}
	};
}
