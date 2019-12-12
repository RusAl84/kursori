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
		//while (pos <= nomer)
		{
			//temp_stack->push(st->pop());

		}
	}
	return -1;
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
	st1->push(5);
	st1->push(2);
	st1->push(8);
	st1->push(16);
	st1->push(1);
	st1->push(19);
	st1->push(22);
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



}

