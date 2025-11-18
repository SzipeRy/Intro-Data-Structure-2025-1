/*
 * Task: Segmented Vector (d68_q2a_segmented_vector)
 * Solution By: WeerawatW (K1EW)
 */

#ifndef __STUDENT_H_
#define __STUDENT_H_
 
#include "segmented_vector.h"
 
template <typename T>
CP::SegmentedVector<T>::~SegmentedVector()
{
    // loop เข้าไปลบข้อมูลด้านในแต่ละ block
    for (int i=0;i<mCap;i++) { 
        delete[] mData[i];
    }

    // จากนั้นให้ลบ block ทุก block ออกอีกที
    delete[] mData;
 
}
template <typename T>
void CP::SegmentedVector<T>::expand(size_t capacity)
{
    // สร้าง data ใหม่ที่มีจำนวน block = capacity
    T** new_data = new T*[capacity]();
    for (int i=0;i<capacity;i++) {
        // allocated พื้นที่ให้แต่ละ block
        new_data[i] = new T[blockSize]();
    }

    // คัดลอกข้อมูลใน mData มายัง data ใหม่
    for (int i=0;i<mSize;i++) {
        new_data[i / blockSize][i % blockSize] = mData[i / blockSize][i % blockSize];
    }

    // ลบ mData เดิมทิ้ง (ทำแบบเดียวกับ destructor)
    for (int i=0;i<mCap;i++) {
        delete[] mData[i];
    }
    delete[] mData;

    // ย้าย mData ไปชี้ที่ข้อมูลชิ้นใหม่ จากนั้นก็ปรับ mCap ให้เท่ากับค่าใหม่
    mData = new_data;
    mCap = capacity;
}
template <typename T>
void CP::SegmentedVector<T>::insert(int index, const T& element)
{
    // ใช้ ensureCapacity เพื่อให้มั่นใจว่าจำนวน block ที่มีอยู่นั้นเพียงพอต่อการใส่ข้อมูลเพิ่มมา 1 ตัว
    ensureCapacity((mSize + 1 + blockSize - 1) / blockSize);

    // ขยับข้อมูล sv[index....mSize - 1] ไปที่ sv[index + 1.....mSize]
    for (int i=mSize - 1; i >= index; i--) {
        std::swap(mData[i / blockSize][i % blockSize], mData[(i+1) / blockSize][(i+1) % blockSize]);
    }
    // ให้ข้อมูลตำแหน่งที่ index เป็น element ที่รับเข้ามา
    mData[index / blockSize][index % blockSize] = element;

    // update mSize
    mSize++;
}
template <typename T>
T& CP::SegmentedVector<T>::operator[](int index) const
{
    return mData[index / blockSize][index % blockSize];
}
#endif
