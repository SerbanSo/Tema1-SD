#include <stdio.h>
#include "list.h"
#include "task4.h"

//functie pentru C(timestamp, left, right)
float C(int timestamp, int ltimestamp, int rtimestamp)
{
    float tmp = (float)(timestamp - ltimestamp) / (float)(rtimestamp - ltimestamp);
    return tmp;
}

//functie pentru w(i, k)
float w(int i, int k)
{
    int j;
    float sum = 0;

    for (j = 0; j < k; j++)
    {
        sum += (j / (float)(k - 1)) * (j / (float)(k - 1)) * 0.9 + 0.1;
    }
    sum = (float)(i / (float)(k - 1) * i / (float)(k - 1) * 0.9 + 0.1) / sum;

    return sum;
}

//functie pentru f(left, right, timestamp)
float f(List left, List right, int timestamp, int k)
{
    List ltmp = left, rtmp = right;
    int i;

    //determinarea pozitie pentru calculul functiei C
    for (i = 0; i < k - 1; i++)
    {
        ltmp = ltmp->next;
        rtmp = rtmp->prev;
    }

    float c = C(timestamp, ltmp->timestamp, rtmp->timestamp);
    float lsum = 0, rsum = 0;

    //calculul lui f propriu-zis
    for (i = 0; i < k; i++)
    {
        lsum += left->valoare * w(i, k);
        rsum += right->valoare * w(i, k);
        left = left->next;
        right = right->prev;
    }

    return (1 - c) * lsum + c * rsum;
}

List task4(List lista, int *n)
{
    List santinela = lista, last = lista, left, right;
    int k = 3, i;

    while (lista != NULL)
    {
        if ((lista->timestamp - last->timestamp) > 1000)
        {
            left = lista;
            right = last;

            //determina pozitiile listelor left si right
            for (i = 0; i < k; i++)
            {
                if (left->prev == NULL || right->next == NULL)
                {
                    break;
                }
                left = left->prev;
                right = right->next;
            }

            int timestamp = last->timestamp + 200;
            float valoare;

            //adauga in lista elemente daca este cazul
            while (timestamp < lista->timestamp)
            {
                (*n)++;
                valoare = f(left, right, timestamp, k);

                lista = addItem(lista, lista->valoare, timestamp, valoare);
                timestamp += 200;
            }
        }

        last = lista;
        lista = lista->next;
    }

    return santinela;
}