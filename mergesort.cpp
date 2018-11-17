#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

extern "C" {

static void merge(int* _b1, int _l1, int* _b2, int _l2) {
    int* _b = NULL;
    int _c1 = 0, _c2 = 0;
    int _l = _l1 + _l2;
    _b = (int *)calloc(sizeof(int), _l);
    for (int i = 0; i < _l; ++i) {
        if ((_c2 < _l2 && _c1 < _l1 && _b1[_c1] <= _b2[_c2]) || (_c2 == _l2)) { // up order
            _b[i] = _b1[_c1];
            ++_c1;
            continue;
        }
        
        if ((_c1 < _l1 && _c2 < _l2 && _b1[_c1] >= _b2[_c2]) || (_c1 == _l1)) {
            _b[i] = _b2[_c2];
            ++_c2;
            continue;
        }

    }


    for (int i = 0; i < _l; i++) {
        if (i < _l1) {
            _b1[i] = _b[i];
        }
        else {
            _b2[i-_l1] = _b[i];
        }
    }

    free(_b);
}

static void slice_merge(int* arr, int len) {
   if (len == 1)  {
       return;
   }

   int* _a1 = NULL;
   int* _a2 = NULL;
   int _l = len / 2;
   _a1 = arr;
   _a2 = arr + _l;

   slice_merge(_a1, _l);
   slice_merge(_a2, len-_l);
   merge(_a1, _l, _a2, len-_l);
}

void mergesort(int* arr, int len)
{
    if (len <= 1) {
        return;
    }

    slice_merge(arr, len);
}

} // extern "C"
