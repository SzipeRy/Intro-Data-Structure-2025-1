#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  if (pos == 0)
  {
    T toBack = mData[(mFront + pos) % mCap];
  
    T* arr = new T[mSize]();
  
    size_t j = 0;
  
    for (int i = 0; i < mSize; i++)
    {
      if (i == pos) continue;
      arr[j] = mData[(mFront + i) % mCap];
      // std::cout << mData[(mFront + i) % mCap] << '\n';
      j++;
    }
    arr[j] = toBack;
  
    delete [] mData;
  
    mData = arr;
    mSize = mSize;
    mCap = mSize;
    mFront = 0;
  }
  else
  {
    T toBack = mData[(mFront + pos) % mCap];

    size_t j = pos;
    while (j < mSize - 1)
    {
      mData[(mFront + j) % mCap] = mData[(mFront + j + 1) % mCap];
      j++;
    }
    mData[(mFront + j) % mCap] = toBack;
  }
}

#endif
