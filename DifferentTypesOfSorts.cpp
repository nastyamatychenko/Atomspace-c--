#include "DifferentTypesOfSorts.h"

DifferentTypesOfSorts::DifferentTypesOfSorts()
{
	mass = new int[size];
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 100;
	}
}


DifferentTypesOfSorts::DifferentTypesOfSorts(int *mass,int size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		this->mass[i] = mass[i];
	}
}


void DifferentTypesOfSorts::BubbleSort()
{
	int startIndex = 0;
	bool is_flag = true;
	while (is_flag)
	{
		is_flag = false;
		for (int currentIndex = 0; currentIndex < size - startIndex - 1; currentIndex++)
		{
			if (mass[currentIndex] > mass[currentIndex + 1])
			{
				std::swap(mass[currentIndex], mass[currentIndex + 1]);
				is_flag = true;
			}
		}
		startIndex++;
	}
}


void DifferentTypesOfSorts::SelectionSort()
{
	for (int startIndex = 0; startIndex < size; startIndex++)
	{
		for (int currentIndex = startIndex - 1; currentIndex >= 0 && mass[currentIndex] > mass[startIndex]; currentIndex--)
		{
			std::swap(mass[currentIndex], mass[startIndex]);
		}
	}
}

void DifferentTypesOfSorts::InsertionSort()
{
	for (int startIndex = 0; startIndex < size - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; currentIndex++)
		{
			if (mass[currentIndex] < mass[smallestIndex])
			{
				smallestIndex = currentIndex;
			}
		}
		std::swap(mass[startIndex], mass[smallestIndex]);
	}
}

bool DifferentTypesOfSorts::LineurSearch(int key)
{
	for (int i = 0; i < size; i++)
	{
		//comparisonCount = i + 1;
		if (mass[i] == key)
		{
			return true;
		}
	}
	return false;
}

bool DifferentTypesOfSorts::BinarySearch(int key)
{
	int low = 0;
	int hight = size - 1;
	int mid;

	while (low <= hight)
	{
		mid = (low + hight) / 2;
		//comparisonCount++;

		if (key == mass[mid])
		{
			return true;
		}
		else if (key > mass[mid])
		{
			low = mid + 1;
		}
		else if (key < mass[mid])
		{
			hight = mid - 1;
		}
	}

	return false;
}

void DifferentTypesOfSorts::GetMass()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << mass[i] << " ";
		std::cout.width(5);
	}
}

int DifferentTypesOfSorts::GetSize()
{
	return size;
}

int DifferentTypesOfSorts::GetMax()
{
	int max =mass[0];
	for (int i = 0; i < size; i++)
	{
		if (mass[i] > max)
		{
			max = mass[i];
		}
	}
	return max;
}

int DifferentTypesOfSorts::GetMin()
{
	int min = mass[0];
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < min)
		{
			min = mass[i];
		}
	}
	return min;
}


DifferentTypesOfSorts::~DifferentTypesOfSorts()
{
	delete[] mass;
	mass = nullptr;
}
