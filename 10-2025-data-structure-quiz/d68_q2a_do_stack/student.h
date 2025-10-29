#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  if (mSize >= mCap)
  {
    ensureCapacity(mSize);
  }
  mData[mSize++] = value;
  aux_stack_1.push({0, value});
  while(!aux_stack_2.empty()) 
  {
    aux_stack_2.pop();
  }
  return ;
} 

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here
  aux_stack_1.push({1, mData[mSize-1]});
  mSize--;
  while(!aux_stack_2.empty()) 
  {
    aux_stack_2.pop();
  }
  return ;
}

template <typename T>
void CP::stack<T>::undo() {
  //You can write your code below here
  if (aux_stack_1.size() == 0)
  {
    return;
  }
  // if the last operation is "push"
  if (aux_stack_1.top().first == 0)
  {
    mSize--;
    aux_stack_2.push({0, aux_stack_1.top().second});
  }
  // if the last operation is "pop"
  else
  {
    if (mSize >= mCap)
    {
      ensureCapacity(mSize + 1);
    }
    aux_stack_2.push( {1, aux_stack_1.top().second});
    mData[mSize] = aux_stack_1.top().second;
    mSize++;
  }

  aux_stack_1.pop();
  return ;
};

template <typename T>
void CP::stack<T>::redo() {
  //You can write your code below here
  if (aux_stack_2.size() == 0)
  {
    return;
  }

  if (aux_stack_2.top().first == 0)
  {
    if (mSize >= mCap)
    {
      ensureCapacity(mSize + 1);
    }
    mData[mSize++] = aux_stack_2.top().second;
    aux_stack_1.push( {0, aux_stack_2.top().second});
  }
  else
  {
    mSize--;
    aux_stack_1.push( {1, aux_stack_2.top().second});
  }

  aux_stack_2.pop();
  return ;
}

#endif