#include "pch.h"
#include "CppUnitTest.h"
#include "D:\ООП\Лабораторні 6\Laboratory_6.4\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int i = 0;
			int arr[3] = { 1337, 69, 1488 };
			Assert::AreEqual(Sort(arr, size(arr), i), 69);
		}
	};
}
