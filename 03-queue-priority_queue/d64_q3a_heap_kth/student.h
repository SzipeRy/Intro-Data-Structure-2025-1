#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>

#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  bool greater = false;
  std::vector<T> tmp;
  int max = 7;
  if (max > mSize)
  {
    max = mSize;
  }
  for (int i = 0; i < max; i++)
  {
    tmp.push_back(mData[i]);
  }

  if (mData[0] <= mData[1] && mData[0] <= mData[2])
  {
    greater = true;
  }
  if (greater)
  {
    std::sort(tmp.begin(), tmp.end());
  }
  else
  {
    std::sort(tmp.rbegin(), tmp.rend());
  }

  return tmp[k-1];
  //can include anything
}

#endif
