#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

#include <stack>
#include <queue>

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here
	if (first >= last)
	{
		return;
	}
	
	std::stack<T> rest;
	std::queue<T> rev;

	for (int i = 0; i < first; i++)
	{
		rest.push(top());
		pop();
	}

	for (int i = first; i <= last; i++)
	{
		rev.push(top());
		pop();
	}

	while (!rev.empty())
	{
		push(rev.front());
		rev.pop();
	}

	while (!rest.empty())
	{
		push(rest.top());
		rest.pop();
	}
}

#endif
