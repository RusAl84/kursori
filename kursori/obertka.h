#pragma once
#include "stack.h"
class obertka
{
private:

	stack* st;
	stack* tst;
public:
	void init(stack* s) {
		st = s;
		stack* temp_stack = new stack;
		tst = temp_stack;
	};

	void GetElement(int pos, stack* s) {
		st = s;
		int sz = st->size();
		int i = 0;
		while (i<)
		{

		}
	};
	void SetElement(int pos, stack* s) {
		st = s;
	};

};

