#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.3\Lab3.3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33
{
	TEST_CLASS(UnitTestLab33)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int N = 1;


			Zodiac* q = new Zodiac[N];

			q[0].date[0] = 14;
			q[0].date[1] = 11;
			q[0].date[2] = 2002;

			q[0].name = "Billy";
			q[0].surname = "Herington";
			q[0].zodiac_sign = "Scorpio";


			Assert::IsTrue(Search(q, N, "Herington") == 0);
		}
	};
}
