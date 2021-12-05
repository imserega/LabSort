#include <iostream>
#include <cstring>
#include "pch.h"
#include "CppUnitTest.h"
#include "../LabSort/LabSort.h"
#include "../LabSort/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BinarySearchTest1)
		{
			
			SortingAlgos sort;
			int arr[5] = { 1, 2, 3, 4, 5 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int x = 3;
			int answ = 0;
			for (int i = 0; i <= sort.binarySearch(arr, x, 0, size - 1); ++i) {
				if (i == sort.binarySearch(arr, x, 0, size - 1))
					answ = arr[i];
			}
			
			Assert::AreEqual(x, answ);
		}
		TEST_METHOD(BinarySearchTest2)
		{
			SortingAlgos sort;
			int arr[5] = { 1, 2, 4, 5, 6 };
			int size = sizeof(arr) / sizeof(arr[0]);
			int x = 3;
			int answ = 0;
			for (int i = 0; i <= sort.binarySearch(arr, x, 0, size - 1); ++i) {
				if (i == sort.binarySearch(arr, x, 0, size - 1))
					answ = arr[i];
			}
			Assert::IsTrue(answ == 0);
		}
		
		TEST_METHOD(QuickSortTest1)
		{
			SortingAlgos sort;
			int array_data[] = { 4, 2, 5, 1, 7, 10, 6, 11 };
			int array_check[] = { 1, 2, 4, 5, 6, 7, 10, 11 };
			int size = sizeof(array_data) / sizeof(array_data[0]);
			sort.quickSort(array_data, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array_data[i], array_check[i]);
			}
		}

		TEST_METHOD(InsertionSortTest1)
		{
			SortingAlgos sort;
			int array_data[] = { 55, 100, 5, 1, 23, 10, 17, 11 };
			int array_check[] = { 1, 5, 10, 11, 17, 23, 55, 100 };
			int size = sizeof(array_data) / sizeof(array_data[0]);
			sort.quickSort(array_data, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array_data[i], array_check[i]);
			}


		}
		TEST_METHOD(BogoSortTest1)
		{
			SortingAlgos sort;
			int array_data[] = { 1002, 100, 5829, 10032, 288, 223, 81, 1100 };
			int array_check[] = { 81, 100, 223, 288, 1002, 1100, 5829, 10032 };
			int size = sizeof(array_data) / sizeof(array_data[0]);
			sort.quickSort(array_data, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array_data[i], array_check[i]);
			}


		}
		TEST_METHOD(CountSortTest1)
		{
			SortingAlgos sort;
			char str_data[] = "helloiiiimmmsseerrggeeiii";
			char str_check[] = "eeeeegghiiiiiiillmmmorrss";
			int count = 0;
			sort.countSort(str_data);
			if (strcmp(str_data, str_check)) {
				++count;
			}
			Assert::AreEqual(0, count);



		}
	};
}
