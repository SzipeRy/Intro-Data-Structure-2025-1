#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  size_t member    = mSize / k;
  size_t remainder = mSize % k;

  size_t m = 0;

  for (int i = 0; i < k; i++)
  {
    std::queue<T> tmp;
    for (int j = 0; j < member; j++)
    {
      tmp.push(mData[(mFront + m) % mCap]);
      m++;
    }
    if (remainder > 0)
    {
      tmp.push(mData[(mFront + m) % mCap]);
      m++;
      remainder--;
    }
    output.push_back(tmp);
  }
}

#endif