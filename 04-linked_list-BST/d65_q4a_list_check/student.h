#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stack>

template <typename T>
bool CP::list<T>::check() {
  //your code here
  size_t next_check = 0;
  size_t prev_check = 0;
  node *node_next = mHeader->next;
  node *node_prev = mHeader->prev;
  
  for (size_t i = 0 ; i < mSize; i++)
  {
    if (node_next == NULL) return false;
    ++next_check;
    if (node_next->next != NULL && node_next->next->prev != node_next) return false;
    node_next = node_next->next;
  }

  if (node_next != mHeader) return false;
  if (next_check != mSize) return false;

  for (size_t i = 0; i< mSize; i++)
  {
    if (node_prev == NULL) return false;
    ++prev_check;
    if (node_prev->prev != NULL && node_prev->prev->next != node_prev) return false;
    node_prev = node_prev->prev;
  }

  if (node_prev != mHeader) return false;
  if (prev_check != mSize) return false;

  return true;
}


#endif
