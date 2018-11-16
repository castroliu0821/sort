#include <stdlib.h>
#include <stdio.h>

#include "heapsort.h"

extern "C" {
static void switchdata(int* arr, int len, int pos) {
    if (pos >= len) {
        return;
    }

    int l = 2 * pos + 1;
    int r = 2 * pos + 2;
    int value = arr[pos];
    if (l < len && arr[l] > arr[pos]) {
        arr[pos] = arr[l];
        arr[l] = value;
        switchdata(arr, len, l);
    }

    value = arr[pos];
    if (r < len && arr[r] > arr[pos]) {
        arr[pos] = arr[r];
        arr[r] = value;
        switchdata(arr, len, r);
    }
    return;
}

static void bigheap(int* arr, int len)
{
    int d = len / 2 - 1;
    int value;

    if (len <= 0) {
        return;
    }

    for (int i = d; i >= 0; --i) {
        switchdata(arr, len, i);
    }

    value = arr[0]; // big top data;
    arr[0] = arr[len - 1];
    arr[len - 1] = value;

    bigheap(arr, len - 1); // reconstruct big top heap
}


void heapsort(int* arr, int len)
{
    if (len <= 1) {
        return;
    }

    bigheap(arr, len);
}

} // extern "C"
