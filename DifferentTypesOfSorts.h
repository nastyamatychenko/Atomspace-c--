#pragma once
#include <iostream>
#include <ctime>
class DifferentTypesOfSorts
{
private:
	int *mass;
	int size=10;

public:
	DifferentTypesOfSorts();
	DifferentTypesOfSorts(int *mass, int size);
	~DifferentTypesOfSorts();
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	bool LineurSearch(int key);
	bool BinarySearch(int key);
	void GetMass();
	int GetSize();
	int GetMax();
	int GetMin();
};

