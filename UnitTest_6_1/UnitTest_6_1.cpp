#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratory_6_1/Array.h"
#include "../Laboratory_6_1/Array.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array A = Array(3);

			for (int i = 0; i < 3; i++)
				A[i] = 0;
			    A[0] = 5;
			    A[1] = 6;
			    A[2] = 10;
			    Assert::AreEqual(A.Arithmetic_mean_absolute_value(), 7.);
		}
	};
}
