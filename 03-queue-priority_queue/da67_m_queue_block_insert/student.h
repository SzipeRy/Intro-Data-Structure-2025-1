#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// write your code here
	ensureCapacity(mSize + m);

	if (p <= mSize / 2)
	{
		mFront = (mFront - m + mCap) % mCap;

		for (int i = 0; i < p; i++)
		{
			mData[(mFront + i) % mCap] = mData[(mFront + i + m) % mCap];
		}
	}
	else
	{
		for (int i = mSize - 1; i >= p; i--)
		{
			mData[(mFront + m + i) % mCap] = mData[(mFront + i) % mCap];
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		mData[(mFront + p + i) % mCap] = element;
	}
	mSize += m;
}

#endif
