struct Cell {
    int value;
    Cell *next;
};

struct SimpleList {
    Cell *head;
    int lenght;
};
void SimpleList_new(SimpleList &l);
int SimpleList_length(SimpleList &l);
void SimpleList_delete(SimpleList &l);
void SimpleList_print( SimpleList &l);
void SimpleList_reverse_print(SimpleList &l);
void SimpleList_recoursive_print(SimpleList &l);
void reverse_print_cell(Cell *c);
void rec_print_cell(Cell *c);
void SimpleList_push_back(SimpleList &l, int value);
int SimpleList_pop_front(SimpleList &l);
int SimpleList_pop_back(SimpleList &l);
void SimpleList_push_front(SimpleList &l,int v);
int * array_from_list(SimpleList &l);
void SimpleList_copy(SimpleList &l, SimpleList &copiato);
void SimpleList_Merge(SimpleList &A, SimpleList &B,SimpleList &M);
void SimpleList_from_array(int a[], int c,SimpleList &l);