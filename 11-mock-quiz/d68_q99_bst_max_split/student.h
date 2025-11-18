#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::max_split()
{
    int left = recur(mRoot->left);
    int right = recur(mRoot->right);

    return abs(left - right);
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::recur(node *n)
{
    if (n == NULL) return 0;
    return 1 + recur(n->right) + recur(n->left);
}

#endif