#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  //write your code here
  if (this->mSize != other.mSize)
  {
    return false;
  }
  
  CP::priority_queue<T,Comp> pq1(*this);
  CP::priority_queue<T,Comp> pq2(other);

  for (size_t i = 0; i < this->mSize; i++)
  {
    if (pq1.top() != pq2.top())
    {
      return false;
    }
    pq1.pop();
    pq2.pop();
  }
  return true;
  ; // you can change this line
}

#endif
