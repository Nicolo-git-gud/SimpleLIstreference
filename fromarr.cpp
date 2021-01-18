#include <iostream>
#include <assert.h>
#include "SimpleListr.h"

int main()
{

    int n = 5;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    SimpleList l;
    SimpleList_from_array(a, n, l);
    int c = SimpleList_length(l);
    assert(l.lenght == 5);
    SimpleList_print(l);
    SimpleList_delete(l);
}