#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  auto it = a;
  while(it != b)
  {
    if (it.ptr->data == value)
    {
      // output.push_front(it.ptr->data);
      auto tmp = output.begin();
      node *n = new node(it.ptr->data, tmp.ptr->prev, tmp.ptr);
      output.mHeader->next = n;
      tmp.ptr->prev = n;
      output.mSize++;

      // erase(it);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
    }
    ++it;
  }
}

#endif
