#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab6.3\Lab6.3.cpp"

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

			Create(first, last);

			Assert::AreEqual(Count(first,3), 1);
		}
	};
}
