#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//functii uzuale pentru liste
//nothing fancy here

List initList(int timestamp, float valoare)
{
    List tmp = (List)malloc(sizeof(struct list));
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->timestamp = timestamp;
    tmp->valoare = valoare;
    return tmp;
}

List addLast(List l, int timestamp, float valoare)
{
    List ret = l;
    List tmp = initList(timestamp, valoare);

    if (l == NULL)
    {
        return tmp;
    }

    while (l->next != NULL)
    {
        l = l->next;
    }
    l->next = tmp;
    tmp->prev = l;

    return ret;
}

List addItem(List l, float x, int timestamp, float valoare)
{
    List ret = l, last = l;
    List tmp = initList(timestamp, valoare);

    while (l->valoare != x)
    {
        l = l->next;
    }
    tmp->prev = l->prev;
    l->prev->next = tmp;
    tmp->next = l;
    l->prev = tmp;

    return ret;
}

List stergeElem(List l, float valoare)
{
    List ret = l, tmp;
    while (l->valoare != valoare)
    {
        l = l->next;
    }
    tmp = l;
    if (l->next != NULL)
    {
        l->next->prev = l->prev;
    }
    if (l->prev != NULL)
    {
        l->prev->next = l->next;
    }

    return ret;
}

void stergeLista(List l)
{
    if (l == NULL)
    {
        return;
    }

    List tmp, tmp2 = l->prev;
    while (l != NULL)
    {
        tmp = l;
        l = l->next;
        free(tmp);
    }

    while (tmp2 != NULL)
    {
        tmp = tmp2;
        tmp2 = tmp2->prev;
        free(tmp);
    }
}

void afisare(List l)
{
    while (l != NULL)
    {
        printf("%d %.2f\n", l->timestamp, l->valoare);
        l = l->next;
    }
}