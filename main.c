#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "bonus.h"

List citire(List lista, int *n)
{
    int i, bufferTmp;
    float bufferVal;
    scanf("%d", n);

    for (i = 0; i < *n; i++)
    {
        scanf("%d", &bufferTmp);
        scanf("%f", &bufferVal);
        lista = addLast(lista, bufferTmp, bufferVal);
    }

    return lista;
}

int main(int argc, char **argv)
{
    List lista = NULL;
    int n, i;
    lista = citire(lista, &n);

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--e1") == 0)
        {
            //task 1
            lista = task1(lista, &n);
        }
        else if (strcmp(argv[i], "--e2") == 0)
        {
            //task 2.1
            lista = task2_1(lista, &n);
        }
        else if (strcmp(argv[i], "--e3") == 0)
        {
            //task 2.2
            lista = task2_2(lista, &n);
        }
        else if (strcmp(argv[i], "--u") == 0)
        {
            //task 3
            lista = task3(lista);
        }
        else if (strcmp(argv[i], "--c") == 0)
        {
            //task 4
            lista = task4(lista, &n);
        }
        else if (strncmp(argv[i], "--st", 4) == 0)
        {
            //bonus
            lista = bonus(lista, argv[i], n);
        }
        else
        {
            printf("Argumentul %s este gresit\n", argv[i]);
        }
    }

    if (lista != NULL)
    {
        printf("%d\n", n);
        afisare(lista);
    }

    //eliberare memorie
    stergeLista(lista);

    return 0;
}