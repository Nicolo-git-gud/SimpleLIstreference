#include "SimpleListr.h"
#include <iostream>

int main()
{
    SimpleList l;
    SimpleList_new(l);
    SimpleList_push_back(l, 1);
    SimpleList_push_back(l, 2);
    SimpleList_push_back(l, 3);

    SimpleList b;
    SimpleList_new(b);
    SimpleList_push_back(b, 4);
    SimpleList_push_back(b, 5);
    SimpleList_push_back(b, 6);

    SimpleList m;
    SimpleList_Merge(l, b, m);

    std::cout << "Provo la print di m " << std::endl;
    SimpleList_print(m);
    SimpleList_delete(b),
        SimpleList_delete(m);
    SimpleList_delete(l);
}