#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.1\Lab3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab31
{
	TEST_CLASS(UnitTestLab31)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			double a = 4;
			int p = 100;
			
			
			int const i = 1;
			Student* S = new Student[i];

			S->prizvandname = "Yurii";
			S->kurs = 3;
			S->spec = (Specilnist)1;
			S->Physical = 5;
			S->Math = 4;
			S->Informatik = 3;
			
			int x = Percent(S, i);
			double b = Highest(S, i);

			Assert::AreEqual(a, b);
			Assert::AreEqual(p, x);
			
		}
	
	};
}
