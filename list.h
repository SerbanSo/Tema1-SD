#ifndef LIST
#define LIST

typedef struct list
{
    struct list *next;
    struct list *prev;

    int timestamp;
    double valoare;
} * List;

List initList(int timestamp, float valoare);

List addLast(List l, int timestamp, float valoare);

List addItem(List l, float x, int timestamp, float valoare);

List stergeElem(List l, float valoare);

void stergeLista(List l);

void afisare(List l);

#endif