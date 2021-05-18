#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratory_6.7/Array.h"
#include "../Laboratory_6.7/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest67
{
	TEST_CLASS(UnitTest67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 3;
			Array res = Array(size);
			for (int i = 0; i < size; i++)
			{
				res[i] = 1.1;
			}
			Assert::AreEqual(3.3, res.Sum(), 0.1);
		}
	};
}
