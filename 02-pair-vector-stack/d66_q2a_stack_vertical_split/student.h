#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  size_t bracket = mSize / k;
  size_t reminder = mSize % k;
  int pos = mSize;
  
  for (int i = 0 ; i < k ; i++)
  {
    int front = pos - (bracket );
    if (reminder > 0) front--;
    pos = front;
    std::stack<T> tmp;
    for (int j = 0; j < bracket; j++)
    {
      tmp.push(mData[front]);
      front++;
    }
    if (reminder > 0)
    {
      tmp.push(mData[front]);
      front++;
      reminder--;
    }
    output.push_back(tmp) ;
  }
}

#endif
