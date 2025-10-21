#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  CP::vector<T> out(mSize+data.size());
  std::sort(data.begin(), data.end());
  
  for(int i = 0; i < data.size(); i++)
  {
    out[data[i].first + i] = data[i].second;
  }
  int pos = 0;
  for(int i = 0; i < mSize; i++)
  {
    if (out[pos] != 0)
    {
      pos++;
    }
    out[pos] = mData[i];
    pos++;
  }

  delete [] mData;

  mData = out.mData;
  mSize = out.mSize;
  mCap  = out.mCap;
  out.mData = nullptr; 
}

#endif
