#include <stdio.h>
#include "list.h"
#include "task3.h"

List task3(List lista)
{
    List santinela = lista, last = lista;

    while (lista != NULL)
    {
        //daca diferenta timestamp-urilor dintre 2 date nu e in intervalul [0.1, 1] se recalculeaza
        if ((lista->timestamp - last->timestamp) <= 1000 && (lista->timestamp - last->timestamp) >= 100)
        {
            lista->timestamp = (last->timestamp + lista->timestamp) / 2;
            lista->valoare = (last->valoare + lista->valoare) / 2;
        }
        last = lista;
        lista = lista->next;
    }

    return santinela;
}