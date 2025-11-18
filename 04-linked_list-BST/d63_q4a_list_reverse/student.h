#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

// 10 20 *30 40 50 60* 70; a = 30, b = 70;
// result : 
// 10 20 *60 50 40 30* 70

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if (empty() || a == b)
  {
    return a;
  }

  --b;
  
  auto it(a);

  while(a != b)
  {
    std::swap(*a, *b);
    ++a;
    if (a == b) break;
    --b;
  }
  return --a;
}

#endif
