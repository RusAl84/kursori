﻿// kursori.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "KurList.h"
#include "stack.h"

using namespace std;

int main()
{
	////List* ls = new List();
	KurList* kur1 = new KurList;
	//kur1->se
	kur1->init(10); // выделяем 1000 ячеек памяти
	cout << "init!\n";
	kur1->showmas();
	cout << "\n";

	stack* st1 = new stack;
	st1->init(kur1);
	st1->push(10);
	st1->push(20);
	st1->push(30);
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



}
