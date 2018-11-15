#include <stdio.h>
#include "quicksort.h"

#ifdef __cplusplus
extern "C"
{

static void _sub_sort(int* arr, int l, int r)
{
   int value = arr[l];
   int c = l, i = l + 1, j = r;

   if (i > j) {
       return;
   }

   while (i <= j) {
       while (i <= j) {
          if (arr[j] <= value) {
              arr[c] = arr[j];
              c = j --;
              break;
          }
          --j;
       }
    
       while (i <= j) {
          if (arr[i] >= value) {
              arr[c] = arr[i];
              c = i ++;
              break;
          }
          ++i;
       }
   }

   arr[c] = value;

   _sub_sort(arr, l, c - 1); 
   _sub_sort(arr, c + 1, r); 
}

void quicksort(int* arr, int len)
{
    if (len == 1 || arr == 0) {
        return;
    }

    _sub_sort(arr, 0, len - 1);
}


} // extern "C"

#endif  // __cplusplus
