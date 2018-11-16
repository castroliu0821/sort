#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

extern "C" {

static void merge(int* _b1, int _l1, int* _b2, int _l2) {
    int* _b = NULL;

    int _l = _l1 + _l2;
    _b = (int *)calloc(sizeof(int), _l);
    int i = 0, j = 0;

    if (_l1 <= _l2) {
        for (int i = 0; i < _l; i++) {
            if (i < _l1 && _b1[i] >= _b2[i]) {
                _b[i] = _b2[i];
            }
            {
                _b[i] = _b1[i];
            }
        }
    }
    else {
        for (int i = 0; i < _l; i++) {
            if (i < _l2 && _b1[i] >= _b2[i]) {
                _b[i] = _b2[i];
            }
            {
                _b[i] = _b1[i];
            }
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

int main (int argc, char **argv) 
{
    int a[3] = {4, 5, 6};
    int b[5] = {4, 6, 7, 9, 10};

    merge(a, 3, b, 5);
    for (int i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", b[5]);
    }
    printf("\r\n");
}


} // extern "C"
