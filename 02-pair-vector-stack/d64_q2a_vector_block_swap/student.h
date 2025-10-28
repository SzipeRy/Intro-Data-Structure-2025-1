#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if (m <= 0) {return false;}
  if (a - begin() >= mSize || b - begin()>= mSize || a-begin() < 0 || b-begin() < 0) {return false;}
  if (a + m - 1 - begin() >= mSize || b + m - 1 - begin()>= mSize || a + m - 1 - begin() < 0 || b + m - 1 - begin() < 0) {return false;}

  auto frontA = a - begin();
  auto endA = a + m - 1 - begin();
  auto frontB = b - begin();
  auto endB = b + m - 1 - begin();
  
  if (endA >= frontB && endB > frontA) {return false;}
  if (endB >= frontA && endA > frontB) {return false;}
  for (int i = 0 ; i < m ; i++)
  {
    std::swap(mData[frontA + i], mData[frontB + i]);
  }
  return true;
}

#endif
