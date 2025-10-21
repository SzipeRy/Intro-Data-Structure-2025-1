#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  
  
  if (m <= 0) {return false;}
  if (a - begin() > mSize || b - begin()> mSize || a-begin() < 0 || b-begin() < 0) {return false;}
  if (a + m - 1 - begin() > mSize || b + m - 1 - begin()> mSize) {return false;}

  // T* out = new T[mSize]();
  // std::vector<T> swap;
  // std::vector<T> first(m);
  // std::vector<T> second(m);

  // for (int i = 0; i < m; i++)
  // {
  //   swap.push_back(a - begin() + i);
  //   swap.push_back(b - begin() + i);

  //   first.push_back(mData[a - begin() + i]);
  //   second.push_back(mData[b -begin() + i]);
  // }
  // std::sort(swap.begin(), swap.end());

  // for (int i = 0; i < m; i++)
  // {
  //   out[a - begin() + i] = second[i];
  //   out[b - begin() + i] = first[i];
  // }
  
  // int k = 0;
  // for (int i = 0; i < mSize; i++)
  // {
  //   if (i == swap[k])
  //   {
  //     k++;
  //   }
  //   else
  //   {
  //     out[i] = mData[i];
  //   }
  // }
  
  // delete [] mData;

  // mData = out;
  // mSize = mSize;
  // mCap = mSize;

  for (int i = 0 ; i < m ; i++)
  {
    std::swap(mData[a- begin() + i], mData[b - begin() +i]);
  }
  return true;
}

#endif
