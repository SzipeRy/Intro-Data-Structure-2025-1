#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  auto arr = new T[mSize*2]();
  for (size_t i = 0; i < mSize; i++)
  {
    arr[i] = mData[i];
    arr[2*mSize - 1 - i] = mData[i];
  }
  
  delete [] mData;
  mData = arr;
  mSize *= 2;
  mCap = mSize;
}

#endif
