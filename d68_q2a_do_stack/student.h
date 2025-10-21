#ifndef _STUDENT_H_INCLUDE_
#define _STUDENT_H_INCLUDE_

#include "stack.h"

template<typename T>
void CP::stack<T>::push(const T &value) {
  //You can write your code below here
  return ;
} 

template <typename T>
void CP::stack<T>::pop() {
  //Do not modify this line
  if (size() == 0) throw std::out_of_range("index of out range") ;
  //You can write your code below here

  return ;
}

template <typename T>
void CP::stack<T>::undo() {
  //You can write your code below here
  return ;
};

template <typename T>
void CP::stack<T>::redo() {
  //You can write your code below here
  return ;
}

#endif