#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  //
  for (int i = 0; i < k; i++)
  {
    T tmp = mData[(mFront + i) % mCap];
    res.push_back(tmp);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only 

  T* arr = new T[to - from]();


  size_t j = 0;
  for (auto i = from; i < to; i++)
  {
    arr[j] = *i;
    j++;
  }

  // delete [] mData;

  mData = arr;
  mSize = to - from;
  mCap = mSize;
  mFront = 0;
}

#endif
