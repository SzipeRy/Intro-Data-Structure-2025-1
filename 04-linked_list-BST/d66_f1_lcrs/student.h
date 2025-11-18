// You may include library here
#include <algorithm>

int depth(node *n)
{
  // Write Code Here
  if (n == NULL) return -1;
  return std::max(1 + depth(n->left_child), depth(n->right_sibling));
}