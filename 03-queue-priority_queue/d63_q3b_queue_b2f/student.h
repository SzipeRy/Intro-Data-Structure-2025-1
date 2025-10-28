#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// locate mFront
// locate mBack
// use std::swap
// gg ez

template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
  if (mSize == 0)
  {
    return;
  }
  std::swap(mData[(mFront + mSize - 1) % mCap], mData[(mFront + mCap -1) % mCap]);
  mFront = (mFront + mCap - 1) % mCap;
}
#endif
