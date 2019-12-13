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
	st1->show();

	int n = st1->size(); //n - количество элементов

	//Пишем обертку
	//int elem = getElement(5, st1, kur1);
	//cout << "\n" << elem <<"\n";
	setElement(0,777, st1, kur1);

	st1->show();


}

