#include <stdio.h>
#include "tetris.h"

int init_jeux(puit p)
{
    int i;
    int j;

    for (i = 0; i < LIGNES; i++)
    {
        for (j = 0; j < COLONNES; j++) {
            p[i][j] = 0;
        }
    }
    return 0;
}

void afficher_terrain(puit p)
{
    int i;
    int j;

    for (i = 0; i < LIGNES; i++)
    {
        for (j = 0; j < COLONNES; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}