#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int init_jeux(puit puit1)
{
    int i;
    int j;

    for (i = 0; i < LIGNES; i++)
    {
        for (j = 0; j < COLONNES; j++) {
            puit1.matrice[i][j] = 0;
        }
    }
    return 0;
}

