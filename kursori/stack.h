#pragma once
#include <iostream>

#include "KurList.h"
class stack
{
private:
		int head;
		KurList* kursor;
		int sz;
public: 
	//	Индекс элемента, находящегося в вершине стека, равен 0.
	//  init() создаёт новый пустой стек.Параметр - динамический массив курсор
	//	push(item) добавляет новый элемент на вершину стека.В качестве параметра выступает элемент; функция ничего не возвращает.
	//	pop() удаляет верхний элемент из стека.Параметры не требуются, функция возвращает элемент.Стек изменяется.
	//	peek() возвращает верхний элемент стека, но не удаляет его.Параметры не требуются, стек не модифицируется.
	//	isEmpty() проверяет стек на пустоту.Параметры не требуются, возвращает булево значение.
	//	size() возвращает количество элементов в стеке.Параметры не требуются, тип результата - целое число.
	void init(KurList* kur) {
		//надо дописать проверки
		kursor = kur;
		head = -1;
		sz = 0;
	};

	//Помещение элемента в стек
	void push(int elem) {
		if (isempty())
		{
			head = kursor->GetElement(elem,-1);
		}
		else
		{
			int temp = head;
			head = kursor->GetElement(elem,-1);
			kursor->SetNext(head, temp);
		}
		sz++;
	};
	//Удаление элемента из стека
	int pop() {
		sz--;
		if (not isempty())
		{
			int temp = head;
			int znach = kursor->DelElement(head);
			head = kursor->GetNext(temp);
			return znach;
		}
		return -1;
	};

	//Получение верхнего элемента стека без его удаления
	int peek() {
		if (not isempty())
		{
			return kursor->GetData(head);
		}
		return -1;
	};
	//Определение пустоты стека
	bool isempty() {
		if (head == -1)
			return true;
		else
			return false;
	};
	//Вывод элементов стека
	int size() {
		return sz;
	};
	void show() {
		std::cout <<  "show stack\n";
		if (not isempty()) {
			int next = head;
			while (next !=-1) {
				std::cout << kursor->GetData(next) << "\n";
				next = kursor->GetNext(next);
			}
		}
	};

};

