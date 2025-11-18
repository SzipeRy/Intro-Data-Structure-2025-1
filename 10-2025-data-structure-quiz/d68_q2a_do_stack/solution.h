#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

/*  push = 0
    pop  = 1 */

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  std::pair<int, T> p = {0, value};
  aux_stack_1.push(p);
  
  while(!aux_stack_2.empty()) aux_stack_2.pop();
  ensureCapacity(mSize + 1);
  mData[mSize] = value;
  mSize++;
  return ;
} 

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here
  std::pair<int, T> tmp = {1, mData[mSize - 1]};
  aux_stack_1.push(tmp);
  
  while(!aux_stack_2.empty()) aux_stack_2.pop();
  mSize--;
  return ;
}

template <typename T>
void CP::stack<T>::undo() {
  //You can write your code below here
  if(aux_stack_1.empty()) return ;
  else {
    if(aux_stack_1.top().first == 0) {
      std::pair<int, T> tmp = {0, aux_stack_1.top().second};
      aux_stack_1.pop();
      aux_stack_2.push(tmp);

      mSize--;
    } 
    else {
      std::pair<int, T> tmp = {1, aux_stack_1.top().second};
      aux_stack_1.pop();
      aux_stack_2.push(tmp);

      ensureCapacity(mSize + 1);
      mData[mSize] = tmp.second;
      mSize++;
    }
    return ;
  }
};

template <typename T>
void CP::stack<T>::redo() {
  //You can write your code below here
  if(aux_stack_2.empty()) return ;
  else {
    if(aux_stack_2.top().first == 0) {
      std::pair<int, T> tmp = {0, aux_stack_2.top().second};
      aux_stack_2.pop();
      aux_stack_1.push(tmp);

      ensureCapacity(mSize + 1);
      mData[mSize] = tmp.second;
      mSize++;
    }
    else {
      std::pair<int, T> tmp = {1, aux_stack_2.top().second};
      aux_stack_2.pop();
      aux_stack_1.push(tmp);

      mSize--;
    }
    return ;
  }
  
}

#endif