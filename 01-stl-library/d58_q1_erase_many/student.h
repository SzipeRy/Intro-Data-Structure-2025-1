#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  T* out = new T[mSize - pos.size()]();
  
  int j = 0;
  int k = 0;
  for (int i = 0; i < mSize; i++)
  {
    if (i == pos[k] && k < pos.size())
    {
      k++;
      continue;
    }
    out[j] = mData[i];
    j++;
  }

  delete [] mData;

  mData = out;
  mSize -= pos.size();
  mCap = mSize;
}

#endif
