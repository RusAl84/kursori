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
	//	������ ��������, ������������ � ������� �����, ����� 0.
	//  init() ������ ����� ������ ����.�������� - ������������ ������ ������
	//	push(item) ��������� ����� ������� �� ������� �����.� �������� ��������� ��������� �������; ������� ������ �� ����������.
	//	pop() ������� ������� ������� �� �����.��������� �� ���������, ������� ���������� �������.���� ����������.
	//	peek() ���������� ������� ������� �����, �� �� ������� ���.��������� �� ���������, ���� �� ��������������.
	//	isEmpty() ��������� ���� �� �������.��������� �� ���������, ���������� ������ ��������.
	//	size() ���������� ���������� ��������� � �����.��������� �� ���������, ��� ���������� - ����� �����.
	void init(KurList* kur) {
		//���� �������� ��������
		kursor = kur;
		head = -1;
		sz = 0;
	};

	//��������� �������� � ����
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
	//�������� �������� �� �����
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

	//��������� �������� �������� ����� ��� ��� ��������
	int peek() {
		if (not isempty())
		{
			return kursor->GetData(head);
		}
		return -1;
	};
	//����������� ������� �����
	bool isempty() {
		if (head == -1)
			return true;
		else
			return false;
	};
	//����� ��������� �����
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

