#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11_1/lab_11_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream f("test.dat", ios::binary);
			for (int i = -5; i <= 1; i++)	{
				f.write((char*)&i, sizeof(i));
			}
			f.close();
			Process("test.dat", "utest.dat");
			ifstream file("utest.dat", ios::binary);
			int x;
			file.read((char*)&x, sizeof(x));
			Assert::AreEqual(x, 1);
			
		}
	};
}
