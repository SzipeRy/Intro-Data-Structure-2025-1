#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include <set>

// IDEA
// make the sort min_element vector

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T min;
  bool first = false;

  for (auto s : pos)
  {
    if (s >= mSize)
    {
    continue;
    }
    if (!first) 
    {
      min = mData[s];
      first = true;
      continue;
    }
    if (!comp(min, mData[s]))
    {
      min = mData[s];
    }
  }

  
  //should return something
  return T(min);
}

#endif
