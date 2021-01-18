#include "SimpleListr.h"
#include <iostream>


int main(){
    SimpleList l;
    SimpleList_new(l);
    SimpleList_push_back(l,5);
    SimpleList_push_back(l,6);
    SimpleList_push_back(l,7);

    SimpleList c;
    SimpleList_copy(l,c);
    std::cout << "Provo la print di c " << std::endl;
    SimpleList_print(c);
    SimpleList_delete(c),
    SimpleList_delete(l);
}