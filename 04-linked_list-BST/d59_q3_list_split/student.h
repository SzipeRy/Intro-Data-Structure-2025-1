#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  
  // change each node pointer
  if (pos == mSize)
  {
    (result.mHeader)->next = result.mHeader;
    (result.mHeader)->prev = result.mHeader;
    result.mSize = 0;
    return result;
  }

  if (pos == 0)
  {
    mHeader->next->prev = (result.mHeader);
    mHeader->prev->next = (result.mHeader);

    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    result.mSize = mSize;
    mSize = 0;
    return result; 
  }

  mHeader->prev->next = (result.mHeader);
  (result.mHeader)->prev = mHeader->prev;

  (result.mHeader)->next = it.ptr->prev->next;
  mHeader->prev = it.ptr->prev;
  it.ptr->prev->next = mHeader;
  it.ptr->prev = (result.mHeader);


  // change mSize of each link list
  result.mSize = mSize - pos;
  mSize = pos;

  return result;
}

#endif
