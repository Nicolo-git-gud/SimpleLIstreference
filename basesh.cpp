#include "SimpleListr.h"
#include <iostream>

int main(){
    SimpleList l;
    SimpleList_new(l);
    SimpleList_push_back(l,5);
    SimpleList_push_back(l,6);
    SimpleList_push_back(l,7);


    std::cout << "La lunghezza è " << SimpleList_length(l) << std::endl;
    std::cout << "Provo la print" << std::endl;
    SimpleList_print(l);
    std::cout << "Provo la reverse print" << std::endl;
    SimpleList_reverse_print(l);
    SimpleList_delete(l);
}