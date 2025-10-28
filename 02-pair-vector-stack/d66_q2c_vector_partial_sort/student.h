#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include <algorithm>
#include <vector>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B

  std::vector<T> tmpForSort;//bro reserved but mange too 
  auto tmpPos(pos);
  std::sort(tmpPos.begin(), tmpPos.end()); //erase comp if(comp = decending u cooked)
  
  for (auto x : pos)
  {
    tmpForSort.push_back(*x);
  }
  std::sort(tmpForSort.begin(), tmpForSort.end(), comp);
  
  for (int i = 0; i < pos.size(); i++)
  {
    mData[tmpPos[i]-begin()] = tmpForSort[i];// i mean tempos is iterator u can just use it or - begin()
  }
}

#endif
