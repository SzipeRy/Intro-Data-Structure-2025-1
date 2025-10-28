#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>

#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  std::vector<T> tmp(7);
  int max = 7;
  if (max > mSize)
  {
    max = mSize;
  }
  for (int i = 0; i < max; i++)
  {
    tmp[i] = mData[i];
  }
  std::sort(tmp.begin(), tmp.end());

  return tmp[k-1];
  //can include anything
}

#endif
