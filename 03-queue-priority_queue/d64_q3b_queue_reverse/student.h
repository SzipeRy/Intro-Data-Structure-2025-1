  #ifndef __STUDENT_H_
  #define __STUDENT_H_

  #include <cassert>
  #include <algorithm>

  template <typename T>
  void CP::queue<T>::reverse(int a,int b) {
    //your code here
    int front = a;
    int back  = b;
    int count = (b - a + 1) / 2;

    while(count > 0)
    {
      std::swap(mData[(mFront + front) % mCap], mData[(mFront + back) % mCap]);
      front++;
      back--;
      count--;
    }

  }

  #endif
