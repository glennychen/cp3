// https://leetcode.com/problems/sort-array-by-parity/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// review merge sort
// review quick sort
// review insertion sort

// Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
vector<int> sortArrayByParity(vector<int>& A) {
    sort(A.begin(), A.end(), [](int a, int b){
        //a predicate to tell in what situation that Apple > Orange,
        return (a%2==0 && b%2!=0);
    });
    return A;
}

/*
/// This is a helper function for the sort routine.
template<typename _RandomAccessIterator, typename _Compare>
  void
  __insertion_sort(_RandomAccessIterator __first,
           _RandomAccessIterator __last, _Compare __comp)
  {
    if (__first == __last) return;

    for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i)
  {
    if (__comp(__i, __first))
      {
        typename iterator_traits<_RandomAccessIterator>::value_type
      __val = _GLIBCXX_MOVE(*__i);
        _GLIBCXX_MOVE_BACKWARD3(__first, __i, __i + 1);
        *__first = _GLIBCXX_MOVE(__val);
      }
    else
      std::__unguarded_linear_insert(__i,
              __gnu_cxx::__ops::__val_comp_iter(__comp));
  }
  }
  */

int main()
{
    vector<int> v{3,1,2,4, 9, 8, 7, 11, 12};
    sortArrayByParity(v);
    return 0;
}
