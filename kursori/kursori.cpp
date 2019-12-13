// kursori.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "KurList.h"
#include "stack.h"

using namespace std;
int getElement(int nomer, stack* st, KurList* kur1){
	if ((nomer >= 0) and (nomer < st->size()))
	{
	
		stack* temp_stack = new stack;
		temp_stack->init(kur1);
		int pos = 0;
		while (pos < nomer)
		{
			temp_stack->push(st->pop());
			pos++;
		}
		int element = st->peek();
		while (not temp_stack->isempty())
		{
			st->push(temp_stack->pop());
		}
		return element;
	}
	return -1;
}

bool setElement(int nomer, int element,  stack* st, KurList* kur1) {
	if ((nomer >= 0) and (nomer < st->size()))
	{

		stack* temp_stack = new stack;
		temp_stack->init(kur1);
		int pos = 0;
		while (pos < nomer)
		{
			temp_stack->push(st->pop());
			pos++;
		}
		st->pop();
		st->push(element);
		while (not temp_stack->isempty())
		{
			st->push(temp_stack->pop());
		}
		return true;
	}
	return false;
}

// A utility function to swap two elements 
void swap(stack* st, KurList* kur1, int i, int j)
{
	int ii = getElement(i, st, kur1);
	int jj = getElement(j, st, kur1);
	setElement(i, jj, st, kur1);
	setElement(j, ii, st, kur1);
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(stack* st, KurList* kur1, int low, int high)
{
	//int pivot = arr[high];    // pivot 
	int pivot = getElement(high, st, kur1);
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		//if (arr[j] <= pivot)
		if (getElement(j, st, kur1) <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(st, kur1, i, j);
			//swap(&arr[i], &arr[j]); 
		}
	}
	//swap(&arr[i + 1], &arr[high]);
	swap(st, kur1, i+1, high);
	return (i + 1);
}
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(stack* st, KurList* kur1, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(st, kur1, low, high);
		//int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(st, kur1, low, pi - 1);
		quickSort(st, kur1, pi + 1, high);
		//quickSort(arr, low, pi - 1);
		//quickSort(arr, pi + 1, high);
	}
}
int main()
{
	//List* ls = new List();
	KurList* kur1 = new KurList;
	//kur1->se
	kur1->init(100); // выделяем 100 ячеек памяти
	//cout << "init!\n";
	//kur1->showmas();
	//cout << "\n";

	stack* st1 = new stack;
	st1->init(kur1);
	st1->push(10);
	st1->push(7);
	st1->push(8);
	st1->push(9);
	st1->push(1);
	st1->push(5);
	/*cout << st1->peek() << "\n";  // для отладки
	cout << "stack!\n";
	kur1->showmas();
	cout << "\n";
	cout << "stack!\n";
	while (not st1->isempty()) {
		cout << st1->size() << "\n";
		cout << st1->pop()<<"\n";
	};
	cout << "\n";*/
	cout << "Unsorted array:\n";
	st1->show();

	int n = st1->size(); //n - количество элементов
	quickSort(st1, kur1, 0, n - 1);
	printf("Sorted array: n");
	st1->show();
	//Пишем обертку - отладка
	//int elem = getElement(5, st1, kur1);
	//cout << "\n" << elem <<"\n";
	//setElement(0,777, st1, kur1);
	//st1->show();


}

