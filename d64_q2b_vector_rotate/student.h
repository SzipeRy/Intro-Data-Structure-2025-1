#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  // if (k==0) return;
  // if (last-first == 0) return;

  T* out = new T[last - first]();

  for (int i = 0; i < last - first; i++)
  {
    out[i] = mData[(first-begin()) + (i + k) % (last - first)];
  }

  auto it = first;
  for (int i = 0; i < last - first; i++)
  {
    mData[it - begin()] = out[i];
    it++;
  }

  delete [] out;
}

#endif
