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
  std::stack<T> value;
  
  for (size_t i = 0 ; i < mSize + 1; i++)
  {
    if (node_next == NULL) return false;
    ++next_check;
    node_next = node_next->next;
    value.push(node_next->data);
  }

  if (next_check != mSize) return false;

  for (size_t i = 0; i< mSize + 1; i++)
  {
    if (node_prev == NULL) return false;
    ++prev_check;
    if (node_prev->data != value.top()) return false;
    value.pop();
    node_prev = node_prev->prev;
  }

  if (prev_check != mSize) return false;

  return true;
}


#endif
