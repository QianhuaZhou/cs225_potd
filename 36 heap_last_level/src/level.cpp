#include "MinHeap.h"
#include <cmath>
vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        int log_size = std::log2(static_cast<int>(heap.elements.size() - 1));//(excluding the 1-based indexing offset
        int start_idx = std::pow(2.0, log_size);
        std::vector<int> ret(heap.elements.begin() + start_idx, heap.elements.end());
        return ret;
}

  // Remove elements from index 2 to index 4 (excluding the element at index 4)
  //vec.erase(vec.begin() + 2, vec.begin() + 4);

