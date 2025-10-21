#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>

// let A be the default stack
// B is for bottom push stack
// for bottom_top, check if B.empty?
	// if B is empty -> check the first available mData in A
	// if not -> top of B

// for bottom_pop, check if B.empty?
	// if B is empty -> skip the bottom value in A
	// if not -> pop the top of B

// for access bottom data
// if B is empty -> check the A
// if B is not empty -> B top is the value

// What if stack A is empty and stack B become main stack?
// Move everything from stack B to stack A


template <typename T>
void CP::stack<T>::pop() {
	// modify method here
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	return stack_a.top();
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here
	if (!stack_b.empty())
	{
		return stack_b.top();
	}
	else
	{
		std::vector<T> tmpA;

		while(!stack_a.empty())
		{
			T tmp = stack_a.top();
			stack_a.pop();
			tmpA.push_back(tmp);
		}
		
		T target = *tmpA.rbegin();
		while(!tmpA.empty())
		{
			T tmp = *tmpA.rbegin();
			tmpA.pop_back();
			stack_a.push(tmp);
		}
		return target;
	}
	
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here

}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here

}
#endif