#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1 IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71IT
{
	TEST_CLASS(UnitTest71IT)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rowCount = 8;
            int colCount = 5;
            int** R = new int* [2];
            for (int i = 0; i < 2; R[i++] = new int[2]);

            R[0][0] = 2;
            R[0][0] = 0;
            R[0][0] = -1;
            R[1][1] = 1;

            Change(R, 0, 1, 2);
           
            Assert::AreEqual(1, R[0][1]);
		}
	};
}
