#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here

  int remainder = mSize % k;
  int pos = mSize / k;
  std::vector<std::vector<T>> out(k);

  int j = mSize - 1;
  
  for (int i = 0; i < k; i++)
  {
    int size = pos;
    if (i < remainder) {size++;}
    for (int m = 0; m < size; m++)
    {
      out[i].push_back(mData[j]);
      j--;
    }
  }
  return out;

}
#endif
