#include <iostream>
#include "DifferentTypesOfSorts.h"
#include <cmath>
#include <vector>

static int Fibonacci(int size);

int main()
{
	std::cout << "\nBubble sort:" << std::endl;
	DifferentTypesOfSorts bubble;
	bubble.GetMass();
	std::cout<<"\nSize of mass:"<<bubble.GetSize()<<std::endl;
	bubble.BubbleSort();
	bubble.GetMass();
	std::cout << "\nMax number is:\t" << bubble.GetMax() << "\t\tMin number is:\t" << bubble.GetMin();
	bubble.~DifferentTypesOfSorts();

	std::cout << "\n\nSelection sort:" << std::endl;
	DifferentTypesOfSorts selectionSort;
	selectionSort.GetMass();
	std::cout<<"\nSize of mass:"<<selectionSort.GetSize()<<std::endl;
	selectionSort.BubbleSort();
	selectionSort.GetMass();
	std::cout << "\nMax number is:\t" << selectionSort.GetMax() << "\t\tMin number is:\t" << selectionSort.GetMin();
	selectionSort.~DifferentTypesOfSorts();

	std::cout << "\n\nInsertion sort:" << std::endl;
	DifferentTypesOfSorts insertionSort;
	insertionSort.GetMass();
	std::cout << "\nSize of mass:" << insertionSort.GetSize() << std::endl;
	insertionSort.BubbleSort();
	insertionSort.GetMass();
	std::cout << "\nMax number is:\t" << insertionSort.GetMax() << "\t\tMin number is:\t" << insertionSort.GetMin();
	insertionSort.~DifferentTypesOfSorts();

	int size;
	std::cout << "\nEnter size of mass:\t";
	std::cin >> size;
	int *mass = new int[size];
	std::cout << "Numbers:\t";
	for (int i = 0; i < size; i++)
	{
		int temp; std::cin >> temp;
		mass[i] = temp;
	}


	std::cout << "Arithmetic sum:\t";
	int arSum = 0,factorial=1;
	for (int i = 0; i < size; i++)
	{
		arSum += mass[i];
		factorial *= i;
	}
	std::cout << arSum;


	std::cout << "Geometric sum:\t";
	double geSum = 1;
	int b, q;
	std::cout << "Enter b and q";
	std::cin >> b >> q;
	geSum =(double)(b * (1.0 - pow(q, size)) / (1.0 - q));
	std::cout << geSum;
	std::cout << " Factorial:\t"<<factorial;
	std::cout << "Fibonacci:\t" << Fibonacci(size);

	char *str = new char[size];
	char *copyStr = new char[size];
	for (int i = 0; i < size; i++)
	{
		char temp; std::cin >> temp;
		str[i] = temp;
		copyStr[i] = str[i];
	}
	std::cout << "\n\nPrint copy of string:\t";
	for(int i=0;i<size;i++)
	{
		std::cout << copyStr[i];
	}
	std::vector<int>  item{ 1, 2, 3, 4, 5 };
	std::vector<int>  copyItem=item;
	std::cout <<"Copy of vector:\t";
	for (auto i = copyItem.rbegin(); i != copyItem.rend(); ++i)
	{
		std::cout << *i;
	}

	return 0;
}

static int Fibonacci(int size)
{
	if (size == 0) return 0;
	if (size == 1) return 1;
	return Fibonacci(size - 1) + Fibonacci(size - 2);
}

