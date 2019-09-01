#include <stdio.h>
#include <string.h>
#include "list.h"
#include "bonus.h"
#include "task2.h"

List bonus(List lista, char *s, int n)
{
    int d = 0, i, inf, sup, contor;

    //extragere interval
    for (i = 4; i < strlen(s); i++)
    {
        d = 10 * d + s[i] - '0';
    }

    List tmp = lista;
    float min = tmp->valoare, max = tmp->valoare;

    //determinarea minimului din interval precum si al maximului
    while (tmp != NULL)
    {
        if (tmp->valoare < min)
        {
            min = tmp->valoare;
        }
        if (tmp->valoare > max)
        {
            max = tmp->valoare;
        }
        tmp = tmp->next;
    }

    sup = (int)min - 1;
    tmp = sortare(lista, n);
    stergeLista(lista);
    lista = tmp;
    while (sup < max)
    {
        inf = sup;
        sup = sup + d;
        contor = 0;

        //parcurgere lista si determinare elemente din interval
        while (tmp != NULL)
        {
            if (tmp->valoare >= inf && tmp->valoare <= sup)
            {
                contor++;
                tmp = tmp->next;
            }
            else
            {
                break;
            }
        }
		//afisare daca exista cel putin 1 element in interval
		if (contor > 0)
		{
			printf("[%d, %d] %d\n", inf, sup, contor);
		}
    }

    //nu mai este nevoie de lista; deja s-a facut afisarea
    stergeLista(lista);
    return NULL;
}