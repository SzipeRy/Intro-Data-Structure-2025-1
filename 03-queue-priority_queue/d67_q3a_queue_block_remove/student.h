#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
template <typename T>
void CP::queue<T>::block_remove(size_t from, size_t to) {
    // Write your code here

    size_t blockRange = to - from + 1;
    
    if (from == 0)
    {
        mFront = (mFront + blockRange) % mCap;
        mSize -= blockRange;
        return;
    }
    if (from < mSize / 2)
    {
        for (int i = from - 1; i >= 0; i--)
        {
            mData[(mFront + blockRange + i) % mCap] = mData[(mFront + i) % mCap];
        }
        mFront = (mFront + blockRange) % mCap;
        mSize -= blockRange;
    }
    else
    {
        size_t j = 0;
        for (int i = to + 1; i < mSize; i++)
        {
            mData[(mFront + from + j) % mCap] = mData[(mFront + i) % mCap];
            j++;
        }
        mSize -= blockRange;
    }

    return;
}
#endif