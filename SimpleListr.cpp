#include "SimpleListr.h"
#include <iostream>

void SimpleList_new(SimpleList &l)
{
    l.head = nullptr;
    l.lenght = 0;
}
int SimpleList_length2(SimpleList &l)
{
    return l.lenght;
}
int SimpleList_length(SimpleList &l)
{
    int contatore = 0;
    Cell *aux = l.head;
    while (aux != nullptr)
    {
        aux = aux->next;
        contatore++;
    }
    return contatore;
}
void SimpleList_delete(SimpleList &l)
{
    while (l.head != nullptr)
    {
        Cell *temp = l.head;
        l.head = l.head->next;
        delete temp;
    }
}
void SimpleList_print(SimpleList &l)
{
    Cell *current = l.head;
    while (current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

void reverse_print_cell(Cell *c)
{
    if (c->next == nullptr)
        return;

    c = c->next;
    reverse_print_cell(c);
    std::cout << c->value << std::endl;
}

void rec_print_cell(Cell *c)
{
    if (c->next == nullptr)
        return;

    c = c->next;
    std::cout << c->value << std::endl;
    rec_print_cell(c);
}
void SimpleList_recoursive_print(SimpleList &l)
{
    Cell *c = l.head;
    if (l.head == nullptr)
        return;
    std::cout << c->value << std::endl;
    rec_print_cell(c);
}
void SimpleList_reverse_print(SimpleList &l)
{
    Cell *c = l.head;
    if (l.head == nullptr)
        return;

    reverse_print_cell(c);
    std::cout << c->value << std::endl;
}
void SimpleList_push_back(SimpleList &l, int value)
{

    Cell *aux = new Cell;
    aux->value = value;
    if (l.head == nullptr)
    {
        aux->next = nullptr;
        l.head = aux;
        l.lenght = 1;
        return;
    }
    Cell *cur = l.head;
    Cell *prev = nullptr;
    while (cur != nullptr)
    {
        prev = cur;
        cur = cur->next;
    }
    l.lenght++;
    aux->next = cur;
    prev->next = aux;
}
void SimpleList_push_front(SimpleList &l, int v)
{
    Cell *aux = new Cell;
    aux->value = v;
    aux->next = l.head;
    l.head = aux;
    l.lenght++;
}
int SimpleList_pop_back(SimpleList &l)
{
    if (l.head == nullptr)
    {
        std::string err = "lista vuota";
        throw err;
    }

    if (l.lenght == 1)
    {
        int value = l.head->value;
        Cell *unico = l.head;
        l.head = nullptr;
        delete unico;
        l.lenght--;
        return value;
    }
    Cell *prev = l.head;
    Cell *cur = l.head;
    while (cur->next != nullptr)
    {
        prev = cur;
        cur = cur->next;
    }
    int value = cur->value;
    prev->next = nullptr;
    delete cur;
    l.lenght--;
    return value;
}
int SimpleList_pop_front(SimpleList &l)
{
    if (l.head == nullptr)
    {
        std::string err = "lista vuota";
        throw err;
    }

    Cell *cur = l.head;
    int value = cur->value;
    l.head = l.head->next;
    delete cur;
    l.lenght--;
    return value;
}

int *array_from_list(SimpleList &l)
{
    if (l.head == nullptr)
    {
        int *b = new int[0];
        return b;
    }
    int n = l.lenght;
    int *b = new int[n];
    Cell *cur = l.head;
    for (int i = 0; i < n; i++)
    {
        b[i] = cur->value;
        cur = cur->next;
    }
    return b;
}
void SimpleList_copy(SimpleList &l, SimpleList &copiato)
{
    if (l.head == nullptr)
    {
        SimpleList_new(copiato);
        return;
    }
    SimpleList_new(copiato);
    Cell *copia = l.head;
    Cell *current = new Cell;
    current->value = l.head->value;
    current->next = nullptr;
    copiato.head = current;
    copia = copia->next;
    while (copia != nullptr)
    {

        Cell *Aux = new Cell;
        Aux->value = copia->value;
        Aux->next = nullptr;
        current->next = Aux;
        current = Aux;
        copia = copia->next;
    }
    copiato.lenght = l.lenght;
    return;
}
void SimpleList_Merge(SimpleList &A, SimpleList &B,SimpleList &M){
    SimpleList_new(M);
    if(A.head==nullptr && B.head==nullptr)
        return;
    if(A.head == nullptr)
    {
        Cell *merge = B.head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        merge = merge->next;
        M.head = current;
        while(merge!=nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current-> next = aux;
            current = aux;
        }
        M.lenght = B.lenght;
        return;
        
    }
    else{
        Cell *merge = A.head;
        Cell *current = new Cell;
        current->value = merge->value;
        current->next = nullptr;
        merge = merge->next;
        M.head = current;
        while(merge != nullptr){
            Cell *aux = new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
        if(B.head == nullptr){
            M.lenght = A.lenght; 
        return;
        }
        merge = B.head;
        while(current->next!=nullptr)
        current = current->next;
        current->next = B.head;
        while(merge!=nullptr){
            Cell *aux=new Cell;
            aux->value = merge->value;
            aux->next = nullptr;
            merge = merge->next;
            current->next = aux;
            current = aux;
        }
    } 
    M.lenght = A.lenght + B.lenght;
}
void SimpleList_from_array(int a[], int c,SimpleList &l){
     SimpleList_new(l);
    if (c==0)
        return;
    Cell *Cur = new Cell;
    Cur -> value = a[0];
    Cur -> next = nullptr;
    l.head = Cur;
    for (int i=1; i < c; i++){
        Cell *aux  =  new Cell;
        aux -> value = a[i];
        aux -> next = nullptr;
        Cur -> next = aux;
        Cur = aux;
    }
    l.lenght = c;
    return;
}