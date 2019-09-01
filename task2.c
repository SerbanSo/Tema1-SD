#include <stdio.h>
#include "list.h"
#include "task1.h"

List sortare(List l, int k)
{
    List aux = NULL, tmp, tmp2;
    int i, j;

    //lista auxiliara
    for (i = 0; i < k; i++)
    {
        if (l == NULL)
        {
            //daca lista e prea scurta, se elibereaza memoria si se returneaza NULL
            stergeLista(aux);
            return NULL;
        }

        aux = addLast(aux, l->timestamp, l->valoare);
        l = l->next;
    }

    //bubblesort
    //ineficient dar sigur
    tmp = aux;
    for (i = 0; i < k; i++)
    {
        tmp2 = tmp->next;
        for (j = i + 1; j < k; j++)
        {
            if (tmp->valoare > tmp2->valoare)
            {
                float temp = tmp->valoare;
                tmp->valoare = tmp2->valoare;
                tmp2->valoare = temp;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }

    return aux;
}

List task2_1(List lista, int *n)
{
    List santinela = lista, tmp = NULL;
    int k = 5, i, contor = 0;
    List subLista = NULL;

    while ((tmp = sortare(lista, k)) != NULL)
    {
        contor++;
        List aux = tmp;

        for (i = 0; i < k / 2; i++)
        {
            aux = aux->next;
        }

        subLista = addLast(subLista, aux->timestamp, aux->valoare);
        lista = lista->next;

        //eliberare lista sortata, nou creata
        stergeLista(tmp);
    }

    //eliberare memorie
    stergeLista(santinela);

    *n = contor;
    return subLista;
}

List task2_2(List lista, int *n)
{
    List santinela = lista, tmp = NULL;
    int k = 5, i, contor = 0;
    List subLista = NULL;

    float med;
    //aceeasi idee ca la task1
    //se calculeaza media aritmetica folosing subprogramul implementat in task1.c
    //posibila problema cand media e chiar -1
    while ((med = medie(lista, k)) != -1)
    {
        tmp = lista;
        for (i = 0; i < k / 2; i++)
        {
            tmp = tmp->next;
        }

        subLista = addLast(subLista, tmp->timestamp, med);
        lista = lista->next;
        contor++;
    }

    //eliberare memorie
    stergeLista(santinela);

    *n = contor;
    return subLista;
}