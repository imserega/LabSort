#pragma once

#include <iostream>
#include <ctime>
#include <cstring>

#define SIZE_OF_ARRAY 10000
#define RANGE 255
#define ITERATE_CONST 10

class SortingAlgos{
private: 

	
public:

	int binarySearch(int array[], int, int, int);
	void insertionSort(int array[], int size);
	void quickSort(int array[], int low, int high);
	int partition(int array[], int low, int high);
	void swap(int* a, int* b);
	bool isSorted(int a[], int n);
	void shuffle(int a[], int n);
	void bogoSort(int a[], int n);
	void countSort(char arr[]);
};