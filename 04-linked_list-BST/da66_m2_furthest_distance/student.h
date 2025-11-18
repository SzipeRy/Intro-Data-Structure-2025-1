#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"
#include <algorithm>

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    // if (n == NULL) return aux;
    // ++aux;
    // return std::max(my_recur(n->left, aux), my_recur(n->right, aux));
    if (n == NULL) return 0;
    return 1 + std::max(my_recur(n->left, aux), my_recur(n->right, aux));
}   

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    if (mRoot == NULL) return -1;
    if (mRoot->left == NULL && mRoot->right == NULL) return 0;
    int aux = 0;
    int right_tree = my_recur(mRoot->right, aux);
    int left_tree  = my_recur(mRoot->left, aux);
    // std::cout << left_tree << '\n' << right_tree << '\n';
	
    return right_tree + left_tree;
}

#endif
