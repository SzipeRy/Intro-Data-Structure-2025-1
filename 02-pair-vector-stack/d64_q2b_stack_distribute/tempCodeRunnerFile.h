#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here

  // 1 2 3 4 5 6 7 8 9 10 11 12 13
  // k = 4
  // vec[0] = 1  2  3  4
  // vec[1] = 5  6  7 
  // vec[2] = 8  9  10
  // vec[3] = 11 12 13
  // that me the result from modulo is how many vec have ... yeah that kind of thing hahaha

  int remainder = mSize % k;
  int pos = mSize / k;
  std::vector<std::vector<T>> out(k);


  int j = 0;
  
  for (int i = 0; i < k; i++)
  {
    int size = pos;
    if (i < remainder) {size++;}
    for (int m = 0; m < size; m++)
    {
      out[i].push_back(mData[j]);
      j++;
    }
  }
  return out;

}
#endif
