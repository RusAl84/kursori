#pragma once
#include <iostream>

struct element // Структура элемента
{
	int data;
	int next;
};

class KurList  // Массив - куча памяти
{
private:
	element* mas;
	int head;
public:
	int init(int size){
		// размер массива
		head = 0;
		element* p_darr = new element[size]; // Выделение памяти для массива
		for (int i = 0; i < size-1; i++) {
			// Заполнение массива
			p_darr[i].data = -1;
			p_darr[i].next = i+1;
		}
		p_darr[size-1].next = -1;
		p_darr[size - 1].data = -1;
		mas = p_darr;
		return 0;
	}
	int GetElement(int data,int next) {  // эквивалент операции new
		int temp = head;
		head = mas[head].next;
		mas[temp].data = data;
		mas[temp].next = next;
		return temp;
	};
	int GetNext(int nomer) {
		if (nomer >= 0)
		return mas[nomer].next;
	};
	int GetData(int nomer) {
		if (nomer >=0)
				return mas[nomer].data;
	};
	void SetNext(int nomer, int next) {
		mas[nomer].next =next;
	};
	int DelElement(int next) { // эквивалент операции delete
		int data = mas[next].data;
		mas[next].data = -1;
		mas[next].next ;
		head = next;
		return data;
	};
	
	void showmas() { // вывести массив на экран
		int dlina = _msize(mas) / sizeof(element); //размер массива
		for (int i = 0; i < dlina; i++) {
			std::cout <<"next:" <<mas[i].next << "  data:" << mas[i].data << std::endl;
		}
	}

};

