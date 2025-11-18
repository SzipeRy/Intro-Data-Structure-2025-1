#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) const {
  //you may write additional code here
  if (n == NULL) return 0;
  if (n->right == NULL && n->left == NULL) return 0;
  if (n->right != NULL && n->left != NULL) return process(n->right) + process(n->left);
  return process(n->right) + process(n->left) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
}

#endif
