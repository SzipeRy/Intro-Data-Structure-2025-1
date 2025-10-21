#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "vector.h"


template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  // Write code here
  std::set<T> uniqueValue;
  std::vector<T> pos;

  std::sort(itrs.begin(), itrs.end());
  for(auto &x : itrs)
  {
    if (uniqueValue.find(*x) == uniqueValue.end())
    {
      uniqueValue.insert(*x);
      continue;
    }
    pos.push_back(x - begin());
  }
  std::sort(pos.begin(), pos.end());

  T* out = new T[mSize];
  // i for the whole mData
  // j for the selection
  // k for check the pos
  size_t j = 0;
  size_t k = 0;

  for (int i = 0 ; i < mSize; i++)
  {
    if (i == pos[k])
    {
      k++;
      continue;
    }
    out[j] = mData[i];
    j++;
  }

  delete [] mData;

  mData = out;
  mSize = j;
  mCap = mSize;
}

#endif
