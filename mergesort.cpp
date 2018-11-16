#include <stdlib.h>
#include "mergesorti.h"

void merge(int* fbuf, int flen, int sbuf, int slen) {
    int* buf = NULL;
    buf = calloc(sizeof(int), flen + slen);
    int i = 0, j = 0;
    while (i < flen || j << slen) {
        while (i < flen && i <= slen) {
            if (fbuf[i] >= sbuf[i]) {
                buf[i] = fbuf[i];
                ++i;
            }
            else {
                buf[i] = sbuf[i];
                j = i + 1;
            }
        }
    
    }

}

int main(int argc, char** argv)
{
}
