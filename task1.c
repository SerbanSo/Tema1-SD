#include <stdio.h>
#include <math.h>
#include "list.h"

//media valorilor numerice din fereastra
float medie(List l, int k)
{
    int i;
    float suma = 0;

    for (i = 0; i < k; i++)
    {
        if (l == NULL)
        {
            return -1;
        }

        suma += l->valoare;
        l = l->next;
    }

    return suma / k;
}

//deviatia standard a valorilor din fereastra
float deviatie(List l, int k, float med)
{
    int i;
    float suma = 0;

    for (i = 0; i < k; i++)
    {
        if (l == NULL)
        {
            return -1;
        }
        suma += (l->valoare - med) * (l->valoare - med);
        l = l->next;
    }

    return sqrt(suma / k);
}

List task1(List lista, int *n)
{
    int k = 5, i, contor = 0;
    float med, dev;
    List aux = NULL, tmp = lista, santinela = lista;

    //formare lista auxiliara
    //adauga primele k/2 elemente in lista auxiliara
    for (i = 0; i < k / 2; i++)
    {
        aux = addLast(aux, tmp->timestamp, tmp->valoare);
        tmp = tmp->next;
        contor++;
    }

    //nu se poate in mod normal ca deviatia sa fie -1; iar cand media = -1 si deviatia = -1
    //deci se acopera toate cazurile
    while ((med = medie(lista, k)) != -1 && (dev = deviatie(lista, k, med)) != -1)
    {
        tmp = lista;
        i = k / 2;

        //determinarea elementului de pe pozitia din mijloc
        while (i != 0)
        {
            tmp = tmp->next;
            i--;
        }

        //daca elementul curent apartile intervalului este adaugat in lista auxiliara
        if (tmp->valoare >= (med - dev) && tmp->valoare <= (med + dev))
        {
            aux = addLast(aux, tmp->timestamp, tmp->valoare);
            contor++;
        }

        lista = lista->next;
    }

    //muta elementul curent pe pozitia din mijloc
    for (i = 0; i < k / 2; i++)
    {
        lista = lista->next;
    }

    //adauga ultime k/2 elemente in lista auxiliara
    while (lista != NULL)
    {
        aux = addLast(aux, lista->timestamp, lista->valoare);
        lista = lista->next;
        contor++;
    }

    //eliberare memorie
    stergeLista(santinela);

    *n = contor;
    return aux;
}