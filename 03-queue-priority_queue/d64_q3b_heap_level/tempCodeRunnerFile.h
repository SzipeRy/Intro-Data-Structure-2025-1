#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include <math.h>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;

  size_t start = pow(2,k) - 1;
  size_t end   = pow(2,k) + start;
  if (end >= mSize)
  {
    end = mSize - 1;
  }
  if (start >= mSize)
  {
    return r;
  }

  for (size_t i = start ; i < end; i++)
  {
    r.push_back(mData[i]);
  }
  std::sort(r.begin(), r.end(), std::greater<T>());
  return r;
}

#endif

