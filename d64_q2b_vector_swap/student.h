#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) 
{
    //write your code here
    CP::vector<T> tmp[last-first];
    for (int i = 0; i < last - first; i++)
    {
        auto pos = (first + k + i);
        if (pos > last - first)
        {
            pos -= last;
        }
        tmp->push_back(*pos);
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        auto pos = tmp.begin() + k + i;
        if (pos > tmp.end() - tmp.begin())
        {
            pos -= tmp.end();
        }
        pos = tmp[pos];
    }
}

#endif
