#ifndef STUDENTH
#define STUDENTH

#include "stack.h"
#include <vector>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::split_stack(int k) const {
  std::vector<std::vector<T>> result(k);

  // Outer loop: Iterate through every possible bucket (0 to k-1)
  // This forces us to scan the whole stack 'k' times.
  for (int bucket_idx = 0; bucket_idx < k; bucket_idx++) {

      // Inner loop: Scan the entire stack for elements belonging to this bucket
      for (size_t i = 0; i < mSize; i++) {
          // Calculate distance from top for the current element
          int dist_from_top = (mSize - 1) - i;

          // Check if this element belongs to the current bucket
          if (dist_from_top % k == bucket_idx) {
              result[bucket_idx].push_back(mData[i]);
          }
      }
  }

  return result;
}

#endif