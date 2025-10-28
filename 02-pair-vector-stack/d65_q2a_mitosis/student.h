#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <vector>
template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    // CP::stack<T> tmpStack;
    // CP::stack<T> out;
    std::vector<T> tmpStack;
    T* out = new T[mSize + (b - a + 1)]();
    int pos = 0;
    for (int i = mSize - 1; i >= 0; i--)
    {
        T value = mData[i];
        tmpStack.push_back(value);
        if (a <= pos && pos <= b)
        {
            tmpStack.push_back(value);
        }
        pos++;
    }
    // while (!tmpStack.empty())
    // {
    //     T value = tmpStack.top();
    //     tmpStack.pop();
    //     out.push(value);
    // }

    pos = tmpStack.size() - 1;
    for (int i = 0; i < tmpStack.size(); i++)
    {
        out[pos] = tmpStack[i];
        pos--;
    }
    
    delete [] mData;

    mData = out;
    mSize += b - a + 1;
    mCap = mSize;
}

#endif