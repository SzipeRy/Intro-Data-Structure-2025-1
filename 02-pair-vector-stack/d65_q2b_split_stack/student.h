#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  //should return something

  // mData = [0,1,2,3,4,5,6,7,8,9]
  // k = 4
  // vec[0] = [1,5,9] ; pos mSize - 1 - k*n
  // vec[1] = [0,4,8] ; pos mSize - 2 - k*n
  // vec[2] = [3,7]   ; pos mSize - 3 - k*n
  // vec[3] = [2,6]   ; pos mSize - 4 - k*n

  std::vector<std::vector<T>> out(k);
  
  int posVec = (mSize - 1); // need to posVec % k first to access the right index;
  for (int i = 0; i < mSize; i++)
  {
    out[posVec % k].push_back(mData[i]);
    posVec--;
  }
  return out;
}

#endif

